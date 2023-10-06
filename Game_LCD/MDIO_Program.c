/***********************************************************************************
 ***********                      Created on: Sep 21, 2021            **************   
 ***********                      Author: Ahmed Tarek                 **************  
 ***********                      File Name : MDIO_Program            **************  
 ***********                       V 1.0                              **************  
 ***********                 Description: Program fo MDIO             **************  
 ***********                                                          **************  
 ***********                                                          **************  
 ***********************************************************************************/








#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MDIO_Private.h"
#include "MDIO_Interface.h"


void MDIO_VoidSetPinDirection(u8 Copy_U8Port,u8 Copy_U8Pin,u8 Copy_U8Dir)
{
	
	if(1==Copy_U8Dir)
	{
		switch (Copy_U8Port)
		{
			case PORTA: SET_BIT(DDRA_REG,Copy_U8Pin); break;
			case PORTB: SET_BIT(DDRB_REG,Copy_U8Pin); break;
			case PORTC: SET_BIT(DDRC_REG,Copy_U8Pin); break;
			case PORTD: SET_BIT(DDRD_REG,Copy_U8Pin); break;
			default: /* do nothing */;
		}
		
	}
	else if (0==Copy_U8Dir)
	
	{
		switch (Copy_U8Port)
		{
			case PORTA: CLR_BIT(DDRA_REG,Copy_U8Pin); break;
			case PORTB: CLR_BIT(DDRB_REG,Copy_U8Pin); break;
			case PORTC: CLR_BIT(DDRC_REG,Copy_U8Pin); break;
			case PORTD: CLR_BIT(DDRD_REG,Copy_U8Pin); break;
			default: /* do nothing */;
		}
	}
	else 
	{
		
		/* Do NOthing*/
	}
}


void MDIO_VoidSetPinValue(u8 Copy_U8Port,u8 Copy_U8Pin,u8 Copy_U8Val)
{
 if(0==Copy_U8Val)
 {
		switch (Copy_U8Port)
		{
			case PORTA: CLR_BIT(PORTA_REG,Copy_U8Pin); break;
			case PORTB: CLR_BIT(PORTB_REG,Copy_U8Pin); break;
			case PORTC: CLR_BIT(PORTC_REG,Copy_U8Pin); break;
			case PORTD: CLR_BIT(PORTD_REG,Copy_U8Pin); break;
			default: /* do nothing */;
		}
 }
 else if(1==Copy_U8Val)
 	{
 		switch(Copy_U8Port)
 		{
 			case PORTA:SET_BIT(PORTA_REG,Copy_U8Pin) ; break;
 			case PORTB:SET_BIT(PORTB_REG,Copy_U8Pin) ; break;
 			case PORTC:SET_BIT(PORTC_REG,Copy_U8Pin) ; break;
 			case PORTD:SET_BIT(PORTD_REG,Copy_U8Pin) ; break;
 			default: /* do nothing */;
 		}
 	}
     else
 	{
 		/* do nothing */
 	}
		
	
	
}
u8 MDIO_u8GetPinValue(u8 Copy_U8Port,u8 Copy_U8Pin)
{
	u8 LOC_U8RetValue ;
	switch (Copy_U8Port)
	{
		
		case PORTA: LOC_U8RetValue=GET_BIT(PINA_REG,Copy_U8Pin); break;
		case PORTB: LOC_U8RetValue=GET_BIT(PINB_REG,Copy_U8Pin); break;
		case PORTC: LOC_U8RetValue=GET_BIT(PINC_REG,Copy_U8Pin); break;
		case PORTD: LOC_U8RetValue=GET_BIT(PIND_REG,Copy_U8Pin); break;
		default : /* Do NOthing*/;
	}
	return LOC_U8RetValue;
}
void MDIO_VoidSetPortDirection(u8 Copy_U8Port,u8 Copy_U8Dir)
{
	switch(Copy_U8Port)
	{
	case PORTA: DDRA_REG = Copy_U8Dir; break;
	case PORTB: DDRB_REG = Copy_U8Dir; break;
	case PORTC: DDRC_REG = Copy_U8Dir; break;
	case PORTD: DDRD_REG = Copy_U8Dir; break;
	default : /* Do NOthing*/;
}
}

void MDIO_VoidSetPortValue(u8 Copy_U8Port,u8 Copy_U8Val)
{
	switch(Copy_U8Port)
	{
	case PORTA: PORTA_REG = Copy_U8Val; break;
	case PORTB: PORTB_REG = Copy_U8Val; break;
	case PORTC: PORTC_REG = Copy_U8Val; break;
	case PORTD: PORTD_REG = Copy_U8Val; break;
	default : /* Do NOthing*/;
}
}
void MDIO_VoidSetTogglePin(u8 Copy_U8Port,u8 Copy_U8Pin)
{
	switch (Copy_U8Port)
		{
			case PORTA: TOGGLE_BIT(PORTA_REG,Copy_U8Pin); break;
			case PORTB: TOGGLE_BIT(PORTB_REG,Copy_U8Pin); break;
			case PORTC: TOGGLE_BIT(PORTC_REG,Copy_U8Pin); break;
			case PORTD: TOGGLE_BIT(PORTD_REG,Copy_U8Pin); break;
			default : /* Do NOthing*/;
		}
}
