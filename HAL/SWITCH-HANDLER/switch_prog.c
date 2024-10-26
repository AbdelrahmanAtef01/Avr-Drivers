#include"../../libraries/std_types.h"
#include "../../mcal/dio_driver/dio_int.h"
#include"switch_helper.h"

uint8_t SWITCH_u8GetSwitch(uint8_t port_id,uint8_t switch_pin,uint8_t pullup_enable,uint8_t * value)
{
	uint8_t error_status=SWITCH_u8InitializeSwitch(port_id,switch_pin);
	if(error_status==E_OK)
	{
		error_status = DIO_u8SetPullUpMode(port_id,switch_pin,pullup_enable);
		if(error_status==E_OK)error_status=DIO_u8GetPinValue(port_id,switch_pin,value);
	}
	return error_status;
}

uint8_t SWITCH_u8GetSwitchPort(uint8_t port_id,uint8_t pullup_enable,uint8_t * value)
{
	uint8_t error_status=SWITCH_u8InitializeSwitchPort(port_id);
	if(error_status==E_OK)
	{
		error_status = DIO_u8SetPortPullUpMode(port_id,pullup_enable);
		if(error_status==E_OK)error_status=DIO_u8GetPortValue(port_id,value);
	}
	return error_status;
}
