#include<LPC17XX.h>
int main()
{
unsigned int val;
SystemInit();
LPC_SC->PCONP=0X00009000;
LPC_PINCON->PINSEL3=0XC0000000;
LPC_PINCON->PINSEL1=0X00200000;
LPC_ADC->ADCR=0X00210220;
while(1)
{
while((LPC_ADC->ADSTAT&0X20)!=0X20);
val=LPC_ADC->ADDR5&0XFFF0;
LPC_DAC->DACR=val;
}
}

