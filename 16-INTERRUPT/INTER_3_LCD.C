#include<LPC17xx.h>
unsigned char msg1[]="there is interrupt";
unsigned char msg2[]="there is no interrupt";
unsigned char cmd[5]={0x38,0x0E,0x06,0x01,0x80};
void lcdwrt(unsigned char y);
void delay(unsigned long int x);
void ext_int();

void EINT1_IRQHandler(void)
{  unsigned int i;
NVIC_DisableIRQ(EINT1_IRQn);
LPC_GPIO1->FIOSET3=0X10;
LPC_GPIO1->FIOCLR1=0X03;
for(i=0;i<5;i++)
lcdwrt(cmd[i]);
LPC_GPIO1->FIOSET1=0X01;
for(i=0;msg2[i]!='\0';i++)
lcdwrt(msg2[i]);
delay(0x10000);
LPC_SC->EXTINT=0X00000002;
NVIC_EnableIRQ(EINT1_IRQn);
}

int main()
{
unsigned int i;
SystemInit();
LPC_SC->PCONP=0X00008000;
ext_int();
LPC_GPIO1->FIOMASK1=0XF8;
LPC_GPIO1->FIODIR1=0X07;
LPC_GPIO2->FIOMASK0=0X00;
LPC_GPIO2->FIODIR0=0XFF;
LPC_GPIO1->FIOMASK3=0XEF;
LPC_GPIO1->FIODIR3=0X10;
while(1)
{
LPC_GPIO1->FIOCLR3=0X10;
LPC_GPIO1->FIOCLR1=0X03;
for(i=0;i<5;i++)
lcdwrt(cmd[i]);
LPC_GPIO1->FIOSET1=0X01;
for(i=0;msg1[i]!='\0';i++)
lcdwrt(msg1[i]);
}
}
void lcdwrt(unsigned char y)
{
LPC_GPIO2->FIOPIN0=y;
LPC_GPIO1->FIOSET1=0X04;
delay(0x500);
LPC_GPIO1->FIOCLR1=0X04;
delay(0x5000);
}
void ext_int()
{
LPC_PINCON->PINSEL4=0X004000000;
LPC_SC->EXTMODE=0X00000002;
LPC_SC->EXTPOLAR=0X00000000;
NVIC_EnableIRQ(EINT1_IRQn);
}
void delay(unsigned long int x)
{
unsigned long int i;
for(i=0;i<x;i++);
}

