#include<LPC17XX.h>
void delay(unsigned long int x);
int main()
{	signed int i;
SystemInit();
LPC_PINCON->PINSEL1=0X00200000;
while(1)
{
for(i=0;i<1023;i++){
LPC_DAC->DACR=i<<6;
}
for(i=1023;i>0;i--){
LPC_DAC->DACR=i<<6;	}
}
}
void delay(unsigned long int x)
{
unsigned long int i;
for(i=0;i<x;i++);
}