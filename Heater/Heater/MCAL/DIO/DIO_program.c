
#include "STDTYPES.h"
#include "BITMATH.h"

#include "DIO_interface.h"

void DIO_voidSetPinDirection(u8 copy_PortID, u8 copy_PinID, u8 copy_PinDirection){
	
	switch(copy_PinDirection){
		case DIO_PIN_OUTPUT:
		
		switch(copy_PortID){
			case DIO_PORTA_ID: SET_BIT(DIO_DDRA, copy_PinID);
			break;
			case DIO_PORTB_ID: SET_BIT(DIO_DDRB, copy_PinID);
			break;
			case DIO_PORTC_ID: SET_BIT(DIO_DDRC, copy_PinID);
			break;
			case DIO_PORTD_ID: SET_BIT(DIO_DDRD, copy_PinID);
			break;
		}
		break;
		
		case DIO_PIN_INPUT:
		
		switch(copy_PortID){
			case DIO_PORTA_ID: CLR_BIT(DIO_DDRA, copy_PinID);
			break;
			case DIO_PORTB_ID: CLR_BIT(DIO_DDRB, copy_PinID);
			break;
			case DIO_PORTC_ID: CLR_BIT(DIO_DDRC, copy_PinID);
			break;
			case DIO_PORTD_ID: CLR_BIT(DIO_DDRD, copy_PinID);
			break;
		}
		break;
	}
	
}

void DIO_voidSetPinValue(u8 copy_PortID, u8 copy_PinID, u8 copy_PinValue){
	
	switch(copy_PinValue){
		case DIO_PIN_LOW:
		
		switch(copy_PortID){
			case DIO_PORTA_ID: CLR_BIT(DIO_PORTA, copy_PinID);
			break;
			case DIO_PORTB_ID: CLR_BIT(DIO_PORTB, copy_PinID);
			break;
			case DIO_PORTC_ID: CLR_BIT(DIO_PORTC, copy_PinID);
			break;
			case DIO_PORTD_ID: CLR_BIT(DIO_PORTD, copy_PinID);
			break;
		}
		break;
		
		case DIO_PIN_HIGH:
		
		switch(copy_PortID){
			case DIO_PORTA_ID: SET_BIT(DIO_PORTA, copy_PinID);
			break;
			case DIO_PORTB_ID: SET_BIT(DIO_PORTB, copy_PinID);
			break;
			case DIO_PORTC_ID: SET_BIT(DIO_PORTC, copy_PinID);
			break;
			case DIO_PORTD_ID: SET_BIT(DIO_PORTD, copy_PinID);
			break;
		}
		break;
	}	

}

void DIO_voidTogglePinValue(u8 copy_PortID, u8 copy_PinID){
	
	switch(copy_PortID){
		case DIO_PORTA_ID: TOG_BIT(DIO_PORTA, copy_PinID);
		break;
		case DIO_PORTB_ID: TOG_BIT(DIO_PORTB, copy_PinID);
		break;
		case DIO_PORTC_ID: TOG_BIT(DIO_PORTC, copy_PinID);
		break;
		case DIO_PORTD_ID: TOG_BIT(DIO_PORTD, copy_PinID);
		break;
	}

} 

u8 DIO_u8GetPinValue(u8 copy_PortID, u8 copy_PinID){
	
    u8 local_u8PinValue;
	
	switch(copy_PortID){
		case DIO_PORTA_ID: local_u8PinValue = GET_BIT(DIO_PINA, copy_PinID);
		break;
		case DIO_PORTB_ID: local_u8PinValue = GET_BIT(DIO_PINB, copy_PinID);
		break;
		case DIO_PORTC_ID: local_u8PinValue = GET_BIT(DIO_PINC, copy_PinID);
		break;
		case DIO_PORTD_ID: local_u8PinValue = GET_BIT(DIO_PIND, copy_PinID);
		break;
	}	
	return local_u8PinValue;
}

void DIO_voidGetPinValue(u8 copy_PortID, u8 copy_PinID, u8* pu8PinValue){
	
	if((copy_PortID <= 3) && (copy_PinID <= 7) && (pu8PinValue != NULL)){
		
	    switch(copy_PortID){
		    case DIO_PORTA_ID: *pu8PinValue = GET_BIT(DIO_PINA, copy_PinID);
		    break;
		    case DIO_PORTB_ID: *pu8PinValue = GET_BIT(DIO_PINB, copy_PinID);
   	   	    break;
		    case DIO_PORTC_ID: *pu8PinValue = GET_BIT(DIO_PINC, copy_PinID);
		    break;
		    case DIO_PORTD_ID: *pu8PinValue = GET_BIT(DIO_PIND, copy_PinID);
		    break;
	}	
	}
	else{
		// return error state
	}
}

