/*======================== GENERIC FUNCTION LIBRARY  ===========================
==============================================================================*/
#include    <xc.h>			// XC general include file

#include    "smartpanipipe.h"


// Timer0 Specific Function
void startTimePIN(){
    TimeOUT = 0;
    WriteTimer0(0);

}
int readTimePIN(){
    int x = TMR0;
    WriteTimer0(0); 
    return x;
}





// Delay Function
void delay_1us(char x){
    while(x-- !=0){
        __delay_us(1);
    }
}

void delay_10us(char x){
    while(x-- !=0){
        __delay_us(10);
    }
}
void delay_100us(char x){
    while(x-- !=0){
        __delay_us(100);
    }
}

void delay_1ms(char x){
    while(x-- !=0){
        __delay_ms(1);
    }
}

void delay_10ms(char x){
    while(x-- !=0){
        __delay_ms(10);
    }
}
void delay_100ms(char x){
    while(x-- !=0){
        delay_10ms(10);
    }
}
void delay_1s(char x){
    while(x-- !=0){
        delay_10ms(100);
    }
}

// Decimal to Char Converter
char makedigit (int *number, int base){
  char map[] = "0123456789";
  int ix;
  for (ix=0; *number >= base; ix++) { *number -= base; }
  return map[ix];
}


char *makefourstring (int number, int deci){
  char tmp[7];
    tmp[0] = makedigit(&number, 10);
    tmp[1] = makedigit(&number, 1);
    tmp[2] = '.';
    tmp[3] = makedigit(&deci, 10);
    tmp[4] = makedigit(&deci, 1);
    tmp[6] = '\0';
  return tmp;
}

char *makedoublestring (int number){
  char tmp[4];
    tmp[0] = makedigit(&number, 10);
    tmp[1] = makedigit(&number, 1);
    tmp[3] = '\0';
  return tmp;
}

char *makethreestring (int number){
  char tmp[5];
    tmp[0] = makedigit(&number, 100);
    tmp[1] = makedigit(&number, 10);
    tmp[2] = makedigit(&number, 1);
    tmp[4] = '\0';
  return tmp;
}

/// Sleeping
void sleep(){
//   MonitorBattery();                        //check battery level and charge if required
//   for (int t=0; t<120;t++){                //sleep for 2hours
//       delay_1s(60);
//   }
    for (char t=0; t<3; t++){  //wait for 3minutes
        delay_1s(60);
    }
}

/// Predefined MSG
void show_DHT(){
    char *RH = makefourstring(RH_INT, 0);
    usartTRANSMIT("RH : ");
    usartTRANSMIT(RH);
    char *TEMP = makefourstring(TEMP_INT, 0);
    usartTRANSMIT("TEMP : ");
    usartTRANSMIT(TEMP);
 }

void show_DHTError(char errmsg){
    char *ERR = makedoublestring(errmsg);
    usartTRANSMIT("DHT11 Error");
    usartTRANSMIT("Err ");
    usartTRANSMIT(ERR);
}

void show_HCSR(){
    char *DIS = makethreestring(DIS_INT);
    usartTRANSMIT("Distance : ");
    usartTRANSMIT(DIS);
}
void show_HCSRError(char errmsg){
    char *ERR = makedoublestring(errmsg);
    usartTRANSMIT("HCSR04 Error");
    usartTRANSMIT("Err ");
    usartTRANSMIT(ERR);
}

void show_Reset(){
    usartTRANSMIT("Reset ...");
}
void show_Capture(){
    usartTRANSMIT("Capture ...");
}
void show_Welcome(){
    usartTRANSMIT("SmartPanipipe");
    usartTRANSMIT("TEAM 7");
}
