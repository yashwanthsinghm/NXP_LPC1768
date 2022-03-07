#include<lpc17xx.h>
void delay(unsigned long int x);
//void print1(unsigned char msg1[]);
void uart_init();


int main()
{  unsigned char gps[100];
   unsigned int i;
unsigned char val;
SystemInit();
LPC_SC->PCONP=0XFFFFFFFF;
uart_init();
while(1)
{
do
{
while(((LPC_UART3->LSR)&(0X01))!=(0X01))
{}
val=LPC_UART3->RBR;
}while(val!='$');


i=0;
do{

while(((LPC_UART3->LSR)&(0X01))!=(0X01))
{}
gps[i]=LPC_UART3->RBR;
LPC_UART0->THR=gps[i];
while(((LPC_UART0->LSR)&(0X20))!=(0X20))
{}

}while(gps[i++]!='\n');
LPC_UART0->THR='\n';
while(((LPC_UART0->LSR)&(0X20))!=(0X20))
{}
}}


void uart_init()
{
LPC_PINCON->PINSEL9=0X0F000000;
LPC_UART3->LCR=0X83;
LPC_UART3->DLM=0X00;
LPC_UART3->DLL=0X75;
LPC_UART3->FDR=0X10;
LPC_UART3->LCR=0X03;

LPC_PINCON->PINSEL0=0X00000050;
LPC_UART0->LCR=0X83;
LPC_UART0->DLM=0X00;
LPC_UART0->DLL=0X75;
LPC_UART0->FDR=0X10;
LPC_UART0->LCR=0X03;
}