#include<LPC17xx.h>
void delay(unsigned long int x);
void uart_init();
int main(){
unsigned int val,i;
unsigned int msg[3];
SystemInit();
LPC_SC->PCONP=0X00008008;//bit 15 for gpio,bit 3 fot uart0
uart_init();

while(1){
while(((LPC_UART0->LSR)&0X01)!=0X01)
{}
val=LPC_UART0->RBR;
if(val=='='){
for(i=0;i<3;i++)
{
while(((LPC_UART0->LSR)&0X01)!=0X01)
{}
msg[i]=LPC_UART0->RBR;
}
for(i=0;i<3;i++)
{
 LPC_UART0->THR=msg[i];
 while(((LPC_UART0->LSR)&0x20)!=0x20)
 {}
 }			 }
}

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