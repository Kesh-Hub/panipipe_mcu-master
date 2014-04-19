#include    "smartpanipipe.h"

void configure_ADC(){
    COND_SIGNAL_CONFIG = 1;
    OpenADC(ADC_FOSC_16&ADC_RIGHT_JUST&ADC_0_TAD, ADC_CH0&ADC_INT_OFF&ADC_REF_VDD_VSS, 0b1110);
}

unsigned int get_ADC_value(void){
    unsigned int max;

    ConvertADC();                               // start conversion
    while(BusyADC());                           //wait while conversion takes place

    max=ReadADC();
    for (int i=0; i<10000; i++){
        ConvertADC();                           // start conversion
        while(BusyADC());                       //wait while conversion takes place
        unsigned int new = ReadADC();
        if (new >= max){
            max=new;
        }
        delay_1us(1);
    }
    return max;
}

void getConductivity(){
    float y;                           // variable for delay adc scaling
    unsigned int k;                             // variable for scaled delay value
    float m = 0.003;                   // cell constant
    float c = 2.7;                     // y-intercept

    configure_ADC();                            // function call to configure adc
    k= get_ADC_value();                         // gets 10 bit adc value
    y = (float) k*(float) (4.73f/1023f);        // adc scaled value now scaled and ready
    Conductivity = (y - c)/m;                   // calculate conductivity value
}