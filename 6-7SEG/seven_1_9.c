#include<LPC17xx.h>
#define SRCLK 0X0080
#define SCLK 0X0100
#define SERIAL 0X0200
void delay(unsigned long int x);
int val1,val2,i,j;
int val[10]={0x3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X67};
int main()
{

SystemInit();
LPC_GPIO0->FIOMASKH=0XFC7F;
LPC_GPIO0->FIODIRH=0X0380;
LPC_GPIO0->FIOCLRH=SERIAL;
LPC_GPIO0->FIOCLRH=SCLK;
LPC_GPIO0->FIOCLRH=SRCLK;
for(i=0;i<10;i++)
{
LPC_GPIO0->FIOCLRH=SCLK;
val1=val[i];
 for(j=0;j<8;j++)
 {
 LPC_GPIO0->FIOCLRH=SRCLK;
 delay(0x100000);
 val2=val1&0x80;
 if(val2==0x80){
 LPC_GPIO0->FIOSETH=SERIAL;
 //delay(0x900000);
 }
 else {
 LPC_GPIO0->FIOCLRH=SERIAL;
 //delay(0x900000);
 }
 LPC_GPIO0->FIOSETH=SRCLK;
 val1=val1<<1;
 delay(0x100000);
 }
 delay(0x1000);
LPC_GPIO0->FIOSETH=SCLK;
delay(0x100000);
}
}
void delay(unsigned long int x)
{
unsigned long int k;
for(k=0;k<x;k++);
}
