#include<LPC17XX.h>
void delay(unsigned long int x);
void speed_clock(unsigned int x);
void speed_anti(unsigned int x);
unsigned int val,val1,val2;
int main()
{
SystemInit();
LPC_SC->PCONP=0X00008000;
LPC_GPIO0->FIOMASK3=0X8F;
LPC_GPIO0->FIODIR3=0X70;//simulation
//LPC_GPIO0->FIODIR3=0X00;//on board
LPC_GPIO1->FIOMASK0=0XEC;
LPC_GPIO1->FIODIR0=0X13;
while(1)
{
val=((LPC_GPIO0->FIOPIN3)&0X40)>>6;
val1=((LPC_GPIO0->FIOPIN3)&0X20)>>5;
val2=((LPC_GPIO0->FIOPIN3)&0X10)>>4;
if(val==1)
{
 if((val1==1)&&(val2==1))
    speed_clock(0xFFFF);
 else if((val1==1)&&(val2==0))
    speed_clock(0x0FFF);
 else if((val1==0)&&(val2==1))
    speed_clock(0x00FF);
 else if((val1==0)&&(val2==0))
    speed_clock(0x000F);
}
else
{
if((val1==1)&&(val2==1))
    speed_anti(0xFFFF);
 else if((val1==1)&&(val2==0))
    speed_anti(0x0FFF);
 else if((val1==0)&&(val2==1))
    speed_anti(0x00FF);
 else if((val1==0)&&(val2==0))
    speed_anti(0x000F);
}
}
}
void delay(unsigned long int x)
{
unsigned long int i;
for(i=0;i<x;i++);
}
void speed_clock(unsigned int x)
{
unsigned int i;
for(i=0;i<x;i++)
LPC_GPIO1->FIOPIN0=0X03;
for(i=0;i<(0xFFFF-x);i++)
LPC_GPIO1->FIOPIN0=0X02;
}
void speed_anti(unsigned int x)
{
unsigned int i;
for(i=0;i<x;i++)
LPC_GPIO1->FIOPIN0=0X12;
for(i=0;i<(0xFFFF-x);i++)
LPC_GPIO1->FIOPIN0=0X02;
}
