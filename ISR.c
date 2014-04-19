/*========================INTERRUPT SERVICE ROUTINE============================
                            SETTING UP INTERRUPT
                             1. Timer Overflow
==============================================================================*/
#include    "smartpanipipe.h"

void INTERRUPT_Config(){

    //Enable global interrupt
    GIE = 1;
    // Enable peripheral interrupt
    PEIE = 1;

    OpenTimer0(TIMER_INT_ON & T0_16BIT & T0_PS_1_8 & T0_SOURCE_INT);

}
void interrupt ISR(){
    if(INTCONbits.TMR0IF == 1 && INTCONbits.TMR0IE == 1){
        TimeOUT = 1;
        WriteTimer0(0);
        INTCONbits.TMR0IF = 0;
    }
}