void DIO_voidActivePinInternalPUR(u8 copy_PortID, u8 copy_PinID){
	
	if((copy_PortID <= 3) && (copy_PinID <= 7)){
		
		switch(copy_PortID){
			case DIO_PORTA_ID: SET_BIT(DIO_PORTA, copy_PinID);
			break;
			case DIO_PORTB_ID: SET_BIT(DIO_PORTB, copy_PinID);
			break;
			case DIO_PORTC_ID: SET_BIT(DIO_PORTC, copy_PinID);
			break;
			case DIO_PORTD_ID: SET_BIT(DIO_PORTD, copy_PinID);
			break;
		}
	}
	else{
		// return error state
	}
} 

void DIO_voidSetPortDirection(u8 copy_u8PortId, u8 copy_u8PortDirection){
	
	switch(copy_u8PortDirection){
		case DIO_PORT_OUTPUT:
		
		switch(copy_u8PortId){
			case DIO_PORTA_ID:
			DIO_DDRA = 0xFF;
			break;
			case DIO_PORTB_ID:
			DIO_DDRB = 0xFF;
			break;
			case DIO_PORTC_ID:
			DIO_DDRC = 0xFF;
			break;
			case DIO_PORTD_ID:
			DIO_DDRD = 0xFF;
			break;
		}
		break;
		
		case DIO_PORT_INPUT:
		
		switch(copy_u8PortId){
			case DIO_PORTA_ID:
			DIO_DDRA = 0x00;
			break;
			case DIO_PORTB_ID:
			DIO_DDRB = 0x00;
			break;
			case DIO_PORTC_ID:
			DIO_DDRC = 0x00;
			break;
			case DIO_PORTD_ID:
			DIO_DDRD = 0x00;
			break;
		}
		break;
	}
}
/*
void DIO_voidSetPortValue(u8 copy_u8PortId, u8 copy_u8PortValue){
	
	switch(copy_u8PortValue){
		case DIO_PORT_LOW:
		
		switch(copy_u8PortId){
			case DIO_PORTA_ID: 
			DIO_PORTA = 0x00;
			break;
			case DIO_PORTB_ID:
			DIO_PORTB = 0x00;
			break;
			case DIO_PORTC_ID:
			DIO_PORTC = 0x00;
			break;
			case DIO_PORTD_ID:
			DIO_PORTD = 0x00;
			break;
		}
		break;
		
		case DIO_PORT_HIGH:
		
		switch(copy_u8PortId){
			case DIO_PORTA_ID:
			DIO_PORTA = 0xFF;
			break;
			case DIO_PORTB_ID:
			DIO_PORTB = 0xFF;
			break;
			case DIO_PORTC_ID:
			DIO_PORTC = 0xFF;
			break;
			case DIO_PORTD_ID:
			DIO_PORTD = 0xFF;
			break;
		}
		break;
	}
}
*/
void DIO_voidSetPortValue(u8 copy_u8PortId, u8 copy_u8PortValue){
	
	switch(copy_u8PortId){
		case DIO_PORTA_ID:
		DIO_PORTA = copy_u8PortValue;
		break;
		case DIO_PORTB_ID:
		DIO_PORTB = copy_u8PortValue;
		break;
		case DIO_PORTC_ID:
		DIO_PORTC = copy_u8PortValue;
		break;
		case DIO_PORTD_ID:
		DIO_PORTD = copy_u8PortValue;
		break;
	}
}

void DIO_voidTogglePortValue(u8 copy_u8PortId){
	
	switch(copy_u8PortId){
		case DIO_PORTA_ID:
		DIO_PORTA ^= 0xFF;
		break;
		case DIO_PORTB_ID:
		DIO_PORTB ^= 0xFF;
		break;
		case DIO_PORTC_ID:
		DIO_PORTC ^= 0xFF;
		break;
		case DIO_PORTD_ID:
		DIO_PORTD ^= 0xFF;
		break; 
	}
}

void DIO_voidGetPortValue(u8 copy_u8PortId, u8* pu8PortValue){
	if((pu8PortValue != NULL) && (copy_u8PortId <= 3)){
		
		switch(copy_u8PortId){
			case DIO_PORTA_ID:
			*pu8PortValue = DIO_PINA; 
			break;
			case DIO_PORTB_ID:
			*pu8PortValue = DIO_PINB;
			break;
			case DIO_PORTC_ID:
			*pu8PortValue = DIO_PINC;
			break;
			case DIO_PORTD_ID:
			*pu8PortValue = DIO_PIND;
			break;
		}
	}
}

void DIO_voidActivePortInternalPUR(u8 copy_PortID){
	
	switch(copy_PortID){
		case DIO_PORTA_ID:
		DIO_PORTA = 0xFF;
		break;
		case DIO_PORTB_ID:
		DIO_PORTB = 0xFF;
		break;
		case DIO_PORTC_ID:
		DIO_PORTC = 0xFF;
		break;
		case DIO_PORTD_ID:
		DIO_PORTD = 0xFF;
		break; 
		
	}
}