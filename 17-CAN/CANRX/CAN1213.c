#include<LPC17xx.h>	  //rec
void uart0_init(void);
void CAN_Init(void);
void CAN_ACC(void);
void looktable(void); 
void delay(unsigned long int z);
void can_tx(unsigned long int id,unsigned char msg);
void can_rx(void);
unsigned char rx=0;
int main()
{
SystemInit ();	
uart0_init();
CAN_Init();
CAN_ACC();
looktable(); 	
	while(1);
	
	
}
void CAN_Init(void)

{
LPC_SC->PCONP|=0x00002000;
LPC_SC->PCLKSEL0|=0X00000000;
LPC_PINCON->PINSEL0|=0X00000005;
LPC_CAN1->MOD=0x00000001;
LPC_CAN1->CMR=0X00000000;
LPC_CAN1->GSR=0x00000000;
LPC_CAN1->IER=0x00000001;
LPC_CAN1->BTR=0X001C0007;
LPC_CAN1->MOD=0x00000000;	
	NVIC_EnableIRQ(CAN_IRQn);
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
LPC_CANAF_RAM->mask[0]=0x00000020;	//20
LPC_CANAF_RAM->mask[1]=0x00000021;		//21
	LPC_CANAF->AFMR=0x00000000;
}

void delay(unsigned long int z)
{unsigned long int x;
for(x=0;x<z;x++);
}

void uart0_init(void)
{ LPC_SC->PCONP|=0X00000000;
  LPC_PINCON->PINSEL0|=0X00000050;
  LPC_SC->PCLKSEL0|=0X00000000;
  LPC_UART0->LCR=0X83;
  LPC_UART0->DLM=0X00;
  LPC_UART0->DLL=0X75;
  LPC_UART0->FDR=0X00000010;
  LPC_UART0->LCR=0X03;
	//LPC_UART0->FCR=0X06;
}
  
 /* void can_tx(unsigned long int id,unsigned char msg)
	{
	while((LPC_CAN1->SR&0X00000004)!=0X00000004);
		LPC_CAN1->TFI1=0X80040000;// (7 - 0)PRIORITY IS 00,(15 - 8) R,(19 - 16) DLC 1 Byte,(29 - 29) R, (30) RTR=0, (31) 29bit identifier
		LPC_CAN1->TID1=id;
		LPC_CAN1->TDA1=msg;
		LPC_CAN1->CMR=0X21;// (0th bit) request for transmission based on priority), (5th bit) tx buffer1 is selected for transmission
		
	}
 	*/
void 	CAN_IRQHandler(void)
{
can_rx();



}	
void can_rx(void)
{
unsigned long int CA = 0,CB = 0, CC = 0, CD = 0,CE1=0;
unsigned int i;
	CA = LPC_CAN1->RFS;
	CA = CA & 0x40000000;//DLC value identifies the number of data bytes requested to be sent using the same Identifier.(RTR of CAN1RFS checks whether it is data frame or remote frame)
	if (CA == 0x00000000)//if it is data frame
	{
		CB = LPC_CAN1->RFS;
		CB = CB & 0x000003FF;// ID Index of CAN1RFS
		if(CB == 0x00000001) //If the BP bit (below) is 0, checks whether the Acceptance Filter matched with the received Identifier.
		{
			CC = LPC_CAN1->RFS;
			CC = CC & 0x000F0000; // tells  the how many number of data bytes available in the CANRDA and CANRDB(DLC)
			if(CC == 0x00040000)//may be checking the status of one byte selected in of frame register
			{
				CD = LPC_CAN1->RDA;
				CD = CD & 0xFFFFFFFF;// Because only four byte is selected in CAN Frame.
				for(i=0;i<4;i++)
				{  CE1=CD&(0X000000FF);
				  LPC_UART0->THR=CE1;
				  while(((LPC_UART0->LSR)&(0X20))!=(0X20))
				  {
				  }
				  CD=CD>>8;
				 
				  }
				   LPC_UART0->THR='\r';
				  while(((LPC_UART0->LSR)&(0X20))!=(0X20))
				  {
				  }
				  LPC_UART0->THR='\n';
				  while(((LPC_UART0->LSR)&(0X20))!=(0X20))
				  {
				  }
				  
				  }
		}
		LPC_CAN1->CMR = 0X04;//The information in the Receive Buffer is released.
				
	}
	
	
	
	
}