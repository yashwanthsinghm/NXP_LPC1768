#include<LPC17XX.H>
void delay(unsigned long int x);
unsigned int VAL=0X00 ;
int main()
{ 
SystemInit();
LPC_SC->PCONP=0X00008000;
LPC_GPIO0->FIOMASK3=0XF7;  
//LPC_GPIO0->FIODIR3=0X00; //ON BOARD
LPC_GPIO0->FIODIR3=0X0F;   //simulation
LPC_GPIO0->FIOMASK2=0X9F;
LPC_GPIO0->FIODIR2=0X60;
VAL=0X00;
while(1){
VAL=LPC_GPIO0->FIOPIN3&0X08;
VAL=VAL>>3;
if(VAL==0X01)	 {
LPC_GPIO0->FIOPIN2=0X40;
delay(0x10000);	}
else{
LPC_GPIO0->FIOPIN2=0X20;
delay(0x10000);}
}
}
void delay(unsigned long int x)
{
unsigned long int i;
for(i=0;i<x;i++);
}