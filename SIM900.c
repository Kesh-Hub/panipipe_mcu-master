#include    "smartpanipipe.h"


void initUSART1(){
    Open1USART(USART_TX_INT_OFF & USART_RX_INT_OFF & USART_ASYNCH_MODE & USART_EIGHT_BIT & USART_CONT_RX & USART_BRGH_LOW, 25);
    ANSELC = 0x00;
}


/* Send a message to server */
void sendData(){
    /****temp fix****/
    Close1USART();
    delay_1s(1);
    initUSART1();
    delay_1s(10);
    puts1USART("AT\r\n");
    delay_1s(1);
    puts1USART("AT+CMGF=1\r\n");
    delay_1s(1);
    puts1USART("AT+CSCS=\"GSM\"\r\n");
    delay_1s(1);;
    puts1USART("AT+CMGS=\"+447937946751\"\r\n");        //Server:+447937946751
    delay_1s(1);
    putrs1USART(SMS_data);
    Write1USART(26); //send character 26 i.e ctrl-z
    delay_1s(1);
    // wait for message to be sent
    Close1USART();
    delay_1s(1);
    initUSART1();
}

/* Delete all messages in SIM memory*/
void initSIM900(){
    delay_1s(1);
    putrs1USART("AT+CBAND=\"PGSM_MODE\"\r\n"); //set preferred band to GSM900
    delay_1s(1);
    putrs1USART("AT+CNMI=2,2,0,0\r\n"); //set module to discard messages after retreival
    delay_1s(1);
}

unsigned char uartReceive(unsigned char data[]){
    unsigned char size=sizeof(data)+2;
    gets1USART((char*)RXdata,size); //receive upto 2 bytes
    if (strstr(RXdata,data)!=NULL){ //check for OK response
        return 1;
    }
    else{
        // re-initialise to discard received data then return 0
        Close1USART();
        delay_1s(1);
        initUSART1();
        return 0;
    }
}

unsigned char serverReceive(unsigned char data[]){
    unsigned char size = sizeof(data)+52; //first 52 characters contains time and recipient number
    gets1USART((char*)RXdata,size); //receive upto two characters in text message
    if (strstr(RXdata, "£")){
        if (strstr(RXdata,"+447937946751")!=NULL){ //Server: +447937946751
            //perform server commands
            if ((strstr(RXdata,data)!=NULL)){
                return 1;
            }
            else{
                return 0;
            }
        }
    }
    else{
        return 0;
    }
}

unsigned char configReceive(){
    unsigned char size = 51+3;
    gets1USART((char*)RXdata,size); //receive upto three characters in text message
    if (strstr(RXdata,"+447937946751")!=NULL){ //Server: +447937946751
        //perform server commands
        if ((strstr(RXdata,"§")!=NULL)){ //check for config prefix
            // change config settings
            WATER_THRESHOLD = RXdata[51] - OFFSET;
            TRANSMIT_FREQ = RXdata[52] - OFFSET;
            CONFIG_FREQ = RXdata[53] - OFFSET;
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        return 0;
    }
}

void SIM900_SWITCH(){
    SIM900_TRIGGER = 0;
    delay_1s(2);
    SIM900_TRIGGER = 1;
}

void GSM_ON(){
    SIM900_POWER = 1;
    delay_1s(2);
    SIM900_SWITCH();
}

void GSM_OFF(){
    SIM900_SWITCH();
    delay_1s(2);
    SIM900_POWER = 0;
}

void sendConReq(){
    puts1USART("AT+CMGF=1\r\n");
    delay_1s(1);
    puts1USART("AT+CSCS=\"GSM\"\r\n");
    delay_1s(1);;
    puts1USART("AT+CMGS=\"+447937946751\"\r\n");        //Server:+447937946751
    delay_1s(1);
    putc1USART(CONFIG_PREFIX);
    Write1USART(26); //send character 26 i.e ctrl-z
    delay_1s(1);

    // wait for message to be sent
    Close1USART();
    delay_1s(1);
    initUSART1();
}

void SIM900_SEND(char type){
        SIM900_START:

        /* initialise SIM900 and set echo OFF */
        puts1USART("ATE0\r\n");
        delay_1s(1);
//        if (!uartReceive("OK")){
//            goto SIM900_START;
//        }
        initSIM900();

        SEND:
        /* send text message*/
        if (type==1){                                           //check if sending data message
            sendData();                                         //send data message
        }
        else{                                                   //else send reconfiguration request message
            sendConReq();                                       //send config request message
        }
        gets1USART((char*)RXdata,20);                           //get OK response from SIM900

        /* wait for response from server */
        if (type==1){
            if (serverReceive("OK")){                           //if acknolegment received
                GSM_OFF();                                      //turn off sim900
            }
            else{
                goto SEND;
            }
        }
        else{
            if (configReceive()){                               //if acknolegment received

                GSM_OFF();                                      //turn off sim900
            }
            else{
                goto SEND;
            }
        }
}