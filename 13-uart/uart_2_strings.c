#include<LPC17xx.h>
void delay(unsigned long int x);
void uart_init();
int main(){
unsigned int i;
unsigned char msg1[]="yashwanth singh";
unsigned char msg2[]="pesit bangalore south campus is great ";
SystemInit();
LPC_SC->PCONP=0X00008008;//bit 15 for gpio,bit 3 fot uart0
uart_init();
for(i=0;msg1[i]!='\0';i++){
LPC_UART0->THR=msg1[i];
while(((LPC_UART0->LSR)&0X20)!=0X20)
{}					 
delay(0x1000); }
LPC_UART0->THR=0x0D;
while(((LPC_UART0->LSR)&0X20)!=0X20)
{}
LPC_UART0->THR=0X0A;
while(((LPC_UART0->LSR)&0X20)!=0X20);
for(i=0;msg2[i]!='\0';i++){
LPC_UART0->THR=msg2[i];
while(((LPC_UART0->LSR)&0X20)!=0X20)
{}}
while(1){}

}
void uart_init()
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