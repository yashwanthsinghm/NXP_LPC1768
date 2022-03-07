#include<lpc17xx.h>
void delay(unsigned long int x);
void print1(unsigned char msg1[]);
void uart_init();


main()
{  unsigned char gps[100];
unsigned char time[200];
unsigned char lat[200];
unsigned char lon[200];
unsigned char next[]="\n";
unsigned char msg[]="invalid\n";
unsigned char frame[]="GPRMC";
unsigned int i,j,n,y;
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
while(gps[i-1]!='\n')
{
while(((LPC_UART3->LSR)&(0X01))!=(0X01))
{}
gps[i]=LPC_UART3->RBR;
i++;
}
if(gps[2]=='R')
{
print1(gps);
//y=0;
//n=1;
//i=0;
// 
// do{
//
//    if(n==1)
//      {
//       j=0;
//    do
//      {
//        time[j]=gps[i];
//        j++; 
//       }while(gps[i++]!=',');
//      n++;
//      i++;
//       if(gps[i]=='A')
//        {
//        n++;
//        i++;
//        }
//        else
//       goto l1;
//          }
//
//
//else if(n==3)
//{
//j=0;
//do
//{
// lat[j]=gps[i];
// j++;
//}while(gps[i++]!=',');
//n++;
//i++;
//if(gps[i]=='N')
//{
//n++;
//i++;
//}
//else
//goto l1;
//}
//
//
//
//
//else if(n==5)
//{
//j=0;
//do
//{
// lon[j]=gps[i];
// j++;
// }while(gps[i++]!=',');
//n++;
//i++;
//if(gps[i]=='E')
//{
//n++;
//i++;
//}
//else
//goto l1;
//}
//
// 
//}while(gps[i++]!='\n');
//print1(next);
//print1(time);
//print1(next);
//print1(lat);
//print1(next);
//print1(lon);
//}
//
//
//
//l1 : //




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
void delay(unsigned long int x)
{
unsigned long int i;
for(i=0;i<x;i++);
}