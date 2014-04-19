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

}

void gatherData(){
    //read temperature and humidity readings for the past three days
    for (char j=0; j<=23; j++){ //read first 17-bytes
        SMS_data[j+1]=ReadMemory(j);
    }
    SMS_data[25]=STOP_BIT;
    if (days==4){
        for (char j=24; j<=31; j++){ //read memory address 23 to 30 (reserved for day four data)
            SMS_data[j+1]=ReadMemory(j);
        }
        SMS_data[33]=STOP_BIT;
    }
}