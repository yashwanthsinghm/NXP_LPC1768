#include<LPC17xx.h>
void delay(unsigned long int x);
void uart_init();
int main(){
unsigned int val,i,flag;
unsigned char msg1[]="yashwanth";
unsigned char val1[10];
SystemInit();
LPC_SC->PCONP=0X00008008;//bit 15 for gpio,bit 3 fot uart0
LPC_GPIO0->FIOMASK1=0XFE;
LPC_GPIO0->FIODIR1=0X01;
uart_init();

while(1){
l1:while(((LPC_UART0->LSR)&0X01)!=0X01)
{}
val=LPC_UART0->RBR;
if(val!='$')
goto l1;
for(i=0;i<9;i++){
while(((LPC_UART0->LSR)&0X01)!=0X01)
{}
val1[i]=LPC_UART0->RBR;
 LPC_UART0->THR=val1[i];
 while(((LPC_UART0->LSR)&0x20)!=0x20)
 {}				  }
  val1[10]='\0' ;
 flag=1;
 for(i=0;i<10;i++){
 if(val1[i]==msg1[i])
 continue;
 else	{
 flag=0; 
 goto l2;} }
 l2 : if(flag==1)  {
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