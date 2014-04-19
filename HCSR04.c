#include    "smartpanipipe.h"

void HCSR_Config(){
    HCSR04_POWER_CONFIG = 0;
    HCSR04_TRIGGER_CONFIG = 0;
    HCSR04_ECHO_CONFIG = 1;
}

void HCSR_Start(){
    HCSR04_TRIGGER = 0;
    delay_10us(1);
    HCSR04_TRIGGER = 1;
    delay_10us(1);
    HCSR04_TRIGGER = 0;
    delay_10us(1);
}

int HCSR_Time(){
    int Res_Time;
    startTimePIN();

    while(HCSR04_ECHO == 0 && TimeOUT == 0);
    Res_Time= readTimePIN();
    if (TimeOUT)
            return 0;
    else
    {
        startTimePIN();
        while(HCSR04_ECHO == 1 && TimeOUT == 0);
        Res_Time = readTimePIN();
        if (TimeOUT)
            return 0;
        else
            return Res_Time;
    }
}

int HCSR_Distance(int time){
    int distance;
    distance = time * 0.034f; //in cm //need to change accordingly (340/2)/10000 in CM *0.8
    return distance;
}

char HCSR_Reading(){
    HCSR_Start();
    DIS_INT = HCSR_Distance(HCSR_Time());
    if (DIS_INT == 0)
        return 1;
    else
        return 0;

}

void getWaterLevel(){
    unsigned char WLevel[3];
    unsigned int sum=0;
    for (char i=0; i<3; i++){
        HCSR04_POWER = 1;
        delay_1s(1);
        ErrorMSG = HCSR_Reading();
        delay_100ms(5);
        HCSR04_POWER = 0;
        WLevel[i]=DIS_INT;
        delay_1s(3);
    }
    for (char j=0; j<3; j++){
        sum+=WLevel[j];
    }
    WaterLevel = sum/3;
//    if(!ErrorMSG)
//        show_HCSR();
//    else
//        show_HCSRError(ErrorMSG);

}
