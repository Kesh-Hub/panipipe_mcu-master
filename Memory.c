#include    "smartpanipipe.h"
char ReadMemory(char addr){
    while(WR)
        continue;
    return EEPROM_READ(addr);
}
void WriteMemory(char addr, char data){
    EEPROM_WRITE(addr,data);
}

void ShiftData(){
    avgTEMP = (char)avgTEMP+OFFSET;
    avgHUM = (char)avgHUM+OFFSET;
    minTEMP = (char)minTEMP+OFFSET;
    maxTEMP = (char)maxTEMP+OFFSET;
    minHUM = (char)minHUM+OFFSET;
    maxHUM = (char)maxHUM+OFFSET;
    WaterLevel = (char)WaterLevel+OFFSET;
    Conductivity = (char)WaterLevel+OFFSET;
}

void SaveData(){
    /*** Save sensor data Data ***/
    if (days==1){
        WriteMemory(0,(char)avgTEMP);
        WriteMemory(1,(char)avgHUM);
        WriteMemory(2,(char)minTEMP);
        WriteMemory(3,(char)maxTEMP);
        WriteMemory(4,(char)minHUM);
        WriteMemory(5,(char)maxHUM);
        WriteMemory(6,(char)WaterLevel);
        WriteMemory(7,(char)Conductivity);
    }
    else if (days==2){
        WriteMemory(8,(char)avgTEMP);
        WriteMemory(9,(char)avgHUM);
        WriteMemory(10,(char)minTEMP);
        WriteMemory(11,(char)maxTEMP);
        WriteMemory(12,(char)minHUM);
        WriteMemory(13,(char)maxHUM);
        WriteMemory(14,(char)WaterLevel);
        WriteMemory(15,(char)Conductivity);
    }
    else if (days==3){
        WriteMemory(16,(char)avgTEMP);
        WriteMemory(17,(char)avgHUM);
        WriteMemory(18,(char)minTEMP);
        WriteMemory(19,(char)maxTEMP);
        WriteMemory(20,(char)minHUM);
        WriteMemory(21,(char)maxHUM);
        WriteMemory(22,(char)WaterLevel);
        WriteMemory(23,(char)Conductivity);
    }
    else if (days==4){
        WriteMemory(24,(char)avgTEMP);
        WriteMemory(25,(char)avgHUM);
        WriteMemory(26,(char)minTEMP);
        WriteMemory(27,(char)maxTEMP);
        WriteMemory(28,(char)minHUM);
        WriteMemory(29,(char)maxHUM);
        WriteMemory(30,(char)WaterLevel);
        WriteMemory(31,(char)Conductivity);
    }
    else if (days==5){
        WriteMemory(32,(char)avgTEMP);
        WriteMemory(33,(char)avgHUM);
        WriteMemory(34,(char)minTEMP);
        WriteMemory(35,(char)maxTEMP);
        WriteMemory(36,(char)minHUM);
        WriteMemory(37,(char)maxHUM);
        WriteMemory(38,(char)WaterLevel);
        WriteMemory(39,(char)Conductivity);
    }

}

void gatherData(){
    //read temperature and humidity readings for the past three days
    for (char j=0; j<=23; j++){ //read first 17-bytes
        SMS_data[j+1]=ReadMemory(j);
    }
    if (days==4){
        for (char j=24; j<=31; j++){ //read memory address 23 to 30 (reserved for day four data)
            SMS_data[j+1]=ReadMemory(j);
        }
    }
    if (days==5){
        for (char j=24; j<=39; j++){ //read memory address 23 to 39 (day 4 and day 5 data)
            SMS_data[j+1]=ReadMemory(j);
        }
    }
}

void SaveConfig(){
    WriteMemory(50,(char)WATER_THRESHOLD);
    WriteMemory(51,(char)TRANSMIT_FREQ);
    WriteMemory(52,(char)CONFIG_FREQ);
}

void ReadConfig(){
    WATER_THRESHOLD=ReadMemory(50);
    TRANSMIT_FREQ=ReadMemory(51);
    CONFIG_FREQ=ReadMemory(52);
}