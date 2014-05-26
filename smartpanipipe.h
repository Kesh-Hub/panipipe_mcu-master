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
#define SOLAR_THRESHOLD 15
#define SOLAR_OFFSET 10
#define CELL_CONSTANT 0.003
#define Y_INTERCEPT 2.7
#define OFFSET (char)32
#define DATA_PREFIX (char)163
#define DATA_SUFFIX (char)164
#define WARNING_PREFIX (char)165
#define CONFIG_PREFIX (char)167
///////////////////////////////////////
/////// SENSOR PIN CONNECTION  ////////
///////////////////////////////////////
// DHT11 - Temperature and Humidity Sensor
#define DHT11_POWER_CONFIG TRISAbits.RA6
#define DHT11_SIGNAL_CONFIG TRISCbits.RC0
#define DHT11_POWER PORTAbits.RA6
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
#define COND_POWER_CONFIG TRISBbits.RB0
#define COND_POWER PORTBbits.RB0

///////////////////////////////////////
/////// SOLAR PANEL AND BATTERY  ////////
///////////////////////////////////////
// Solar Panel
#define SOLAR_POWER_CONFIG TRISBbits.RB4
#define SOLAR_SIGNAL_CONFIG TRISAbits.RA2
#define SOLAR_POWER PORTBbits.RB4
#define SOLAR_SIGNAL PORTAbits.RA2
#define BATTERY_THRESHOLD 960

// Battery
#define BATT_SIGNAL_CONFIG TRISAbits.RA1
#define BATT_SIGNAL PORTAbits.RA1

///////////////////////////////////////////////
///////////// COMMUNICATION PORT //////////////
///////////////////////////////////////////////
#define SIM900_POWER_CONFIG TRISCbits.RC4
#define SIM900_TRIGGER_CONFIG TRISCbits.RC5
#define SIM900_POWER PORTCbits.RC4
#define SIM900_TRIGGER PORTCbits.RC5
#define SIM900_RX_CONFIG TRISCbits.RC7
#define SIM900_TX_CONFIG TRISCbits.RC6

#define PIC_RX2_CONFIG TRISBbits.RB7
#define PIC_TX2_CONFIG TRISBbits.RB6 //black
#define PIC_RX2 PORTBbits.RB7
#define PIC_TX2 PORTBbits.RB6

/*==================== INITIATING VARIABLES REQUIRED ===========================
==============================================================================*/

volatile unsigned char TimeOUT; //Used to store TRUE and FALSE BIT
volatile unsigned char TEMP_INT, TEMP_DEC, RH_INT, RH_DEC, DIS_INT;
volatile unsigned char ErrorMSG; //Used to store the Error Message No.
volatile char message;                                                  //used to store received msg from the computer

unsigned char WATER_THRESHOLD = 20;
unsigned char TRANSMIT_FREQ = 3;
unsigned char CONFIG_FREQ = 15;

unsigned char count = 0; //for testing only
unsigned char initcheck=1;                                          //used to check if device has been initialised for the first time
unsigned char days=0;                                               //used to count number of days passed since last transmission
unsigned char solarcounter = 0;                                     //used to check if solar panel is not responsive
unsigned char tempcounter = 0;                                      //used to measure temperature and humidity at regular intervals
unsigned char RXdata[60];                                           //used to store received data from GSM module
unsigned char SMS_data[50];                                         //used to store data to be transmitted in text message
unsigned char DayTEMP[7];                                           //used to store temperature values of current day
unsigned char DayHUM[7];                                            //used to store humidity values of current day
unsigned char avgTEMP, avgHUM, minTEMP, maxTEMP, minHUM, maxHUM;    //used to store calculated temperature and humidity values
unsigned char WaterLevel;                                           //used to store the waterlevel sensed by ultrasonic sensor
unsigned int Conductivity;                                          //used to store the conductivity value from sensor
unsigned char CheckByte;                                            //used to store the calculated checkbyte to be transmitted in text message
unsigned int BatteryLevel= 0;                                       //used to store current battery level
unsigned int SolarLevel = 0;                                        //used to store current solar power level
/*=========================== FUNCTION PROTOTYPE ===============================
==============================================================================*/
// FUNCTION

void routine();
void demo_test();

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
extern void sendData();
extern void sendConReq();
extern unsigned char configReceive();
extern unsigned char uartReceive(unsigned char data[]);
extern unsigned char serverReceive(unsigned char data[]);
extern void SIM900_SEND(char type);

// DataCheck
extern void getCheckByte();

//Solar Panel and Battery monitor
extern void MonitorBattery();
extern void getBatteryLevel();
extern void getSolarLevel();
extern void ChargeBattery();
extern unsigned char BatteryCharged();
extern unsigned char SolarStatus();

//To be defined
extern void getConductivity();
extern void getImage();
