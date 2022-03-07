#include <LPC17xx.h>
#include <string.h>
void gprs_send();
void uart1_init(void);
void uart3_init(void);
void uart0_init(void);
void delay(unsigned long int x);
void lcdwrt(unsigned char y );
unsigned int c[10];
unsigned  char msgp1[]="AT\r\n";
unsigned  char msgp3[]="AT+CGATT?\r\n";
unsigned  char msgp7[]="AT+CSTT=\"CMNET\"\r\n";
unsigned  char msgp8[]="AT+CIICR\r\n";
unsigned  char msgp9[]="AT+CIFSR\r\n";
unsigned  char msgp10[]="AT+CIPSTATUS\r\n";
unsigned  char msgp11[]="AT+CIPSTART=\"TCP\",\"184.106.153.149\",\"80\"\r\n";
unsigned  char msgp12[]="AT+CIPSEND\r\n";
unsigned  char msgp13[]="GET /update?key=X10I93WFK3I2FHF5&field1=";
unsigned char msgp16[]="\r\n";


unsigned  char msgp14[]="AT+CIPSHUT\r\n";
unsigned  char msgp15[]="AT+CIPCLOSE\r\n";

int main()
{
unsigned char msg1[]="digital value is ";
unsigned char cmd[5]={0X38,0X0E,0X06,0X01,0X80}; 
unsigned int i,VAL,temp,j,rem,qot;
signed int k;
SystemInit();
LPC_SC->PCONP=0X00009008;

LPC_GPIO0->FIOMASK1=0XF0; //11110000 LED PINS
LPC_GPIO0->FIODIR1=0X0F;  //00001111 OUTPUT PINS
LPC_GPIO1->FIOMASK1=0XF8;
LPC_GPIO1->FIODIR1=0X07;
LPC_GPIO2->FIOMASK0=0X00;
LPC_GPIO2->FIODIR0=0XFF;
LPC_PINCON->PINSEL3=0XC0000000;
uart0_init();
uart3_init();
LPC_ADC->ADCR=0X00210320;
LPC_GPIO1->FIOCLR1=0X02;
LPC_GPIO1->FIOCLR1=0X01;
		 for(i=0;i<5;i++)
		 lcdwrt(cmd[i]);
		 LPC_GPIO1->FIOSET1=0X01;
		 for(i=0;msg1[i]!='\0';i++)
		 lcdwrt(msg1[i]);
		 delay(0x5000);
while(1){
		 LPC_GPIO1->FIOCLR1=0X01;
		 lcdwrt(0x01);
		 lcdwrt(0xC0);
		 LPC_GPIO1->FIOSET1=0X01;
while((LPC_ADC->ADSTAT&0X00000020)!=0X00000020)
{}
VAL=(LPC_ADC->ADDR5>>4)&(0XFFF);
if(VAL>0X07FF)	{
LPC_GPIO0->FIOSET1=0X01;
delay(0x1000);}
else  {
LPC_GPIO0->FIOCLR1=0X01;
delay(0x1000);}
		 
		    temp=VAL;
            for(j=0;j<4;j++){
			rem=temp%0x0A;
			qot=temp/0x0A;
			temp=qot;
			c[j]=rem+(0x30);}
			for(k=3;k>-1;k--)
			lcdwrt(c[k]);
			gprs_send(); 
}}
void delay(unsigned long int x)
{
unsigned long int i;
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
void gprs_send()
{
        unsigned  char gp1=0;
		signed int k;
        
        gp1=0;
        while(msgp14[gp1]!='\0')
        {
                LPC_UART3->THR=msgp14[gp1++];
                while((LPC_UART3->LSR&0X20)!=0X20);
        }
        delay(0x5000000);
        
        gp1=0;
        while(msgp1[gp1]!='\0')
        {
                LPC_UART3->THR=msgp1[gp1++];
                while((LPC_UART3->LSR&0X20)!=0X20);
        }
        delay(0x5000000);
        


        gp1=0;
        while(msgp3[gp1]!='\0')
        {
                LPC_UART3->THR=msgp3[gp1++];
                while((LPC_UART3->LSR&0X20)!=0X20);
        }
                delay(0x5000000);
        
        gp1=0;
        while(msgp7[gp1]!='\0')
        {
                LPC_UART3->THR=msgp7[gp1++];
                while((LPC_UART3->LSR&0X20)!=0X20);
        }
        delay(0x5000000);
        
        gp1=0;
        while(msgp8[gp1]!='\0')
        {
                LPC_UART3->THR=msgp8[gp1++];
                while((LPC_UART3->LSR&0X20)!=0X20);
        }
        delay(0x5000000);
        
        gp1=0;
        while(msgp9[gp1]!='\0')
        {
                LPC_UART3->THR=msgp9[gp1++];
                while((LPC_UART3->LSR&0X20)!=0X20);
        }
        delay(0x5000000);
        
        gp1=0;
        while(msgp10[gp1]!='\0')
        {
                LPC_UART3->THR=msgp10[gp1++];
                while((LPC_UART3->LSR&0X20)!=0X20);
        }
        delay(0x5000000);
        
        gp1=0;
        while(msgp11[gp1]!='\0')
        {
                LPC_UART3->THR=msgp11[gp1++];
                while((LPC_UART3->LSR&0X20)!=0X20);
        }
        delay(0x5000000);
        
        gp1=0;
        while(msgp12[gp1]!='\0')
        {
                LPC_UART3->THR=msgp12[gp1++];
                while((LPC_UART3->LSR&0X20)!=0X20);
        }
        
        delay(0x500000);

        
        gp1=0;
        while(msgp13[gp1]!='\0')
        {
                LPC_UART3->THR=msgp13[gp1++];
                while((LPC_UART3->LSR&0X20)!=0X20);
        }
		 for(k=3;k>-1;k--)
		 {
                LPC_UART3->THR=c[k];
                while((LPC_UART3->LSR&0X20)!=0X20);
        }
		gp1=0;
        while(msgp16[gp1]!='\0')
        {
                LPC_UART3->THR=msgp16[gp1++];
                while((LPC_UART3->LSR&0X20)!=0X20);
        }
        
        
        LPC_UART3->THR=0x1A;
                while((LPC_UART3->LSR&0X20)!=0X20);
        delay(0x5000000);
        delay(0x5000000);
        delay(0x5000000);
        
        
        
}
void uart0_init(void)
{
        LPC_SC->PCONP|=0X00000000;
        LPC_SC->PCLKSEL0|=0X00000000;
        LPC_PINCON->PINSEL0|=0X00000050;
        LPC_UART0->LCR=0X00000083;
        LPC_UART0->DLL=0X00000075;
        LPC_UART0->DLM=0X00000000;
        LPC_UART0->FDR=0X00000010;
        LPC_UART0->LCR=0X00000003;
        LPC_UART0->FCR=0X00000007;
        
}


void uart3_init(void)
  {
        LPC_SC->PCONP|=0X02000000;
        LPC_SC->PCLKSEL1|=0X00000000;
        LPC_PINCON->PINSEL9|=0X0F000000;
        LPC_UART3->LCR=0X00000083;
        LPC_UART3->DLL=0X00000075;
        LPC_UART3->DLM=0X00000000;
        LPC_UART3->FDR=0X00000010;
        LPC_UART3->LCR=0X00000003;
        LPC_UART3->FCR=0X00000007;
  }
