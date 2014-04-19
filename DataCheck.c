#include    "smartpanipipe.h"

unsigned int sum;
unsigned int getCheckBytes(){
    for (char i=1; i<=24;i++){
        sum+=SMS_data[i];
    }
    if (days=4){
        for (char i=25; i<=32;i++){
            sum+=SMS_data[i];
        }
    }
    return sum;
}
