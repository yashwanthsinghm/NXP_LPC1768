#include<LPC17XX.h>
void delay(unsigned long int x);
int main()
{
SystemInit();
LPC_PINCON->PINSEL1=0X00200000;
while(1)
{
LPC_DAC->DACR=0X0000;
delay(3000);
LPC_DAC->DACR=0XFFFF;
delay(7000);
}
}
void delay(unsigned long int x)
{
unsigned long int i;
for(i=0;i<x;i++);
}