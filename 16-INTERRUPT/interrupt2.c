#include<LPC17XX.h>
unsigned char msg[]="no interrupt ";
unsigned char msg1[]="INTERRUpt is enabled";
unsigned char cmd[5]={0X38,0X0E,0X06,0X01,0X80};
void delay(unsigned long int x);
void lcdwrt(unsigned char y );



void EINT2_IRQHandler(void)
{
unsigned int i,j;
LPC_SC->EXTINT=0X00000004;
LPC_GPIO1->FIOSET3=0X10;
NVIC_DisableIRQ(EINT2_IRQn);
LPC_GPIO1->FIOCLR1=0X02;
LPC_GPIO1->FIOCLR1=0X01;
for(j=0;j<5;j++)
lcdwrt(cmd[j]);
LPC_GPIO1->FIOSET1=0X01;
for(j=0;msg1[j]!='\0';j++)
lcdwrt(msg1[j]);
for(i=0;i<10;i++){
	LPC_GPIO0->FIOSET2=0X20;
	delay(0x500000);
	LPC_GPIO0->FIOCLR2=0X20;
	delay(0x500000);}
LPC_GPIO1->FIOCLR3=0X10;	
NVIC_EnableIRQ(EINT2_IRQn);
}
int main(){
	unsigned int j;
SystemInit();
LPC_GPIO1->FIOMASK3=0XEF;
LPC_GPIO1->FIODIR3=0X10;
LPC_GPIO2->FIOMASK2=0XDF;
LPC_GPIO2->FIODIR2=0X20;
LPC_GPIO0->FIOMASK1=0XF0;
LPC_GPIO0->FIODIR1=0X0F;
LPC_GPIO1->FIOMASK1=0XF8;
LPC_GPIO1->FIODIR1=0X07;
LPC_GPIO2->FIOMASK0=0X00;
LPC_GPIO2->FIODIR0=0XFF;
LPC_GPIO1->FIOCLR1=0X02;
LPC_PINCON->PINSEL4=0X01000000;
LPC_SC->EXTMODE=0X00000004;
LPC_SC->EXTPOLAR=0X00000000;
NVIC_EnableIRQ(EINT2_IRQn);
while(1){
LPC_GPIO0->FIOPIN1=0X0F;
delay(0x100000);
LPC_GPIO0->FIOCLR1=0X0F;
delay(0x100000);
LPC_GPIO1->FIOCLR1=0X02;
LPC_GPIO1->FIOCLR1=0X01;
for(j=0;j<5;j++)
lcdwrt(cmd[j]);
LPC_GPIO1->FIOSET1=0X01;
for(j=0;msg[j]!='\0';j++)
lcdwrt(msg[j]);
}
}
void delay(unsigned long int x){
unsigned int i;
for(i=0;i<x;i++);
}
void lcdwrt(unsigned char y )
{
	LPC_GPIO2->FIOPIN0=y;
	LPC_GPIO1->FIOSET1=0X04;
	delay(0x50000);
	LPC_GPIO1->FIOCLR1=0X04;
	delay(0x50000);
}



