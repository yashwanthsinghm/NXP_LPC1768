#include <LPC17xx.H>
//#include "wbm1.h"
//#include "graphi.h"
#include <string.h>
void gprs_send();
void delay(unsigned long int dk);
void uart1_init(void);
void uart3_init(void);
void uart0_init(void);

//////////////////////////////////
unsigned  char msgp1[]="AT\r\n";
//unsigned  char msgp2[]="AT+CREG?\r\n";
unsigned  char msgp3[]="AT+CGATT?\r\n";
//unsigned  char msgp4[]="AT+CIPSHUT\r\n";
//unsigned  char msgp5[]="AT+CIPSTATUS\r\n";
//unsigned  char msgp6[]="AT+CIPMUX=0\r\n";
unsigned  char msgp7[]="AT+CSTT=\"CMNET\"\r\n";
unsigned  char msgp8[]="AT+CIICR\r\n";
unsigned  char msgp9[]="AT+CIFSR\r\n";
unsigned  char msgp10[]="AT+CIPSTATUS\r\n";
unsigned  char msgp11[]="AT+CIPSTART=\"TCP\",\"184.106.153.149\",\"80\"\r\n";
unsigned  char msgp12[]="AT+CIPSEND\r\n";
unsigned  char msgp13[]="GET /update?key=X10I93WFK3I2FHF5&field1=123\r\n";


unsigned  char msgp14[]="AT+CIPSHUT\r\n";
unsigned  char msgp15[]="AT+CIPCLOSE\r\n";


int main()
{
SystemInit ();
uart0_init();
uart3_init();


while(1)
{ gprs_send();          
}
}




void gprs_send()
{
        unsigned  char gp1=0;
		
        
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


void uart1_init(void)
{
        LPC_PINCON->PINSEL0|=0X40000000;
        LPC_PINCON->PINSEL1|=0X00000001;
        LPC_UART1->LCR=0X00000083;
        LPC_UART1->DLL=0X00000075;
        LPC_UART1->DLM=0X00000000;
        LPC_UART1->FDR=0X00000010;
        LPC_UART1->LCR=0X00000003;
        LPC_UART1->FCR=0X00000007;
}        
           
void delay(unsigned long int dk)
{
        unsigned long int di=0;
        for(di=0;di<dk;di++);                
}
        
