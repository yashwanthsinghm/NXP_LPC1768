   #include<LPC17xx.h>
   void delay(unsigned long int x);
   int main()
   {  unsigned int j;
   unsigned int array[10]={0x10,0x20,0x50,0x60,0x40,0xF0,0x30,0xA0,0Xc0};
   SystemInit();
   LPC_SC->PCONP=0X00008000;
   LPC_GPIO0->FIOMASK1=0X0F;
   LPC_GPIO0->FIODIR1=0XF0;
   for(j=0;j<10;j++){
   LPC_GPIO0->FIOSET1=array[j];
   delay(0x100000);
   LPC_GPIO0->FIOCLR1=array[j];
   delay(0x100000);
   }
   while(1){}  }
   void delay(unsigned long int x)
   {
   unsigned long int i;
   for(i=0;i<x;i++);
   }
