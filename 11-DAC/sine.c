#include<LPC17xx.h>
#include<math.h>
int main()
{unsigned int val,i;
  SystemInit();
LPC_PINCON->PINSEL1=0X00200000;
while(1)
{
for(i=0;i<360;i++) {
val=0x1ff+(0x1ff*sin(3.14*i/180));
LPC_DAC->DACR=val<<6;
}
}
}