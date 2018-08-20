/**********************************************************************
* Corona Control 
* © PerkinElmer Health Sciences Canada, Inc., 2017
* This program is Corona Voltage control. 
* FileName:        Main.c
* Processor:       dsPIC33FJ256GP510
* Compiler:        XC16 v1.32 or Higher
* Version:     
************************************************************************/
#include "p33Fxxxx.h"
#include "time.h"

_FGS(GSS_OFF & GWRP_OFF); //code protect off,write protect disabled
_FOSCSEL(FNOSC_PRIPLL & IESO_OFF);
_FOSC(FCKSM_CSECME & OSCIOFNC_OFF & POSCMD_HS);
_FWDT(FWDTEN_OFF);//watch dog disabled

unsigned char version = 20;   //new version for corona//
int txdData1, rxdData1, SPIFlag = 0;

/* **********************   SPI Interrupt *************************/
void __attribute__((__interrupt__,no_auto_psv)) _SPI2Interrupt(void) 
{    
    IFS2bits.SPI2IF = 0;
    SPI2STATbits.SPIROV = 0;  // Clear SPI1 receive overflow flag if set //
    rxdData1 = SPI2BUF;
    
    SPIFlag =1;
    if (!SPI2STATbits.SPITBF)
                SPI2BUF = txdData1;

}

unsigned short ADC_Read(unsigned short ch)
  {
    unsigned short ADC_out;
    AD1CHS0 = ch;//select AN0 //
    AD1CON1bits.SAMP = 1; // start sampling  ADC1
    while (!AD1CON1bits.DONE);
    AD1CON1bits.DONE = 0;
    ADC_out = ADC1BUF0;
    ADC_out >>= 2; //adjust adc from 10 bit to 8 bit value//
    return ADC_out;
  }

void main(void)
{

    long int sum =0;

    int Instruction1; // 1,2,3
    int CurrentAverage = 0;
    int CurrentAverageOld = 0;
    int MyCounter = 0;
    int MyDelay =0;

    unsigned short ResultHV;
    unsigned short ResultCurrent;
    unsigned short CronaCurrent = 0;
    unsigned short CronaSettingPos = 0;
    unsigned short CronaSettingNeg = 0;

    unsigned char TempSetpointLow=0;
    unsigned char TempSetpointHi=0;
    unsigned char VoltageMonitorLow1=0;
    unsigned char VoltageMonitorHi1=0;
    unsigned char HVSetpointLow1=0;
    unsigned char HVSetpointHi1=0;
    unsigned char APCIRealTime =0;
    unsigned char ProbeId=0x0;
    unsigned char version = 19;   //new version for corona//

  SPI2CON1bits.SSEN = 1; // slave select pin enabled//
  SPI2CON1 = 0x8080;  // enable slave, mode8, cke=1, ckp = 0, smp = 0
  SPI2STAT = 0x8000;  // enables the spi
 
  TRISG = 0x00;

  


}
//for main

//*************************************************************************************//
//Time to check SPI2 for any new data//
