/***********************************************************************************
 ***********                      Created on: Sep 25, 2021            **************   
 ***********                      Author: Ahmed Tarek                 **************  
 ***********                      File Name : HKPD_Program            **************  
 ***********                       V 1.0                              **************  
 ***********                 Description: Program For HKPD            **************  
 ***********                                                          **************  
 ***********                                                          **************  
 ***********************************************************************************/








#include "STD_TYPES.h"
#include "MDIO_Private.h"
#include "MDIO_Interface.h"
#include "HKPD_CONFIG.h"
#include "avr/delay.h"


void HKPD_Init(void)
{
	MDIO_VoidSetPortDirection(Copy_HKPDPort,0b11110000);
	MDIO_VoidSetPortValue(Copy_HKPDPort,0b00001111);
}

u8 Get_PressKey(void)
{
	u8 prs_key=50;
	for (u8 c=0;c<4;c++)
	{
		MDIO_VoidSetPinValue(Copy_HKPDPort,4+c,0);
		for (u8 r=0;r<4;r++)
		{
			u8 x=MDIO_u8GetPinValue(Copy_HKPDPort,r);
			if (0==x)
			{
				prs_key=(4*r)+c+1;
			}
//			while (0==MDIO_u8GetPinValue(Copy_HKPDPort,r))
//			{
//
//			}
			_delay_ms(8);
		}
		MDIO_VoidSetPinValue(Copy_HKPDPort,4+c,1);
	}
	
	return prs_key;
	
	
}
