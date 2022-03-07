#include<LPC17xx.h>
void delay(unsigned long int x);
int a,b,c,d;
int and,or,xnor_or_xor_and,xor,xnor;
int main()
{ 
SystemInit();
LPC_SC->PCONP=0X00008000;
LPC_GPIO0->FIOMASK3=0X87;
//LPC_GPIO0->FIODIR3=0X87;//on board
LPC_GPIO0->FIODIR3=0X78;//simulation
LPC_GPIO0->FIOMASK1=0XF0;
LPC_GPIO0->FIODIR1=0X0F;
while(1)
{
a=(LPC_GPIO0->FIOPIN3&0X40)>>6;
b=(LPC_GPIO0->FIOPIN3&0X20)>>5;
c=(LPC_GPIO0->FIOPIN3&0X10)>>4;
d=(LPC_GPIO0->FIOPIN3&0X08)>>3;
and=(((a*b)*c)*d);
or=(((a|b)|c)|d);
xor=(((a^b)^c)^d);
xnor=!(((a^b)^c)^d);
xnor=xnor<<3;
or=or<<2;
xor=xor<<1;
xnor_or_xor_and=or|and|xor|xnor;
LPC_GPIO0->FIOPIN1=xnor_or_xor_and;
delay(0x1000);
}}
void delay(unsigned long int x)
{
unsigned long int i;
for(i=0;i<x;i++);
}

