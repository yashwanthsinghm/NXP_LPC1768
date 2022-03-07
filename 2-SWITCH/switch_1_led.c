#include<LPC17XX.H>
void delay(unsigned long int x);
unsigned int VAL=0X00 ;
int main()
{ 
SystemInit();
LPC_SC->PCONP=0X00008000;
LPC_GPIO0->FIOMASK3=0XF7;  //SIMULATION
LPC_GPIO0->FIODIR3=0X00; //ON BOARD
//LPC_GPIO0->FIODIR3=0X0F;
LPC_GPIO1->FIOMASK3=0XEF;
LPC_GPIO1->FIODIR3=0X10;
VAL=0X00;
while(1){
VAL=LPC_GPIO0->FIOPIN3&0X08;
VAL=VAL>>3;
if(VAL==0X01)	 {
LPC_GPIO1->FIOSET3=0X10;
delay(0x10000);	}
else{
LPC_GPIO1->FIOCLR3=0X10;
delay(0x10000);}
}
}
void delay(unsigned long int x)
{
unsigned long int i;
for(i=0;i<x;i++);
}