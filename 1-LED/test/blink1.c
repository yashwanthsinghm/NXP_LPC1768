#include<lpc21xx.h>
void delay(unsigned int x);


int main()
{	   
IO0DIR=0X000000FF;
while(1){
IO0PIN=IO0PIN^0X000000FF;
delay(0X50000);
}
	 
}



void delay(unsigned int x)
{
 unsigned int i;
 for(i=0;i<x;i++)
 {}
}
