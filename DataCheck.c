#include    "smartpanipipe.h"
unsigned int rem;

void  insertCheckByte(){                //insert check byte in text message
    if (days==3){
        SMS_data[25]=CheckByte;
        SMS_data[26]=DATA_SUFFIX;
    }
    else if (days==4){
        SMS_data[33]=CheckByte;
        SMS_data[34]=DATA_SUFFIX;
    }
    else if (days==5){
        SMS_data[41]=CheckByte;
        SMS_data[42]=DATA_SUFFIX;
    }
}

void getCheckByte(){
    unsigned int sum=0;
    for (int z=0; z<=23; z++){                        //read until end of memory
        char temp = ReadMemory(z)-OFFSET;
        sum+=temp;
    }
    if (days==4){
        for (char z=24; z<=31; z++){
            char temp = ReadMemory(z)-OFFSET;
            sum+=temp;
        }
    }
    if (days==5){
        for (char z=32; z<=39; z++){
            char temp = ReadMemory(z)-OFFSET;
            sum+=temp;
        }
    }
    rem=sum%95;                         //ensure checkbyte falls into range of supported characters
    CheckByte= rem+OFFSET;                          
    insertCheckByte();
}