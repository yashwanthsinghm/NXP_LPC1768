#include<LPC17xx.h>
void delay(unsigned long int x);
void spi_init();
void spi_read();
void uart_init();
unsigned char rx1=0x00,rx2=0x00,rx3=0x00;
unsigned short int rx4=0x0000;
unsigned char con[5];
int main(){

signed int i;
unsigned int qot,rem;
SystemInit();
LPC_SC->PCONP=0X00008008;
LPC_GPIO0->FIOMASK2=0X9F;
LPC_GPIO0->FIODIR2=0X6F;
spi_init();
uart_init();
while(1)
{
spi_read();
//rx4=(rx2<<8)|rx3;
rx4=0x2ac;
//rx4=rx4/13;
if(rx4>0x30)
{
 LPC_GPIO0->FIOSET2=0X40;
 LPC_GPIO0->FIOSET2=0X20;
delay(0x500);
LPC_GPIO0->FIOCLR2=0X20;
}
else
{
LPC_GPIO0->FIOCLR2=0X40;
LPC_GPIO0->FIOCLR2=0X20;
}
for(i=3;i>0;i--)
{
rem=rx4%0x0A;
qot=rx4/0x0A;
rx4=qot;
con[i]=rem+0x30	;
}
con[4]='\0';
for(i=0;i<4;i++)
{
LPC_UART0->THR=con[i];
while((LPC_UART0->LSR&0X20)!=0X20);
}
LPC_UART0->THR=0X0D;
while((LPC_UART0->LSR&0X20)!=0X20);
LPC_UART0->THR=0X0A;
while((LPC_UART0->LSR&0X20)!=0X20);
}}
void delay(unsigned long int x)
{
unsigned long int i;
for(i=0;i<x;i++);
}
void spi_init()
{
LPC_PINCON->PINSEL0=0XC0000000;
LPC_PINCON->PINSEL1=0X0000003C;
LPC_GPIO0->FIODIR2=0X00000001;
LPC_GPIO0->FIOSET2=0X00000001;
LPC_SPI->SPCCR=0X000000FE;
LPC_SPI->SPCR=0X00000824;
}
void spi_read()
{
delay(0x50000);
LPC_GPIO0->FIOCLR2=0X01;
delay(0x5000);
LPC_SPI->SPDR=0X01;
while((LPC_SPI->SPSR&0X80)!=0X80);
rx1=LPC_SPI->SPDR;
LPC_SPI->SPDR=0XA0;
while((LPC_SPI->SPSR&0X80)!=0X80);
rx2=LPC_SPI->SPDR;
LPC_SPI->SPDR=0X00;
while((LPC_SPI->SPSR&0X80)!=0X80);
rx3=LPC_SPI->SPDR;
delay(0x5000);
LPC_GPIO0->FIOSET2=0X01;
delay(0x5000);
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




















