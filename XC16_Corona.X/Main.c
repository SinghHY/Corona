#include "p33Fxxxx.h"

_FGS(GSS_OFF & GWRP_OFF); //code protect off,write protect disabled
_FOSCSEL(FNOSC_PRIPLL & IESO_OFF);
_FOSC(FCKSM_CSECME & OSCIOFNC_OFF & POSCMD_HS);
_FWDT(FWDTEN_OFF);//watch dog disabled

unsigned char version = 20;   //new version for corona//

void main(void)
{

    // init SPI2

 SPI2CON1bits.SSEN = 1; // slave select pin enabled//

  SPI2CON1 = 0x8080;  // enable slave, mode8, cke=1, ckp = 0, smp = 0
  SPI2STAT = 0x8000;  // enables the spi
 
TRISG = 0x00;

}
//for main

//*************************************************************************************//
//Time to check SPI2 for any new data//
void __attribute__((__interrupt__,no_auto_psv)) _SPI2Interrupt(void) 

{    


}