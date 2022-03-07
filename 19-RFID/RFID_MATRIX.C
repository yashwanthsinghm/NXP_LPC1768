#include<lpc17xx.h>
#include<string.h>
void delay(unsigned long int x);
void uart_init();
void rece(unsigned char msg[])	;
int main()
{
unsigned char real[10][14]={"09008206B33E","0900820A5CDD","09008206D459","09008206A825","09008206BE33","09008206C944","09008207109C","0900843444F3","090084336CD2","090082070589"};
unsigned char text1[]="  correct\r\n";
unsigned char text2[]="  not correct\r\n";
unsigned char text3[]="  card number is = ";
unsigned char rec[20];
unsigned int i,j,r,y;
SystemInit();

LPC_SC->PCONP=0X02008008;
uart_init();


while(1)
{

rece(rec);

i=0;
for(j=0;j<12;j++)
{
if(real[i][j]==rec[j]){
y=0;				}
else{
y=1;
i++;
j=0;
if(i==10)
{break;}
}
}
r=i;


if(y==0)
{ 
for(i=0;text1[i]!='\0';i++)
   {
LPC_UART0->THR=text1[i];
while(((LPC_UART0->LSR)&(0X20))!=(0X20))
{}
   }
for(i=0;text3[i]!='\0';i++)
   {
LPC_UART0->THR=text3[i];
while(((LPC_UART0->LSR)&(0X20))!=(0X20))
{
}
   }



   LPC_UART0->THR=(r+(0x30));
while(((LPC_UART0->LSR)&(0X20))!=(0X20))
{
}
   LPC_UART0->THR='\n';
while(((LPC_UART0->LSR)&(0X20))!=(0X20))
{
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
   LPC_UART0->THR=0x0D;
while(((LPC_UART0->LSR)&(0X20))!=(0X20))
{
}

}
}
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
void rece(unsigned char msg[])
{
unsigned int i=0;
   LPC_UART0->THR=0x0D;
while(((LPC_UART0->LSR)&(0X20))!=(0X20))
{
}
   LPC_UART0->THR='\n';
while(((LPC_UART0->LSR)&(0X20))!=(0X20))
{
}
for(i=0;i<12;i++){
while(((LPC_UART3->LSR)&0X01)!=0X01);
msg[i]=LPC_UART3->RBR;
 LPC_UART0->THR=msg[i];
while(((LPC_UART0->LSR)&(0X20))!=(0X20));
}
}