#include<LPC17XX.H>
void delay(unsigned long int x);
unsigned int val;
int main(){
unsigned char clock[4]={0x01,0x02,0x04,0x08};
unsigned int i,j;
SystemInit();
LPC_SC->PCONP=0X00008000;
LPC_GPIO1->FIOMASK=0XFFFC3FFF;
LPC_GPIO1->FIODIR=0X0003C000;
val=(50*2.5);
for(i=0;i<val;i++)
{
for(j=0;j<4;j++)
{
LPC_GPIO1->FIOPIN=clock[j]<<14;
delay(0x50000);
}
}
}
void delay(unsigned long int x)
{
unsigned long int i;
for(i=0;i<x;i++);
}