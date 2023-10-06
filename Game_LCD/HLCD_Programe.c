/***********************************************************************************
 ***********                      Created on: Sep 24, 2021            **************   
 ***********                      Author: Ahmed Tarek                 **************  
 ***********                      File Name : HLCD_Program            **************  
 ***********                       V 1.0                              **************  
 ***********                 Description: Program for LCD             **************  
 ***********                                                          **************  
 ***********                                                          **************  
 ***********************************************************************************/









#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "HLCD_Private.h"
#include "MDIO_Interface.h"
#include "HLCD_CONFIG.h"
#include <avr/delay.h>

void HLCD_VoidSendChar(u8 Copy_U8Data)
{
	/*Set RS=1, to send data*/
	MDIO_VoidSetPinValue(Copy_RSPort,PIN0,1);
	/*Set Rw=0, to write */
	MDIO_VoidSetPinValue(Copy_RWPort,PIN1,0);
	/*Portc = data*/
	MDIO_VoidSetPortValue(PORTC, Copy_U8Data);
	/*En_seq*/
	MDIO_VoidSetPinValue(Copy_EnPort,PIN2,0);
	/* wait 1ms */
	_delay_ms(1);
	/*set High to enable*/
	MDIO_VoidSetPinValue(Copy_EnPort,PIN2,1);
	/* wait 1ms */
	_delay_ms(1);
	/*set low to enable*/
	MDIO_VoidSetPinValue(Copy_EnPort,PIN2,0);
	/* wait 1ms */
	_delay_ms(2);
}
void HLCD_VoidSendCommand(u8 Copy_U8Command)
{
	/*Set RS=1, to send data*/
	MDIO_VoidSetPinValue(Copy_RSPort,PIN0,0);
	/*Set Rw=0, to write */
	MDIO_VoidSetPinValue(Copy_RWPort,PIN1,0);
	/*Portc = data*/
	MDIO_VoidSetPortValue(Copy_DataPort, Copy_U8Command);
	/*En_seq*/
	MDIO_VoidSetPinValue(Copy_EnPort,PIN2,0);
	/* wait 1ms */
	_delay_ms(1);
	/*set High to enable*/
	MDIO_VoidSetPinValue(Copy_EnPort,PIN2,1);
	/* wait 1ms */
	_delay_ms(1);
	/*set low to enable*/
	MDIO_VoidSetPinValue(Copy_EnPort,PIN2,0);
	/* wait 1ms */
	_delay_ms(2);
}
void HLCD_VoidInit(void)
{
	/*power on*/
	MDIO_VoidSetPortDirection(Copy_DataPort,0b11111111);
	MDIO_VoidSetPinDirection(Copy_RSPort,PIN0,1);
	MDIO_VoidSetPinDirection(Copy_RWPort,PIN1,1);
	MDIO_VoidSetPinDirection(Copy_EnPort,PIN2,1);
	/*wait 40ms*/
	_delay_ms(40);
	
	/*Function set 8bit mode ... 2 line mode ... 5*8 mode */
	
	HLCD_VoidSendCommand(0b00111000);
	
	/*wait for more than 1ms*/
 _delay_ms(1);

/*on display..on cursor...on bluting*/

HLCD_VoidSendCommand(0b00001100);

/*wait more than 1.53*/

_delay_ms(1);

/*display clear*/

HLCD_VoidSendCommand(0b00000001);
	
	/*delay more than 1.53ms*/
	
	_delay_ms(2);
	
}
void HLCD_VoidStringChar (char* str)
{
	u8 i=0;
	
	while (str[i]!=('\0'))
	{
		HLCD_VoidSendChar(str[i]);
		i++;
	}
	
}
void HLCD_VoidSetPostion(u8 Copy_U8Row,u8 Copy_U8Col)
{
	
	if (Copy_U8Row == 0)
	{
		HLCD_VoidSendCommand(Copy_U8Col+128);
	}
	else if (Copy_U8Row == 1)
	{
		HLCD_VoidSendCommand(Copy_U8Col+128+64);
	}
	
	
}
void HLCD_SendNumber(u32 num)
{
	if (0==num)
	{
		HLCD_VoidSendChar(0+48);
	}
	else
	{
	u32 Loc_U32Rev=1;
	while (num>0)
	{
		Loc_U32Rev=(Loc_U32Rev*10)+num%10;
		num/=10;
	}
	while(Loc_U32Rev>1)
	{
	   u32 n=Loc_U32Rev%10;
	   HLCD_VoidSendChar(n+48);
	   Loc_U32Rev=Loc_U32Rev/10;
	}
	}
}
void HLCD_DrawCharStand(void)
{

	HLCD_VoidSendCommand(64);
	/*char Standup */

	HLCD_VoidSendChar(0b11111);
	HLCD_VoidSendChar(0b01010);
	HLCD_VoidSendChar(0b01110);
	HLCD_VoidSendChar(0b11111);
	HLCD_VoidSendChar(0b00100);
	HLCD_VoidSendChar(0b01110);
	HLCD_VoidSendChar(0b01010);
	HLCD_VoidSendChar(0b01010);

	HLCD_VoidSendCommand(128+64+3);
	HLCD_VoidSendChar(0);
}
void HLCD_DrawCharMoveRight(u8 r,u8 c)
{

	HLCD_VoidSendCommand(64+8);

	/*char move right */
	HLCD_VoidSendChar(0b11111);
	HLCD_VoidSendChar(0b01010);
	HLCD_VoidSendChar(0b01110);
	HLCD_VoidSendChar(0b11111);
	HLCD_VoidSendChar(0b00100);
	HLCD_VoidSendChar(0b01110);
	HLCD_VoidSendChar(0b01010);
	HLCD_VoidSendChar(0b01001);

	HLCD_VoidSendCommand(128+r+c);
	HLCD_VoidSendChar(1);
}
void HLCD_DrawCharMoveLeft(void)
{

	HLCD_VoidSendCommand(64+8+8);

	/*char move right */
	HLCD_VoidSendChar(0b11111);
	HLCD_VoidSendChar(0b01010);
	HLCD_VoidSendChar(0b01110);
	HLCD_VoidSendChar(0b11111);
	HLCD_VoidSendChar(0b00100);
	HLCD_VoidSendChar(0b01110);
	HLCD_VoidSendChar(0b01010);
	HLCD_VoidSendChar(0b10010);

	HLCD_VoidSendCommand(128);
	HLCD_VoidSendChar(2);
}
void HLCD_DrawCharJump(u8 r,u8 c)
{

	HLCD_VoidSendCommand(64+8+8+8);

	/*char Jump */
	HLCD_VoidSendChar(0b11111);
    HLCD_VoidSendChar(0b01010);
	HLCD_VoidSendChar(0b01110);
	HLCD_VoidSendChar(0b11111);
	HLCD_VoidSendChar(0b00100);
	HLCD_VoidSendChar(0b01110);
	HLCD_VoidSendChar(0b11011);
	HLCD_VoidSendChar(0b00000);

	HLCD_VoidSendCommand(128+r+c);
	HLCD_VoidSendChar(3);
}
void HLCD_DrawCharTree1(u8 i)
{
	
	HLCD_VoidSendCommand(64+8+8+8+8);

	HLCD_VoidSendChar(0b10101);
	HLCD_VoidSendChar(0b10101);
	HLCD_VoidSendChar(0b10101);
	HLCD_VoidSendChar(0b11111);
	HLCD_VoidSendChar(0b01110);
	HLCD_VoidSendChar(0b01110);
	HLCD_VoidSendChar(0b01110);
	HLCD_VoidSendChar(0b01110);
	HLCD_VoidSendCommand(128+64+i);
	HLCD_VoidSendChar(4);
}
void HLCD_DrawCharTree2(u8 i)
{

	HLCD_VoidSendCommand(64+8+8+8+8+8);

	HLCD_VoidSendChar(0b10101);
	HLCD_VoidSendChar(0b10101);
	HLCD_VoidSendChar(0b10101);
	HLCD_VoidSendChar(0b11111);
	HLCD_VoidSendChar(0b01110);
	HLCD_VoidSendChar(0b01110);
	HLCD_VoidSendChar(0b01110);
	HLCD_VoidSendChar(0b01110);
	HLCD_VoidSendCommand(128+64+i);
	HLCD_VoidSendChar(5);
}
void HLCD_DrawCharTree3(u8 i)
{

	HLCD_VoidSendCommand(64+8+8+8+8+8+8);

	HLCD_VoidSendChar(0b10101);
	HLCD_VoidSendChar(0b10101);
	HLCD_VoidSendChar(0b10101);
	HLCD_VoidSendChar(0b11111);
	HLCD_VoidSendChar(0b01110);
	HLCD_VoidSendChar(0b01110);
	HLCD_VoidSendChar(0b01110);
	HLCD_VoidSendChar(0b01110);
	HLCD_VoidSendCommand(128+64+i);
	HLCD_VoidSendChar(6);
}
