/*
 * main.c
 *
 *  Created on: Sep 29, 2021
 *      Author: Eng Ahmed Tarek
 */
#include "STD_TYPES.h"
#include "HLCD_Interface.h"
#include "HKPD_Interface.h"
#include "MDIO_Interface.h"
#include "avr/delay.h"




void main (void)
{


u8 i,x,y,h=1;
	while (h)
	{


		for (i=16,y=25,x=21;((i>0)||(y>0)||(x>0))&&(h==1);i--,x--,y--)
		{
			HLCD_VoidInit();
			HKPD_Init();


			HLCD_DrawCharStand();

			if(Get_PressKey()==1)
			{
				HLCD_VoidSendCommand(0x01);
				HLCD_DrawCharJump(0,3);
				_delay_ms(80);
			}

			if(i>1)
			{
	HLCD_DrawCharTree1(i);
	_delay_ms(80);
			}

			if(x>1)
			{
	HLCD_DrawCharTree2(x);
	_delay_ms(80);
			}

if (y>1)
{
	HLCD_DrawCharTree3(y);
	_delay_ms(80);
}

 if (1==y)
 {
	 i=16;
	 x=21;
	 y=25;

 }

 if((3==i)&&(Get_PressKey()!=1))
 			 			{
	 HLCD_VoidSendCommand(0x01);
 				HLCD_VoidSetPostion(0,5);
 				HLCD_VoidStringChar("Game Over");
_delay_ms(100);
h=0;
 			 			}
 else if((3==y)&&(Get_PressKey()!=1))
 						 			{
 				HLCD_VoidSendCommand(0x01);
 				HLCD_VoidSetPostion(0,5);
 				HLCD_VoidStringChar("Game Over");
 				_delay_ms(100);
 				h=0;
 						 			}
 else if((3==x)&&(Get_PressKey()!=1))
 						 			{
 				HLCD_VoidSendCommand(0x01);
 				HLCD_VoidSetPostion(0,5);
 				HLCD_VoidStringChar("Game Over");
 				_delay_ms(100);
 				h=0;
 						 			}
 if (2==y)
 {
	 for(u8 c=3;c<=16;c++)
	 {
	HLCD_VoidSendCommand(0x01);
	 HLCD_DrawCharMoveRight(1,c);
	 _delay_ms(200);
 }
	 i=0;
	 x=0;
	 h=0;
	 y=0;
	 HLCD_VoidSendCommand(0x01);
	 HLCD_VoidStringChar("Winner Winner");

 }
		}



	}

    }






/*HLCD_DrawCharStand();
	_delay_ms(500);
	HLCD_VoidSendCommand(0b00000001);
	HLCD_DrawCharMoveRight();
	_delay_ms(500);
	HLCD_VoidSendCommand(0b00000001);
	HLCD_DrawCharMoveLeft();
	_delay_ms(500);
	HLCD_VoidSendCommand(0b00000001);
	HLCD_DrawCharJump();
	_delay_ms(500);
	HLCD_VoidSendCommand(0b00000001);*/
