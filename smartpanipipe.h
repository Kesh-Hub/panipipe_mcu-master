/*============================== CUSTOM HEADER =================================
    CUSTOM HEADER FOR THE PROJECT, INCLUDES:
    - STANDARD LIBRARY
    - DEFINITION
    - SHARED VARIABLES
    - CUSTOMISED FUNCTIONS PROTOTYPE

    File:      smartpanipipe.h
    Author:    Lucky Lim
==============================================================================*/


/*============================ STANDARD LIBRARY=================================
==============================================================================*/

#include    <xc.h>			// XC general include file

#include    <stdint.h>                   // Core Input and Output Functions
#include    <stdio.h>                   // Core Input and Output Functions
#include    <stdlib.h>                  // Numeric Conversion Functions,
                                        // Pseudo-Random Numbers Generation Functions,
                                        // Memory Allocation,
                                        // Process Control Functions

#include    <math.h>                    // Defines common mathematical functions

#include    <plib/spi.h>                // XC8 Peripheral Library for SPI
#include    <plib/timers.h>              // XC8 Peripheral Library for Timers (optional)
#include    <plib/usart.h>              // XC8 Peripheral Library for Timers (optional)
#include    "plib/adc.h"                //XC8 Peripheral Library for ADC

#include    <string.h>                  // Allows string data manipulation

#include    <pic18f25k22.h>            // Optional Header for PIC18F25K22


/*============================== DECLARATION ===================================
==============================================================================*/
// SETTING XTAL FREQUENCY FOR TIME DELAYS MACRO
// XTAL_FREQ = CLOCK FREQUENCY, i.e.
// For PIC18F25k22 with Internal Clock Used -> 111 - 16MHZ
#define _XTAL_FREQ 16000000
#define WATER_THRESHOLD 15
#define SOLAR_THRESHOLD 15
#define OFFSET (char)31
#define STOP_BIT (char)164
#define WARNING_BIT (char)165
#define START_BIT (char)163
///////////////////////////////////////
/////// SENSOR PIN CONNECTION  ////////
///////////////////////////////////////
// DHT11 - Temperature and Humidity Sensor
#define DHT11_POWER_CONFIG TRISAbits.RA0
#define DHT11_SIGNAL_CONFIG TRISCbits.RC0
#define DHT11_POWER PORTAbits.RA0
#define DHT11_SIGNAL PORTCbits.RC0

// HC-SR04 - Ultrasonic Distance Measuring Sensor
#define HCSR04_POWER_CONFIG TRISBbits.RB3
#define HCSR04_TRIGGER_CONFIG TRISBbits.RB2
#define HCSR04_ECHO_CONFIG TRISBbits.RB1
#define HCSR04_POWER PORTBbits.RB3
#define HCSR04_TRIGGER PORTBbits.RB2
#define HCSR04_ECHO PORTBbits.RB1

// Conductivity
#define COND_SIGNAL_CONFIG TRISAbits.RA0
#define COND_SIGNAL PORTAbits.RA0


///////////////////////////////////////
/////// SOLAR PANEL AND BATTERY  ////////
///////////////////////////////////////
// Solar Panel
#define SOLAR_POWER_CONFIG TRISBbits.RB5
#define SOLAR_SIGNAL_CONFIG TRISBbits.RB4
#define SOLAR_POWER PORTBbits.RB5
#define SOLAR_SIGNAL PORTBbits.RB4

// Battery
#define BATT_SIGNAL_CONFIG TRISBbits.RB3
#define BATT_SIGNAL PORTBbits.RB3

///////////////////////////////////////////////
///////////// COMMUNICATION PORT //////////////
///////////////////////////////////////////////
#define SIM900_POWER_CONFIG TRISCbits.RC4
#define SIM900_TRIGGER_CONFIG TRISCbits.RC5
#define SIM900_POWER PORTCbits.RC4
#define SIM900_TRIGGER PORTCbits.RC5
#define SIM900_RX PORTCbits.RC7
#define SIM900_TX PORTCbits.RC6

#define PIC_RX2_CONFIG TRISBbits.RB7
#define PIC_TX2_CONFIG TRISBbits.RB6 //black
#define PIC_RX2 PORTBbits.RB7
#define PIC_TX2 PORTBbits.RB6

/*==================== INITIATING VARIABLES REQUIRED ===========================
==============================================================================*/

volatile unsigned char TimeOUT; //Used to store TRUE and FALSE BIT
volatile unsigned char TEMP_INT, TEMP_DEC, RH_INT, RH_DEC, DIS_INT;
volatile unsigned char ErrorMSG; //Used to store the Error Message No.

volatile char message; //  Used for store received msg from the computer
    char days=0;
    char solarcounter = 0;
    char tempcounter = 0;
    unsigned char RXdata[60];
    unsigned char SMS_data[50];
    unsigned char count = 0; //for testing only
    unsigned char DayTEMP[7];
    unsigned char DayHUM[7];
    unsigned char avgTEMP, avgHUM, minTEMP, maxTEMP, minHUM, maxHUM; //Temperature & Humidity sensor variables
    unsigned char WaterLevel;
    unsigned int Conductivity;

/*=========================== FUNCTION PROTOTYPE ===============================
==============================================================================*/
// FUNCTION

void routine();
void test();

// PrintMSG
extern void show_DHT();
extern void show_HCSR();
extern void show_DHTError(char errmsg);
extern void show_HCSRError(char errmsg);
extern void show_Reset();
extern void show_Capture();
extern void show_Welcome();

// GEN_Library
extern void startTimePIN();
extern int readTimePIN();

extern void delay_1us(char x);
extern void delay_10us(char x);
extern void delay_100us(char x);
extern void delay_1ms(char x);
extern void delay_10ms(char x);
extern void delay_100ms(char x);
extern void delay_1s(char x);

extern char makedigit (int *number, int base);
extern char *makefourstring (int number, int deci);
extern char *makedoublestring (int number);
extern char *makethreestring (int number);

extern void sleep(); //timer to keep device in sleep mode

//MEMORY
extern char ReadMemory(char addr);
extern void WriteMemory(char addr, char data);
extern void SaveData();
extern void gatherData();
extern void ShiftData();

//ISR
extern void INTERRUPT_Config();
extern void interrupt ISR();

//DHT11
extern void getTempHum();
extern void avgTempHum();
extern void minmaxTempHum();
extern void DHT_Config();
extern void DHT_Start();
extern unsigned char DHT_CheckResponse();
extern unsigned char DHT_ReadByte();
extern unsigned char DHT_Reading();

//HC-SR04
extern void getWaterLevel();
extern void HCSR_Config();
extern void HCSR_Start();
extern int HCSR_Time();
extern int HCSR_Distance(int time);
extern char HCSR_Reading();

//USART
extern void relayMSG();
extern void transmitWaterLevel();
extern void transmitData();
extern void usartTRANSMIT(char *msg);

//SIM900
extern void initUSART1();
extern void initSIM900();
extern void SIM900_SWITCH();
extern void GSM_ON();
extern void GSM_OFF();
extern void sendMessage();
extern unsigned char uartReceive(unsigned char data[]);
extern unsigned char serverReceive(unsigned char data[]);
extern void SIM900_SEND();

// DataCheck
extern unsigned int getCheckBytes();

//To be defined
extern void getConductivity();
extern void getImage();
