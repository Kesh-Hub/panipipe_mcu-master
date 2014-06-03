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
    Conductivity = (char)Conductivity+OFFSET;
    BatteryValue = (char)BatteryValue+OFFSET;
    SolarValue = (char)SolarValue+OFFSET;
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
        WriteMemory(8,(char)BatteryValue);
        WriteMemory(9,(char)SolarValue);
    }
    else if (days==2){
        WriteMemory(10,(char)avgTEMP);
        WriteMemory(11,(char)avgHUM);
        WriteMemory(12,(char)minTEMP);
        WriteMemory(13,(char)maxTEMP);
        WriteMemory(14,(char)minHUM);
        WriteMemory(15,(char)maxHUM);
        WriteMemory(16,(char)WaterLevel);
        WriteMemory(17,(char)Conductivity);
        WriteMemory(18,(char)BatteryValue);
        WriteMemory(19,(char)SolarValue);
    }
    else if (days==3){
        WriteMemory(20,(char)avgTEMP);
        WriteMemory(21,(char)avgHUM);
        WriteMemory(22,(char)minTEMP);
        WriteMemory(23,(char)maxTEMP);
        WriteMemory(24,(char)minHUM);
        WriteMemory(25,(char)maxHUM);
        WriteMemory(26,(char)WaterLevel);
        WriteMemory(27,(char)Conductivity);
        WriteMemory(28,(char)BatteryValue);
        WriteMemory(29,(char)SolarValue);
    }
    else if (days==4){
        WriteMemory(30,(char)avgTEMP);
        WriteMemory(31,(char)avgHUM);
        WriteMemory(32,(char)minTEMP);
        WriteMemory(33,(char)maxTEMP);
        WriteMemory(34,(char)minHUM);
        WriteMemory(35,(char)maxHUM);
        WriteMemory(36,(char)WaterLevel);
        WriteMemory(37,(char)Conductivity);
        WriteMemory(38,(char)BatteryValue);
        WriteMemory(39,(char)SolarValue);
    }
    else if (days==5){
        WriteMemory(40,(char)avgTEMP);
        WriteMemory(41,(char)avgHUM);
        WriteMemory(42,(char)minTEMP);
        WriteMemory(43,(char)maxTEMP);
        WriteMemory(44,(char)minHUM);
        WriteMemory(45,(char)maxHUM);
        WriteMemory(46,(char)WaterLevel);
        WriteMemory(47,(char)Conductivity);
        WriteMemory(48,(char)BatteryValue);
        WriteMemory(49,(char)SolarValue);
    }

}

void gatherData(){
    //read temperature and humidity readings for the past three days
    for (char j=0; j<=29; j++){ //read first 17-bytes
        SMS_data[j+1]=ReadMemory(j);
    }
    if (days==4){
        for (char j=30; j<=39; j++){ //read memory address 23 to 30 (reserved for day four data)
            SMS_data[j+1]=ReadMemory(j);
        }
    }
    if (days==5){
        for (char j=40; j<=49; j++){ //read memory address 23 to 39 (day 4 and day 5 data)
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

void SetInitFlag(){
    WriteMemory(53,1);
}

unsigned char ReadInitFlag(){
    int val = ReadMemory(53);
    if (val==1){
        return 1;
    }
    else{
        return 0;
    }
}