#include<LPC17xx.h>
void delay(unsigned long int x);
void uart_init();
void trans(unsigned char msg[])	;
void print1(unsigned char msg1[]);

int main(){
unsigned char gps[100];
unsigned char time[20];
unsigned char lat[20];
unsigned char lon[20];
unsigned char next[]="\r\n";
unsigned char val,itr=0;

unsigned char msg2[]="AT\r\n";
unsigned char msg3[]="AT+CREG?\r\n";
unsigned char msg4[]="AT+CMGF=1\r\n";
unsigned char msg5[]="AT+CMGS=\"8105842536\"\r\n";
unsigned int i,j;
SystemInit();
LPC_SC->PCONP=0XFFFFFFFF;//bit 15 for gpio,bit 3 fot uart0

uart_init();

 while(itr<3)
 {


do
{
while(((LPC_UART1->LSR)&(0X01))!=(0X01))
{}
val=LPC_UART1->RBR;
}while(val!='$');


i=0;
while(gps[i-1]!='\n')
{
while(((LPC_UART1->LSR)&(0X01))!=(0X01))
{}
gps[i]=LPC_UART1->RBR;
i++;
}
if(gps[2]=='R')
{ print1(gps);
j=0;
for(i=6;i<16;i++) {
time[j]=gps[i];
j++;			   }
time[j]='\n';




print1(time);
print1(next);
j=0;
for(i=19;i<30;i++) {
lat[j]=gps[i];
j++;}
lat[j]='\r';
j++;
lat[j]='\n';			   

print1(lat);
print1(next);
j=0;
for(i=31;i<41;i++) {
lon[j]=gps[i];
j++;			   }


lon[j]='\r';
j++;
lon[j]='\n';



}
trans(msg2);

delay(0x20000);

					 
trans(msg3);
delay(0x20000);


trans(msg4);
delay(0x20000);


trans(msg5);

delay(0x20000);

trans(lat);
delay(0x20000);

LPC_UART3->THR=0x1A;
while(((LPC_UART3->LSR)&0X20)!=0X20)
{}
delay(0x200000);

trans(lon);
delay(0x20000);

LPC_UART3->THR=0x1A;
while(((LPC_UART3->LSR)&0X20)!=0X20)
{}
delay(0x20000);

itr++;
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

LPC_PINCON->PINSEL0=0X40000050;
LPC_UART0->LCR=0X83;
LPC_UART0->DLM=0X00;
LPC_UART0->DLL=0X75;
LPC_UART0->FDR=0X10;
LPC_UART0->LCR=0X03;



LPC_PINCON->PINSEL1=0X00000001;
LPC_UART1->LCR=0X83;
LPC_UART1->DLM=0X00;
LPC_UART1->DLL=0X75;
LPC_UART1->FDR=0X10;
LPC_UART1->LCR=0X03;
}
void delay(unsigned long int x)
{
unsigned long int i;
for(i=0;i<x;i++);
}
void trans(unsigned char msg[])
{
unsigned int i;
for(i=0;msg[i]!='\n';i++)
{
LPC_UART3->THR=msg[i];
while(((LPC_UART3->LSR)&0X20)!=0X20)
{}					  
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

