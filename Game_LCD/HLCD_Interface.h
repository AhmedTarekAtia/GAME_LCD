/***********************************************************************************
 ***********                      Created on: Sep 24, 2021            **************   
 ***********                      Author: Ahmed Tarek                 **************  
 ***********                      File Name : HLCD_INTERFACE          **************  
 ***********                       V 1.0                              **************  
 ***********                 Description: INTERFACE for LCD           **************  
 ***********                                                          **************  
 ***********                                                          **************  
 ***********************************************************************************/






#ifndef HLCD_INTERFACE_H
#define HLCD_INTERFACE_H

void HLCD_VoidSendChar(u8 Copy_U8Data);

void HLCD_VoidSendCommand(u8 Copy_U8Command);

void HLCD_VoidStringChar (char* str);

void HLCD_VoidSetPostion(u8 Copy_U8Row,u8 Copy_U8Col);

void HLCD_VoidShiftingLeftLcd();

void HLCD_VoidShiftingRightLcd();

void HLCD_VoidInit(void);

void HLCD_SendNumber(u32 num);

void HLCD_DrawCharStand(void);

void HLCD_DrawCharMoveLeft(void);

void HLCD_DrawCharTree1(u8 i);

void HLCD_DrawCharJump(u8 r,u8 c);

void HLCD_DrawCharMoveRight(u8 r,u8 c);

void HLCD_DrawCharTree3(u8 i);

void HLCD_DrawCharTree2(u8 i);

#endif
