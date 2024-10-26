#include"../../libraries/std_types.h"
#include "../../mcal/dio_driver/dio_int.h"

uint8_t SWITCH_u8InitializeSwitch(uint8_t port_id,uint8_t switch_pin)
{
	uint8_t IsInput;
	uint8_t error_status=DIO_u8IsPinOutPut(port_id,switch_pin,&IsInput);
	if(error_status==E_OK){
		if(IsInput==1) error_status = DIO_u8SetPinMode(port_id,switch_pin,INPUT);
	}
	return error_status;
}

uint8_t SWITCH_u8InitializeSwitchPort(uint8_t port_id)
{
	uint8_t IsInput;
	uint8_t error_status=DIO_u8IsPinOutPut(port_id,PIN_4,&IsInput);
	if(error_status==E_OK){
		if(IsInput==1) error_status = DIO_u8SetPortMode(port_id,INPUT);
	}
	return error_status;
}
