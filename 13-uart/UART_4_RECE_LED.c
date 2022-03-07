#include<LPC17xx.h>
void delay(unsigned long int x);
void uart_init();
int main(){
unsigned int val;
SystemInit();
LPC_SC->PCONP=0X00008008;//bit 15 for gpio,bit 3 fot uart0
LPC_GPIO0->FIOMASK1=0XFE;
LPC_GPIO0->FIODIR1=0X01;
uart_init();

while(1){
while(((LPC_UART0->LSR)&0X01)!=0X01)
{}
val=LPC_UART0->RBR;
 LPC_UART0->THR=val;
 while(((LPC_UART0->LSR)&0x20)!=0x20)
 {}
 if(val=='1')  {
 LPC_GPIO0->FIOSET1=0X01;}
 else
{ LPC_GPIO0->FIOCLR1=0X01; }
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