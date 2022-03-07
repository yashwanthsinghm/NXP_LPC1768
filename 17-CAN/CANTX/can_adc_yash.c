#include<LPC17xx.h>	//TRANS
#include <stdio.h>
void uart0_init(void);
void CAN_Init(void);
void CAN_ACC(void);
void looktable(void);
void delay(unsigned long int z);
void can_tx(unsigned long int id,unsigned char msg[4]);
unsigned char rx=0;
 void hexdecimal(unsigned int ha);
unsigned char con[4],as[4];
main()
{  
unsigned long int mv;
SystemInit();
LPC_SC->PCONP=0XFFFFFFFF;	

LPC_PINCON->PINSEL3=0XC0000000;
LPC_ADC->ADCR=0X00210320;
uart0_init();
CAN_Init();
CAN_ACC();
looktable();


while(1)
{ 	
   
while((LPC_ADC->ADSTAT&(0X00000020))!=(0X00000020))
{
}
mv=((LPC_ADC->ADDR5>>4)&(0X0FFF));



 hexdecimal(mv);
  

  } 
 }
 void hexdecimal(unsigned int ha)
  {
  unsigned char k;
  for(k=0;k<4;k++)
  {
  con[k]=ha%(0X0A);
  ha=ha/(0x0A);
  }

  as[0]=(con[3])+(0x30);
   as[1]=(con[2])+(0x30);
    as[2]=(con[1])+(0x30);
	 as[3]=(con[0])+(0x30);
     //for(k=0;k<4;k++)
	//can_tx(0x00000021,as[k]); 
	can_tx(0x00000021,as);
	delay(0x10000);
	 }
	m,

 void CAN_Init(void)

{
//LPC_SC->PCONP|=0x00002000;
LPC_SC->PCLKSEL0=0X00000000;
LPC_PINCON->PINSEL0|=0X00000005;
LPC_CAN1->MOD=0x00000001;
LPC_CAN1->CMR=0X00000000;
LPC_CAN1->GSR=0x00000000;
LPC_CAN1->IER=0x00000001;
LPC_CAN1->BTR=0X001C0007;
LPC_CAN1->MOD=0x00000000;	
}

void CAN_ACC(void)
{
LPC_CANAF->AFMR=0x00000001;
LPC_CANAF->SFF_sa=0x00000000;
LPC_CANAF->SFF_GRP_sa=0x00000000;
LPC_CANAF->EFF_sa=0x00000000;
LPC_CANAF->EFF_GRP_sa=0x00000008;
LPC_CANAF->ENDofTable=0x00000008;
LPC_CANAF->AFMR=0x00000000;	
}

void looktable(void) 
{
	LPC_CANAF->AFMR=0x00000001;
LPC_CANAF_RAM->mask[0]=0x00000012;
LPC_CANAF_RAM->mask[1]=0x00000014;
	LPC_CANAF->AFMR=0x00000000;
}

void delay(unsigned long int z)
{unsigned long int x;
for(x=0;x<z;x++);
}

void uart0_init(void)
{ //LPC_SC->PCONP=0X00000008;
  LPC_PINCON->PINSEL0|=0X00000050;
  LPC_SC->PCLKSEL0|=0X00000000;
  LPC_UART0->LCR=0X83;
  LPC_UART0->DLM=0X00;
  LPC_UART0->DLL=0X75;
  LPC_UART0->FDR=0X00000010;
  LPC_UART0->LCR=0X03;
	//LPC_UART0->FCR=0X06;
}
  
  void can_tx(unsigned long int id,unsigned char msg[4])
	{			unsigned long int msg1=0x00000000;
	unsigned int b;
			   for(b=0;b<4;b++)
			   {
			   msg1=msg1|(msg[b]<<8*b);
			   }
	while((LPC_CAN1->SR&0X00000004)!=0X00000004);
		LPC_CAN1->TFI1=0X80040000;
		LPC_CAN1->TID1=id;
		LPC_CAN1->TDA1=msg1;
		LPC_CAN1->CMR=0X21;
		
	}
	