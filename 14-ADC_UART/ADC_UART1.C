#include<LPC17XX.h>
void delay(unsigned long int x);
void uart_int();
unsigned int val;
unsigned char conv[10];
int main ()
{
signed int i;
unsigned qot,rem,temp;
SystemInit();
LPC_SC->PCONP=0X0009008;
LPC_PINCON->PINSEL3=0XC0000000;
uart_int();
LPC_ADC->ADCR=0X00210220;
while(1)
{
while(((LPC_ADC->ADSTAT)&0X20)!=0X20);
val=(LPC_ADC->ADDR5>>4)&0X0FFF;

temp=val;
for(i=3;i>=0;i--)
 {qot=temp/0x0A;
  rem=temp%0x0A;
  conv[i]=rem+0x30;
  temp=qot;
 }
 conv[4]='\0';
 for(i=0;conv[i]!='\0';i++)
 {
LPC_UART0->THR=conv[i];
while(((LPC_UART0->LSR)&0X20)!=0X20);
 }
 delay(0x1000);
LPC_UART0->THR=0X0D;
while(((LPC_UART0->LSR)&0X20)!=0X20);
LPC_UART0->THR=0X0A;
while(((LPC_UART0->LSR)&0X20)!=0X20);
 delay(0x1000000);
 }
}
void uart_int()
{
LPC_PINCON->PINSEL0=0X00000050;
LPC_UART0->LCR=0X83;
LPC_UART0->DLM=0X00;
LPC_UART0->DLL=0X75;
LPC_UART0->FDR=0X10;
LPC_UART0->LCR=0X03;
}
void delay(unsigned long int x)
{
unsigned long int i;
for(i=0;i<x;i++);
}
