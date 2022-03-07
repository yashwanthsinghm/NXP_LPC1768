#include<lpc17xx.h>
#include<string.h>
void delay(unsigned long int x);
void uart_init();
void rece(unsigned char msg[])	;
int main()
{
unsigned char real[]="09008206B33E";
unsigned char text1[]="  correct\r\n";
unsigned char text2[]="  not correct\r\n";
unsigned char rec[20];
unsigned int i,y;
SystemInit();

LPC_SC->PCONP=0XFFFFFFFF;
uart_init();


while(1)
{
rece(rec);

for(i=0;i<12;i++)
{
if(real[i]==rec[i]){
y=0;				}
else{
y=1;
break;
}}
if(y==0)
{ 
for(i=0;text1[i]!='\0';i++)
{
LPC_UART0->THR=text1[i];
while(((LPC_UART0->LSR)&(0X20))!=(0X20))

{
}

 }
}
else
{


   for(i=0;text2[i]!='\0';i++)
{
LPC_UART0->THR=text2[i];
while(((LPC_UART0->LSR)&(0X20))!=(0X20))

{
}

}
}
}
		 

}








void uart_init()
{
LPC_PINCON->PINSEL0=0X40000050;
LPC_PINCON->PINSEL1=0X00000001;
LPC_UART1->LCR=0X83;
LPC_UART1->DLM=0X00;
LPC_UART1->DLL=0X75;
LPC_UART1->FDR=0X10;
LPC_UART1->LCR=0X03;


//LPC_PINCON->PINSEL0=0X00000050;
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
void rece(unsigned char msg[])
{
unsigned int i=0;
for(i=0;i<12;i++){
while(((LPC_UART1->LSR)&0X01)!=0X01);
msg[i]=LPC_UART1->RBR;
 LPC_UART0->THR=msg[i];
while(((LPC_UART0->LSR)&(0X20))!=(0X20));
}
}