#include "smartpanipipe.h"

void MonitorBattery(){
    TRISCbits.RC1=0;
    TRISCbits.RC2=0;
    SOLAR_POWER=0;  //for testing only
    getBatteryLevel();
    if(BatteryLevel <= BATTERY_THRESHOLD) {  //if Battery not charged
        getSolarLevel();
        if((SolarLevel-SOLAR_OFFSET) > BatteryLevel)   {  //If solar level > Battery level
            ChargeBattery();
        }
    }
  }

void getBatteryLevel () {             //ADC conversion to check battery level
    PORTCbits.RC2=1; //for testing only
    /*read ADC value for Battery*/
    OpenADC(ADC_FOSC_16&ADC_RIGHT_JUST&ADC_0_TAD, ADC_CH1&ADC_INT_OFF&ADC_REF_VDD_VSS, 0b00000000);

    ConvertADC();                               // start conversion
    while(BusyADC());                           //wait while conversion takes place
    BatteryLevel = ReadADC();
    delay_1s(1);  //for testing only
    PORTCbits.RC2=0; //for testing only
}

void getSolarLevel(){               //ADC conversion to check solar panel level
    PORTCbits.RC1=1; //for testing only
    /*read ADC value for SolarPanel*/
    OpenADC(ADC_FOSC_16&ADC_RIGHT_JUST&ADC_0_TAD, ADC_CH2&ADC_INT_OFF&ADC_REF_VDD_VSS, 0b00000000);
    ConvertADC();                               // start conversion
    while(BusyADC());                           //wait while conversion takes place
    SolarLevel = ReadADC();

    delay_1s(1); //for tesing only
    PORTCbits.RC1=0; //for tesing only
}

void ChargeBattery(){
    int count1=0;
    while((SolarLevel-SOLAR_OFFSET) > BatteryLevel){
        SOLAR_POWER=1;              //Turn on Charge circuit.
        delay_1s(2);                //wait for 10mins
        getSolarLevel();
        if (count1>12){             //if battery is being charged for more than 2hours
            SOLAR_POWER=0;
            return;
        }
        count1++;
    }
    SOLAR_POWER=0;
    PORTCbits.RC1=0; //for tesing only
    PORTCbits.RC2=0; //for tesing only
}

unsigned char BatteryCharged(){
    getBatteryLevel();
    if (BatteryLevel > 860){ //if battery level >5V
        return 1;
    }
    else{
        return 0;
    }
}

unsigned char SolarStatus(){
    getSolarLevel();
    if (SolarLevel == 0){ //if there is no signal
        return 2;
    }
    else if (SolarLevel < 500){ //if its evening - 3V
        return 0;
    }
    else{  //if its morning
        return 1;
    }
}