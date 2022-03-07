#include<LPC17xx.h>
void delay(unsigned long int x);
void speed(unsigned int x);
int main()
{
SystemInit();
LPC_GPIO1->FIOMASK0=0XEC;
LPC_GPIO1->FIODIR0=0X13;
while(1)
{
speed(0xFFFF);
delay(0x1000);
}
}
void delay(unsigned long int x)
{
unsigned long int i;
for(i=0;i<x;i++);
}
void speed(unsigned int x)
{
unsigned int val;
for(val=0;val<x;val++)
LPC_GPIO1->FIOSET0=0X03;
for(val=0;val<(0xFFFF-x);val++)
LPC_GPIO1->FIOCLR0=0X02;
}

