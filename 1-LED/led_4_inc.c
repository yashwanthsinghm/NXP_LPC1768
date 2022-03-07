   #include<LPC17xx.h>
   void delay(unsigned long int x);
     unsigned int x;
   int main()
   {  unsigned int j;
  
   SystemInit();
   LPC_SC->PCONP=0X00008000;
   LPC_GPIO0->FIOMASK1=0X0F;
   LPC_GPIO0->FIODIR1=0XF0;
   x=0;
   for(j=0;j<10;j++){
   LPC_GPIO0->FIOSET1=x<<4;
   delay(0x10000);
   LPC_GPIO0->FIOCLR1=x<<4;
   delay(0x10000);
   x=x+1;
   }  }
   void delay(unsigned long int x)
   {
   unsigned long int i;
   for(i=0;i<x;i++);
   }
