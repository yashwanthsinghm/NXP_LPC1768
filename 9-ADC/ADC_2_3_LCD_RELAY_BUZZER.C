#include<LPC17XX.h>
#define rs 0x01
#define rw 0x02
#define en 0x04
void delay(unsigned long int x);
void lcdwrt(unsigned char y);
unsigned int val,val1;
unsigned char con[10];
unsigned char cmd[5]={0x38,0x0E,0X06,0X01,0X80};
unsigned char msg1[]="converted value is";
unsigned int i,qot,rem;
int main()
{
signed k;

SystemInit();
LPC_SC->PCONP=0X00009000;
LPC_PINCON->PINSEL3=0XC0000000;
LPC_GPIO1->FIOMASK1=0XF8;
LPC_GPIO1->FIODIR1=0X07;
LPC_GPIO2->FIOMASK0=0X00;
LPC_GPIO2->FIODIR0=0XFF;
LPC_ADC->ADCR=0X00210220;

LPC_GPIO0->FIOMASK2=0X9F;
LPC_GPIO0->FIODIR2=0X60;
while(1){
while((LPC_ADC->ADSTAT)&0X20!=0X20)
{}
val=(LPC_ADC->ADDR5>>4)&0XFFF;
val1=val;
if(val>0x1FF)
{LPC_GPIO0->FIOPIN2=0X40;   }
else
{LPC_GPIO0->FIOPIN2=0X20; }

for(k=3;k>0;k--) {
rem=val1%0x0A;
qot=val1/0x0A;
con[i]=	rem+0x30;
val1=qot;
}
con[4]='\0';
LPC_GPIO1->FIOCLR1=rw;
LPC_GPIO1->FIOCLR1=rs;
for(i=0;i<5;i++)
lcdwrt(cmd[i]);
LPC_GPIO1->FIOSET1=rs;
for(i=0;msg1[i]!=0;i++)
lcdwrt(msg1[i]);
LPC_GPIO1->FIOCLR1=rs;
lcdwrt(0xc0);
LPC_GPIO1->FIOSET1=rs;
 for(i=0;con[i]!=0;i++)
lcdwrt(con[i]);



}}

void delay(unsigned long int x)
{
unsigned long int i;
for(i=0;i<x;i++);
}

void lcdwrt(unsigned char y){
LPC_GPIO2->FIOPIN0=y;
LPC_GPIO1->FIOSET1=en;
delay(0x5000);
LPC_GPIO1->FIOCLR1=en;
delay(0x5000);
}
