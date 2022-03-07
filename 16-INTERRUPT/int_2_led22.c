#include<LPC17xx.h>
void delay(unsigned long int x);
void ex_int();
void EINT2_IRQHandler(void)
{  unsigned int i;
NVIC_DisableIRQ(EINT2_IRQn);
for(i=0;i<10;i++){
LPC_GPIO1->FIOSET3=0X10;
delay(0x1000);
LPC_GPIO1->FIOCLR3=0X10;
delay(0x1000);
}
LPC_SC->EXTINT=0X00000004;
NVIC_EnableIRQ(EINT2_IRQn);
}
int main(){

SystemInit();
LPC_SC->PCONP=0X00008000;
LPC_GPIO1->FIOMASK3=0XEF;
LPC_GPIO1->FIODIR3=0X10;
LPC_GPIO0->FIOMASK1=0XF0;
LPC_GPIO0->FIODIR1=0X0F;
while(1)
{
LPC_GPIO0->FIOSET1=0X0F;
delay(0x1000);
LPC_GPIO0->FIOCLR1=0X0F;
delay(0x1000);
}}
void ex_int()
{
LPC_PINCON->PINSEL4=0X01000000;
LPC_SC->EXTMODE=0X00000004;
LPC_SC->EXTPOLAR=0X00000000;
NVIC_EnableIRQ(EINT2_IRQn);
}
void delay(unsigned long int x)
{
unsigned long int i;
for(i=0;i<x;i++);
}