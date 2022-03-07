   #include<LPC17xx.h>
   void delay(unsigned long int x);
   int main()
   {
   SystemInit();
   LPC_SC->PCONP=0X00008000;
   LPC_GPIO0->FIOMASK1=0XEF;
   LPC_GPIO0->FIODIR1=0X10;
   while(1){
   LPC_GPIO0->FIOSET1=0X10;
   delay(0x1000);
   LPC_GPIO0->FIOCLR1=0X10;
   delay(0x1000);
   }}
   void delay(unsigned long int x)
   {
   unsigned long int i;
   for(i=0;i<x;i++);
   }
