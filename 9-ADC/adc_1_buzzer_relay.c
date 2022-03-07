#include<LPC17XX.h>
void delay(unsigned long int x);
unsigned int val;
int main()
{
SystemInit();
LPC_SC->PCONP=0X00009000;
LPC_PINCON->PINSEL3=0XC0000000;
LPC_ADC->ADCR=0X00210220;
while(1){
LPC_GPIO0->FIOMASK2=0X9F;
LPC_GPIO0->FIODIR2=0X60;
while((LPC_ADC->ADSTAT)&0X20!=0X20)
{}
val=(LPC_ADC->ADDR5>>4)&0XFFF;
if(val>0x1FF)
LPC_GPIO0->FIOPIN2=0X40;
else
LPC_GPIO0->FIOPIN2=0X20;
}}
void delay(unsigned long int x)
{
unsigned long int i;
for(i=0;i<x;i++);
}

