#include<LPC17xx.h>
#define RS 0X20
#define EN 0x40
void delay(unsigned long int x);
void lcdwrt(unsigned char y);
unsigned char cmd[5]={0x28,0x00,0x00,0x00,0x80};
unsigned char msg1[]="yashwanth";
unsigned int val;
int main(){
				
unsigned int i;
SystemInit();
LPC_SC->PCONP=0X00008000;
LPC_GPIO0->FIOMASK2=0X1F;
LPC_GPIO0->FIODIR2=0XE0;//RS,RW,EN=OUTPUT
//LPC_GPIO0->FIOCLR1=0XE0;//RS==RW==EN=0
LPC_GPIO0->FIOMASK3=0XF8;
LPC_GPIO0->FIODIR3=0X07;  //D0-D7=OUTPUT
LPC_GPIO1->FIOCLR1|=RS;
for(i=0;i<5;i++)
lcdwrt(cmd[i]);
LPC_GPIO0->FIOSET2|=RS;
for(i=0;msg1[i]!='\0';i++)
lcdwrt(msg1[i]);
//while(1){
//LPC_GPIO0->FIOCLR2=RS;
//lcdwrt(0xc0);
//
//LPC_GPIO0->FIOSET2=RS;
//val=LPC_GPIO0->FIOPIN3;
//if((val)&0x10==0X10){
//for(i=0;msg2[i]!='\0';i++)
//lcdwrt(msg2[i]);			 }
//else
//{
//for(i=0;msg3[i]!='\0';
//}		
 }
void delay(unsigned long int x){
unsigned long int i;
for(i=0;i<x;i++);
}
void lcdwrt(unsigned char y)
{
LPC_GPIO0->FIOPINH|=y<<7;
LPC_GPIO0->FIOSET2|=EN;
delay(0x50000);
LPC_GPIO0->FIOCLR2|=EN;
delay(0x50000);
}

