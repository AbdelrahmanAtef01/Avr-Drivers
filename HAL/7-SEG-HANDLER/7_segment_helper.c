#include"../../libraries/std_types.h"
#include "../../mcal/dio_driver/dio_int.h"

uint8_t SEGMENT_u8Initialize(uint8_t port_id)
{
	uint8_t IsOutput;
	uint8_t error_status=DIO_u8IsPinOutPut(port_id,PIN_4,&IsOutput);
	if(error_status==E_OK){
		if(IsOutput==0) error_status = DIO_u8SetPortMode(port_id,255);
	}
	return error_status;
}
