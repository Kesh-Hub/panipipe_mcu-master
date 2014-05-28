/*==================DHT11 TEMPERATURE AND HUMIDITY SENSOR=======================
            Overview of The Sensor - 3 Phases for Sensor Readings
 * 1. StartSignal() - Used to initiate DHT11 to take new reading
 * (i.e. to set low for at least 18us followed by high for 20-40us)
 * 2. CheckResponse() - Used to check if DHT11 have responsed and reading to send signal
 * 3. ReadByte() - To read 8 bits of data send from DHT11
 * (i.e. if high for 25-30us, BIT 0, if 70us it is  BIT1)
 *
 * For this application
 * 4. DHT11Read() - Function used to initiate the sensor and capturing 5 bytes as well as error
 * - Returning Array in order as : RH_Integer, RH_Decimal, Temp_Integer, Temp_Decimal
 *
 * For PIC18F4520
 * Function is written to utilise Timer0 - Assuming that Timer 2 value incremented every 1us
 *
 * Note that Temp Op-Range are between 0-50 C whereas Humidty are between 20-95 %
 * Function 4 can be extended to check it is is within the range.
==============================================================================*/
#include    "smartpanipipe.h"

void DHT_Config(){
    DHT11_POWER_CONFIG = 0;
}

void DHT_Start(){
    DHT11_SIGNAL_CONFIG = 0; // PORT RA1 as OUTPUT from MCU
    DHT11_SIGNAL = 1;
    delay_10us(5);
    DHT11_SIGNAL = 0;
    delay_1ms(30);
    DHT11_SIGNAL = 1;
    delay_10us(3);
    DHT11_SIGNAL = 0;
    delay_1us(1);
    DHT11_SIGNAL_CONFIG = 1;  // PORT RA1 as INPUT to MCU
}

unsigned char DHT_CheckResponse(){
    int Res_Time = 0;
    DHT11_SIGNAL_CONFIG = 1;
    startTimePIN();
    while(DHT11_SIGNAL == 0 && TimeOUT == 0);
    Res_Time= readTimePIN();
    if (TimeOUT){
            return 1;
        }
        else
        {
            startTimePIN();
            while(DHT11_SIGNAL == 1 && TimeOUT == 0);
            Res_Time= readTimePIN();
                if (TimeOUT)
                    return 2;
                else
                    return 0;
        }
}
unsigned char DHT_ReadByte(){
    DHT11_SIGNAL_CONFIG = 1;
    unsigned char bytes, i;
    int Res_Time;
        for ( i=0 ; i < 8 ; i++ )
        {
            bytes = bytes << 1;
            startTimePIN();
            while(DHT11_SIGNAL==0);// && TimeOUT == 0);

            startTimePIN();
            while(DHT11_SIGNAL==1);// && TimeOUT ==0);
            Res_Time= readTimePIN();

            if(Res_Time>(15)){
                bytes = bytes | 0b0000001;
            }
        }
        return bytes;
}

unsigned char DHT_Reading(){
    unsigned char msg, CheckSUM = 0, TotalSUM = 0;

    DHT_Start();
    msg = DHT_CheckResponse();

    if (msg != 0){
        return msg; //timeout error
    }
    else
    {
        RH_INT = DHT_ReadByte();
        RH_DEC = DHT_ReadByte();
        TEMP_INT = DHT_ReadByte();
        TEMP_DEC = DHT_ReadByte();
        CheckSUM = DHT_ReadByte();
        TotalSUM = RH_INT + RH_DEC + TEMP_INT + TEMP_DEC;
        if (CheckSUM != TotalSUM)
            return 3; //checksum error
        else
            return 0;
    }
}

//void getTempHum(){
//    DHT11_POWER = 1;
//    delay_1s(1);
//    ErrorMSG = DHT_Reading();
//    delay_100ms(5);
//    DHT11_POWER = 0;
////    if(!ErrorMSG)
////        show_DHT();
////    else
////        show_DHTError(ErrorMSG);;
//}

void getTempHum(){
    DayTEMP[0]=24;
    DayTEMP[1]=24;
    DayTEMP[2]=23;
    DayHUM[0]=43;
    DayHUM[1]=44;
    DayHUM[2]=43;
}

void avgTempHum(){
    unsigned int sum1=0;
    unsigned int sum2=0;
    for (char i=0; i<tempcounter; i++){
        sum1+=DayTEMP[i];
        sum2+=DayHUM[i];
    }
    avgTEMP = sum1/tempcounter;
    avgHUM = sum2/tempcounter;
}

void minmaxTempHum(){
    unsigned char min1 = DayTEMP[0];
    unsigned char max1 = DayTEMP[0];
    unsigned char min2 = DayHUM[0];
    unsigned char max2 = DayHUM[0];

    for (char i=0; i<tempcounter; i++){
        if (DayTEMP[i]<=min1){
            min1 = DayTEMP[i];
        }
        if (DayHUM[i]<=min2){
            min2 = DayHUM[i];
        }
        if (DayTEMP[i]>=max1){
            max1 = DayTEMP[i];
        }
        if (DayHUM[i]>=max2){
            max2 = DayHUM[i];
        }
    }
    minTEMP = min1;
    maxTEMP = max1;
    minHUM = min2;
    maxHUM = max2;
}