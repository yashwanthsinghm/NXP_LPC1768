#include<LPC17XX.h>
#include<math.h>
void delay(unsigned long int x);
int main()
{
unsigned int val;
signed int i;
SystemInit();
LPC_PINCON->PINSEL1=0X00200000;
while(1)
{
for(i=0;i<360;i++)
{
val=466+(466*sin(i*3.14/180));
LPC_DAC->DACR=val<<6;
}
LPC_DAC->DACR=932<<6;
delay(0x10000);
LPC_DAC->DACR=0x00<<6;
delay(0x10000);
for(i=466;i<932;i++){
LPC_DAC->DACR=i<<6;	 
delay(0x25);}
for(i=932;i>0;i--){
LPC_DAC->DACR=i<<6;
delay(0x25);}
for(i=0;i<466;i++){
LPC_DAC->DACR=i<<6;
delay(0x25);
}
}
}
void delay(unsigned long int x)
{
unsigned long int i;
for(i=0;i<x;i++);
}