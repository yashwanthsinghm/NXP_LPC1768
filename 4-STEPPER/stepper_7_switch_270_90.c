#include<LPC17XX.H>
void delay(unsigned long int x);
unsigned int clock[4]={0x01,0x02,0x04,0x08};
unsigned int anti[4]={0x08,0x04,0x02,0x01};
unsigned int val;
int main()
{unsigned int i,j;
SystemInit();
LPC_SC->PCONP=0X00008000;
LPC_GPIO1->FIOMASK=0XFFFC3FFF;
LPC_GPIO1->FIODIR=0X0003C000;
LPC_GPIO0->FIOMASK3=0XE7;
LPC_GPIO0->FIODIR3=0X18;//simulation
//LPC_GPIO0->FIODIR3=0X00;//on board
while(1)
{

while((((LPC_GPIO0->FIOPIN3)&0X10)>>4)!=1);
val=((LPC_GPIO0->FIOPIN3)&0X08)>>3;
if(val==1){
for(i=0;i<38;i++)
	{
	for(j=0;j<4;j++)
	   {
     	LPC_GPIO1->FIOPIN=clock[j]<<14;
	    delay(0x50000);
	    }
	 }
	       }
else{
for(i=0;i<12;i++)
	{
	for(j=0;j<4;j++)
	   {
     	LPC_GPIO1->FIOPIN=anti[j]<<14;
	    delay(0x50000);
	    }
	 }
    }
 }
 }
 void delay(unsigned long int x)
 {
 unsigned long int i;
 for(i=0;i<x;i++);
 }

