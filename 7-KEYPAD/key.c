#include<LPC17XX.H>
void delay(unsigned long int x);
void lcdwrt(unsigned char y);
unsigned char msg1[]="keypressed =";
unsigned char cmd[5]={0x38,0x0E,0X06,0X01,0X80};
unsigned char key[4][4]={'1','2','3','4','5','6','7','8','9','0','a','b','c','d','e','f'};
unsigned int col,row;
int main(){
unsigned int i;
SystemInit();
LPC_GPIO1->FIOMASK1=0XF8;
LPC_GPIO1->FIODIR1=0X07;
LPC_GPIO2->FIOMASK0=0X00;
LPC_GPIO2->FIODIR0=0XFF;
LPC_GPIO0->FIOMASK0=0X0F;
LPC_GPIO0->FIODIR0=0X00;
LPC_GPIO1->FIOMASK3=0XF0;
LPC_GPIO1->FIODIR3=0X0F;
LPC_GPIO1->FIOCLR1=0X03;
for(i=0;i<5;i++)
lcdwrt(cmd[i]);
LPC_GPIO1->FIOSET1=0X01;
for(i=0;msg1[i]!='\0';i++)
lcdwrt(msg1[i]);
while(1)
{
LPC_GPIO1->FIOSET3=0X00;
do
{
col=LPC_GPIO0->FIOPIN0;
col=col&0xF0;
}while(col==0xF0);
 while(1)
 {
  LPC_GPIO1->FIOPIN3=0X0E;
  col=LPC_GPIO0->FIOPIN0;
  col=0xF0&col;
  if(col!=0xF0)
  {
  row=0;
  break;
  }
  LPC_GPIO1->FIOPIN3=0X0D;
  col=LPC_GPIO0->FIOPIN0;
  col=0xF0&col;
  if(col!=0xF0)
  {
  row=1;
  break;
  }
   LPC_GPIO1->FIOPIN3=0X0B;
  col=LPC_GPIO0->FIOPIN0;
  col=0xF0&col;
  if(col!=0xF0)
  {
  row=2;
  break;
  }
   LPC_GPIO1->FIOPIN3=0X07;
  col=LPC_GPIO0->FIOPIN0;
  col=0xF0&col;
  if(col!=0xF0)
  {
  row=3;
  break;
  }
 }
LPC_GPIO1->FIOCLR1=0X01;
lcdwrt(0xc0);
LPC_GPIO1->FIOSET1=0X01;
if(col==0x0E)
lcdwrt(key[row][0]);
else if(col==0x0D)
lcdwrt(key[row][1]);
else if(col==0x0B)
lcdwrt(key[row][2]);
else 
lcdwrt(key[row][3]);
}
}
void delay(unsigned long int x)
{
unsigned long int i;
for(i=0;i<x;i++);
}
void lcdwrt(unsigned char y)
{
LPC_GPIO2->FIOPIN0=y;
LPC_GPIO1->FIOSET1=0X04;
delay(0x500);
LPC_GPIO1->FIOCLR1=0X04;
delay(0x5000);
}