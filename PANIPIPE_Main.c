/*============================PROJECT TITLE=====================================
	Project: Smart Panipipe
	Version: 1.2				Date: April 9, 2014
	Target: -				Processor: PIC18F25k22
==============================================================================*/

#include    "smartpanipipe.h"


/*===========================CONFIGURATION BITS=================================
            CONFIGURATION BITS FOR PIC18F25k22
==============================================================================*/

#pragma config   FOSC=INTIO67
#pragma config   PLLCFG=OFF
#pragma config   PRICLKEN=OFF
#pragma config   FCMEN=OFF
#pragma config   IESO=OFF
#pragma config   PWRTEN=ON
#pragma config   BOREN=SBORDIS
#pragma config   BORV=285
#pragma config   WDTEN=SWON
#pragma config   WDTPS=1024
#pragma config   CCP2MX=PORTC1
#pragma config   PBADEN=OFF
#pragma config   CCP3MX=PORTC6
#pragma config   HFOFST=OFF
#pragma config    T3CMX=PORTB5
#pragma config    P2BMX=PORTC0
#pragma config    MCLRE=EXTMCLR
#pragma config    STVREN=ON
#pragma config    LVP=OFF
#pragma config    XINST=OFF
#pragma config    DEBUG=OFF
#pragma config    CP0=OFF
#pragma config    CP1=OFF
#pragma config    CP2=OFF
#pragma config    CP3=OFF
#pragma config    CPB=OFF
#pragma config    CPD=OFF
#pragma config    WRT0=OFF
#pragma config    WRT1=OFF
#pragma config    WRT2=OFF
#pragma config    WRT3=OFF
#pragma config    WRTB=OFF
#pragma config    WRTC=OFF
#pragma config    WRTD=OFF
#pragma config    EBTR0=OFF
#pragma config    EBTR1=OFF
#pragma config    EBTR2=OFF
#pragma config    EBTR3=OFF
#pragma config    EBTRB=OFF

/*========================PORT BITS INITIALISATION==============================
                              GLOBAL INTERRUPT
                               I/O PIN CONFIG
                                 LCD SET UP
==============================================================================*/
void initPorts(void)
{
    INTERRUPT_Config();
    OSCCON = 0b01110010;                   // internal oscillator, 16MHz
    OSCTUNEbits.TUN=011111;

    DHT_Config();
    HCSR_Config();
    SOLAR_POWER_CONFIG = 1;
    SOLAR_SIGNAL_CONFIG = 0;

    COND_SIGNAL_CONFIG = 1;

    BATT_SIGNAL_CONFIG = 0;
    //Setting USART PORT
    SIM900_POWER_CONFIG = 0;
    SIM900_TRIGGER_CONFIG = 0;
    SIM900_TRIGGER = 1;

    SIM900_TX = 1;
    SIM900_RX = 1;
    //  Configure UART
    Open1USART(USART_TX_INT_OFF & USART_RX_INT_OFF & USART_ASYNCH_MODE & USART_EIGHT_BIT & USART_CONT_RX & USART_BRGH_LOW, 25);
    ANSELC = 0x00;
    
    //Setting PC USART COM
    PIC_TX2_CONFIG = 1;
    PIC_RX2_CONFIG = 1;
    //  Configure UART
    Open2USART(USART_TX_INT_OFF & USART_RX_INT_OFF & USART_ASYNCH_MODE &USART_EIGHT_BIT & USART_CONT_RX & USART_BRGH_HIGH, 25);
    ANSELB = 0x00;

    show_Welcome();
    delay_100ms(5);
}


/*=========================== MAIN APPLICATION =================================

==============================================================================*/
void main() {
    initPorts();
    while(1){
        if (count==0){
            getConductivity();
            //count++;
        }
    }
}

void test(){
    tempcounter=2;
    char c=0;
    for (char d=0; d<3; d++){
        days++;                                         //increment days
        for (int i=0; i<tempcounter; i++){
            getTempHum();                               //get temperature and humidity sensor
            while ((TEMP_INT==0)&&(c<=3)){              //check DHT11 sensor 3 times for reading if no data received
                getTempHum();                           
                c++;
            }
            DayTEMP[i]=TEMP_INT;
            DayHUM[i]=RH_INT;
        }
        avgTempHum();                                   //calculate average temperature and humidity
        minmaxTempHum();                                //calculate minimum and maximum temperature and humidity
        getWaterLevel();                                //get water level from conductivity sensor
        getConductivity();
        ShiftData();                                    //shift gathered data by offset
        if ((WaterLevel-OFFSET) >= WATER_THRESHOLD){    //check if water level is too low
            SMS_data[0]=WARNING_BIT;                    //initiate message with warning char
            SMS_data[1]=WaterLevel;                     //put water level in text message
            SMS_data[2]=STOP_BIT;                       //end message with stop bit

            GSM_ON();                                   //turn on sim900
            delay_1s(10);                               //wait for GSM to connect to network
            SIM900_SEND();                              //Send message to server
            GSM_OFF();                                  //turn off sim900
        }
        SaveData();                                     //Sava sensor readings to memory
    }
    SMS_data[0]=START_BIT;                              //start message with start bit
    gatherData();                                       //read data from memory
    getCheckBytes();

    GSM_ON();                                           //turn on sim900
    delay_1s(10);                                       //wait for GSM to connect to network
    SIM900_SEND();                                      //Send message to server
    GSM_OFF();                                          //turn off sim900
}

void routine(){
        START:

        if(SOLAR_SIGNAL == 1){                                      //if solar-panel is on
            solarcounter = 0;

            while (BATT_SIGNAL == 1){                               //while there is power on sensor pins

                while (TEMP_INT==0){
                    getTempHum();
                }
                DayTEMP[tempcounter]=TEMP_INT;
                DayHUM[tempcounter]=RH_INT;
                tempcounter++;
                delay_1ms(1);
                sleep();                                            //sleep for 2h

                if (tempcounter==2){
                        getConductivity();
                        days++;
                    if (days>=3)
                        getImage();

                    avgTempHum();                                   //calculare average temperature and humidity
                    minmaxTempHum();                                //calculate minimum and maximum temperature and humidity
                    getWaterLevel();                                //get water level from conductivity sensor

                    ShiftData();                                    //shift gathered data by offset
                    if ((WaterLevel-OFFSET) >= WATER_THRESHOLD){    //check if water level is too low
                        SMS_data[0]=WARNING_BIT;                    //initiate message with warning char
                        SMS_data[1]=WaterLevel;                     //put water level in text message
                        SMS_data[2]=STOP_BIT;                       //end message with stop bit

                        GSM_ON();                                   //turn on sim900
                        delay_1s(10);                               //wait for GSM to connect to network
                        SIM900_SEND();                              //Send message to server
                        GSM_OFF();                                  //turn off sim900
                    }
                }
            }

            if (SOLAR_SIGNAL == 0)                                  //if solar-panel is off
                goto OFF;
            BATT_SIGNAL = 1;
            goto START;

        }
        else {                                                      //when solar-panel is off
            OFF:
            SaveData();                                             //Sava sensor readings to memory
            tempcounter=0;

            //check if number of days since last transmisssion is 3
            if (days >=3){
                transmitData();
                days=0;
            } //reset days counter only after successful tranmsission

            while (SOLAR_SIGNAL == 0) //if solar-panel is off
                delay_1s(5);

            solarcounter++;
            if (solarcounter > SOLAR_THRESHOLD){
                    usartTRANSMIT("Solar Threshold");
                    delay_1s(5);
                    solarcounter=0;
                    goto START;
            }
        }

}