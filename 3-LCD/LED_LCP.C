#include<LPC17xx.h>
void delay(unsigned long int x);

int main(){
SystemInit();
LPC_SC->PCONP=0X00008000;
LPC_GPIO0->FIOMASKH=0X00;
LPC_GPIO0->FIODIRH=0XFF;//RS,RW,EN=OUTPUT
while(1)
{
 LPC_GPIO0->FIOSETH=0XFF;
 delay(0x10000);
 LPC_GPIO0->FIOCLRH=0X00;
delay(0x10000);
  }
 }
void delay(unsigned long int x){
unsigned long int i;
for(i=0;i<x;i++);
}
