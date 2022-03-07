						#include<LPC17xx.h>
#define RS 0X01
#define RW 0X02
#define EN 0x04
void delay(unsigned long int x);
void lcdwrt(unsigned char y);
unsigned char cmd[5]={0x38,0x0E,0x06,0x01,0x80};
unsigned char msg1[]="status of switch=";
unsigned char msg2[]="on";				   
unsigned char msg3[]="off";
unsigned int val;
int main(){
				
unsigned int i;
SystemInit();
LPC_SC->PCONP=0X00008000;
LPC_GPIO0->FIOMASK3=0XEF;  //mask for switch
LPC_GPIO0->FIODIR3=0X00;  //switch no 28
LPC_GPIO1->FIOMASK1=0XF8;
LPC_GPIO1->FIODIR1=0X07;//RS,RW,EN=OUTPUT
LPC_GPIO1->FIOCLR1=0X07;//RS==RW==EN=0
LPC_GPIO2->FIOMASK0=0X00;
LPC_GPIO2->FIODIR0=0XFF;  //D0-D7=OUTPUT
LPC_GPIO1->FIOCLR1=RS;
for(i=0;i<5;i++)
lcdwrt(cmd[i]);
LPC_GPIO1->FIOSET1=RS;
for(i=0;msg1[i]!='\0';i++)
lcdwrt(msg1[i]);
while(1){
LPC_GPIO1->FIOCLR1=RS;
lcdwrt(0xc0);

LPC_GPIO1->FIOSET1=RS;
val=LPC_GPIO0->FIOPIN3;
if((val)&0x10==0X10){
for(i=0;msg2[i]!='\0';i++)
lcdwrt(msg2[i]);			 }
else
{
for(i=0;msg3[i]!='\0';i++)
lcdwrt(msg3[i]);
}
}		 }
void delay(unsigned long int x){
unsigned long int i;
for(i=0;i<x;i++);
}
void lcdwrt(unsigned char y)
{
LPC_GPIO2->FIOPIN0=y;
LPC_GPIO1->FIOSET1=EN;
delay(0x50000);
LPC_GPIO1->FIOCLR1=EN;
delay(0x50000);
}

