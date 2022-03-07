#include<LPC17xx.h>
void delay(unsigned long int x);
void lcdwrt(unsigned char y);
unsigned char msg1[]="welcome to";
unsigned char msg2[]="Department ECE";
unsigned char cmd[5]={0x28,0x0E,0X06,0X01,0X82};
int main()
{
unsigned int i;
SystemInit();
LPC_GPIO1->FIOMASK1=0XF8;
LPC_GPIO1->FIODIR1=0X07;
LPC_GPIO2->FIOMASK0=0X00;
LPC_GPIO2->FIODIR0=0XFF;
LPC_GPIO1->FIOCLR1=0X07;
for(i=0;i<5;i++)
lcdwrt(cmd[i]);
LPC_GPIO1->FIOSET1=0X01;//RS=1
for(i=0;msg1[i]!='\0';i++)
lcdwrt(msg1[i]);
LPC_GPIO1->FIOCLR1=0X01;
lcdwrt(0xc1);
LPC_GPIO1->FIOSET1=0X01;
for(i=0;msg2[i]!='\0';i++)
lcdwrt(msg2[i]);
}
void delay(unsigned long int x)
{
unsigned long int i;
for(i=0;i<x;i++);
}
void lcdwrt(unsigned char y)
{
LPC_GPIO2->FIOPIN0=y;
LPC_GPIO1->FIOSET1=0X04;
delay(0x5000);
LPC_GPIO1->FIOCLR1=0X04;
delay(0x500000);
}


