/***********************************************************************************
 ***********                      Created on: Sep 21, 2021            **************   
 ***********                      Author: Ahmed Tarek                 **************  
 ***********                      File Name : MDIO_Interface          **************  
 ***********                       V 1.0                              **************  
 ***********                 Description: Interface fo MDIO           **************  
 ***********                                                          **************  
 ***********                                                          **************  
 ***********************************************************************************/




#ifndef MDIO_Interface_H
#define MDIO_Interface_H

/* pin numbers to prevent numbers in function */
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

/* Port Numbers */
#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3

void MDIO_VoidSetPinDirection(u8 Copy_U8Port,u8 Copy_U8Pin,u8 Copy_U8Dir);
void MDIO_VoidSetPinValue(u8 Copy_U8Port,u8 Copy_U8Pin,u8 Copy_U8Val);
u8 MDIO_u8GetPinValue(u8 Copy_U8Port,u8 Copy_U8Pin);
void MDIO_VoidSetPortDirection(u8 Copy_U8Port,u8 Copy_U8Dir);
void MDIO_VoidSetPortValue(u8 Copy_U8Port,u8 Copy_U8Val);
void MDIO_VoidSetTogglePin(u8 Copy_U8Port,u8 Copy_U8Pin);
#endif
