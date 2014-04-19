
#include    "smartpanipipe.h"

void usartTRANSMIT(char *msg){
        putrs2USART(msg);
        putc2USART(0x0A);
}

void relayMSG(){
     if(DataRdy1USART())
           putc2USART(Read1USART());
     if(DataRdy2USART())
            putc1USART(Read2USART());
}


void transmitWaterLevel(){
        //to be defined
}

void transmitData(){
        //to be defined
}