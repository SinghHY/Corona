/**********************************************************************
* Corona Firmware
* PerkinElmer Health Sciences Canada, Inc., 2017 
* FileName:        Main.c
* Processor:       dsPIC33FJ256GP510A
* Compiler:        CCS v5.074 or Higher
* Version:     
************************************************************************/

#include <33FJ256GP510.h>
#fuses XT,NOWDT,NOPROTECT
#device ADC = 12 
#use delay(clock = 100Mhz, crystal = 40Mhz)
#use spi(SLAVE, SPI2, BITS = 8, MODE = 0, ENABLE = PIN_G9, stream = SPI_2)

#define GREEN_LED  PIN_A6
#define RED_LED  PIN_A7

   
#bank_dma 
    unsigned int8  TxBuffer[4];
#bank_dma 
    unsigned int8  RxBuffer[4]; 
 
void main()
{  
   setup_adc_ports(sAN0|sAN1|sAN2|sAN3, VSS_VDD);
   setup_adc(ADC_CLOCK_INTERNAL);  
   
   setup_dma(2, DMA_OUT_SPI2, DMA_BYTE);  
   setup_dma(0, DMA_IN_SPI2, DMA_BYTE);

   spi_prewrite(TxBuffer[0]);
   dma_start(0, DMA_CONTINOUS ,&RxBuffer[0],3);  
   dma_start(2, DMA_CONTINOUS ,&TxBuffer[0],3);   
  
   setup_timer2(TMR_INTERNAL | TMR_DIV_BY_1, 39);
   
   setup_compare(1, COMPARE_PWM | COMPARE_TIMER2);
   set_pwm_duty(1,0);
   setup_compare(2, COMPARE_PWM | COMPARE_TIMER2);
   set_pwm_duty(2,0);
   while(1)
   {
       
   }
}   