#include<LPC17XX.h>
void spi_read();
void spi_init();
void delay(unsigned long int x);
unsigned short int rx4=0x0000;
unsigned int rx1=0x00,rx2=0x00,rx3=0x00;
int main(){
SystemInit();
LPC_SC->PCONP=0X00008000;
LPC_GPIO0->FIOMASK2=0X9F;
LPC_GPIO0->FIODIR2=0X60;
spi_init();
while(1){
spi_read();
rx4=(rx2<<8)|rx3;
rx4=rx4&0xFFF;
if(rx4>0x1FF)
{
LPC_GPIO0->FIOSET2=0X40;
LPC_GPIO0->FIOSET2=0X20;
delay(0x1000);
LPC_GPIO0->FIOCLR2=0X20;
delay(0x1000);
}else {
LPC_GPIO0->FIOCLR2=0X40;
LPC_GPIO0->FIOCLR2=0X20;
}		 }
}
void delay(unsigned long int x)
{unsigned long int i;
for(i=0;i<x;i++);
}
void spi_init()
{
LPC_PINCON->PINSEL0=0XC0000000;
LPC_PINCON->PINSEL1=0X0000003C;
LPC_GPIO0->FIODIR2=0X01;
LPC_GPIO0->FIOSET2=0X01;
LPC_SPI->SPCCR=0X000000FE;
LPC_SPI->SPCR=0X00000824;
}
void spi_read(){
delay(0x5000);
LPC_GPIO0->FIOCLR2=0X01;
LPC_SPI->SPDR=0X01;
while((LPC_SPI->SPSR&0X80)!=0X80)
{}
rx1=LPC_SPI->SPDR;
LPC_SPI->SPDR=0XA0;
while((LPC_SPI->SPSR&0X80)!=0X80)
{}
rx2=LPC_SPI->SPDR;
LPC_SPI->SPDR=0X00;
while((LPC_SPI->SPSR&0X80)!=0X80)
{}
rx3=LPC_SPI->SPDR;
delay(0x5000);
LPC_GPIO0->FIOSET2=0X01;
delay(0x5000);
}