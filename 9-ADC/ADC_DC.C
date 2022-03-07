#include<LPC17XX.H>
void delay(unsigned long int x);
unsigned int val,off;
int main()
{
unsigned int i;
SystemInit();
LPC_SC->PCONP=0X00009008;
LPC_PINCON->PINSEL3=0XC0000000;
LPC_GPIO1->FIOMASK0=0XEC;
LPC_GPIO1->FIODIR0=0X13;
LPC_ADC->ADCR=0X00210220;
while(1)
{
while((LPC_ADC->ADSTAT&0X20)!=0X20);
val=(LPC_ADC->ADDR5)&0xFFF0;
off=0XFFF0-val;
for(i=0;i<val;i++)
LPC_GPIO1->FIOPIN0=0X03;
for(i=0;i<off;i++)
LPC_GPIO1->FIOPIN0=0X02;
}
}