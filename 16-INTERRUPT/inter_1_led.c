#include<LPC17xx.h>
void delay(unsigned long int x);
void ex_int();
void EINT1_IRQHandler(void)
{	 unsigned int i;
NVIC_DisableIRQ(EINT1_IRQn);
for(i=0;i<10;i++)
{
LPC_GPIO0->FIOSET3=0X10;
delay(0x1000);
LPC_GPIO0->FIOCLR3=0X10;
delay(0x1000);
}
LPC_SC->EXTINT=0X00000002;
NVIC_EnableIRQ(EINT1_IRQn);
}
int main(){
SystemInit();
LPC_SC->PCONP=0X00008000;
LPC_GPIO0->FIOMASK3=0XEF;
LPC_GPIO0->FIODIR3=0X10;
LPC_GPIO0->FIOMASK1=0XF0;
LPC_GPIO0->FIODIR1=0X0F;
ex_int();
while(1)
{
LPC_GPIO0->FIOSET1=0X0F;
delay(0x1000);
LPC_GPIO0->FIOCLR1=0X0F;
delay(0x1000);
}}
void delay(unsigned long int x)
{
unsigned long int i;
for(i=0;i<x;i++);
}
void ex_int(){
LPC_PINCON->PINSEL4=0X00400000;
LPC_SC->EXTMODE=0X00000002;
LPC_SC->EXTPOLAR=0X00000000;
NVIC_EnableIRQ(EINT1_IRQn);
}