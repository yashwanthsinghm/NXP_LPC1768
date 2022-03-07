#include<LPC17xx.h>
#include<math.h>
void delay(unsigned long int x);
int main(){
unsigned int val;
signed int i;
SystemInit();
LPC_PINCON->PINSEL1=0X00200000;
while(1)
{
LPC_DAC->DACR=0X00<<6;
delay(0x1000);
LPC_DAC->DACR=0X26D<<6;
delay(0x1000);
LPC_DAC->DACR=0X136<<6;
delay(0x2000);
for(i=0;i<50;i++)
{
val=0x136+(0x136*sin(i*3.14/180));
LPC_DAC->DACR=val<<6;
}
for(i=547;i<932;i++)
LPC_DAC->DACR=i<<6;
for(i=932;i>547;i--)
LPC_DAC->DACR=i<<6;
for(i=50;i>0;i--)
{
val=0x136+(0x136*sin(i*3.14/180));
LPC_DAC->DACR=val<<6;
}
LPC_DAC->DACR=0X136<<6;
delay(0x2000);
LPC_DAC->DACR=0X26D<<6;
delay(0x1000);
LPC_DAC->DACR=0X00<<6;
delay(0x1000);
}
} 
void delay(unsigned long int x)
{
unsigned long int i;
for(i=0;i<x;i++);
}