#include<lpc17xx.h>
void delay(unsigned long int x);
void print1(unsigned char msg1[]);
void uart_init();


main()
{  
unsigned char gps[100];
unsigned char time[20];
unsigned char lat[20];
unsigned char lon[20];
unsigned char next[]="\r\n";
unsigned char msg[]="invalid\n";
unsigned char frame[]="GPRMC";
unsigned int i,j,n,y;
unsigned char val;
SystemInit();
LPC_SC->PCONP=0XFFFFFFFF;
uart_init();
while(1)
{   LPC_UART0->THR=0x0D;
   while(((LPC_UART0->LSR)&(0X20))!=(0X20))
   {}
do
{
while(((LPC_UART3->LSR)&(0X01))!=(0X01))
{}
val=LPC_UART3->RBR;
}while(val!='$');


i=0;
while(gps[i-1]!='\n')
{
while(((LPC_UART3->LSR)&(0X01))!=(0X01))
{}
gps[i]=LPC_UART3->RBR;
i++;
}
if(gps[2]=='R')
{ print1(gps);
j=0;
for(i=6;i<16;i++) {
time[j]=gps[i];
j++;			   }
 //time[j]='\n';
 LPC_UART0->THR=0x0D;
   while(((LPC_UART0->LSR)&(0X20))!=(0X20))
   {}
print1(time);
print1(next);
j=0;
for(i=19;i<30;i++) {
lat[j]=gps[i];
j++;			   }
//lat[j]='\n';

 LPC_UART0->THR=0x0D;
   while(((LPC_UART0->LSR)&(0X20))!=(0X20))
   {}
print1(lat);
print1(next);
j=0;
for(i=31;i<41;i++) {
lon[j]=gps[i];
j++;			   }
//lon[j]='\n';
 LPC_UART0->THR=0x0D;
   while(((LPC_UART0->LSR)&(0X20))!=(0X20))
   {}
print1(lon);
print1(next);
}






}
}



void print1(unsigned char msg1[])
{
unsigned int i;
 for(i=0;msg1[i]!='\0';i++)
   {  LPC_UART0->THR=msg1[i];
   while(((LPC_UART0->LSR)&(0X20))!=(0X20))
   {}
   }
}
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