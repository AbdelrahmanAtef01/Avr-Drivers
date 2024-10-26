#include"../../libraries/std_types.h"
#include "../../mcal/dio_driver/dio_int.h"
#include"7_segment_helper.h"

	int segment[10]={
			0b00000001,
			0b01001111,
			0b00010010,
			0b00000110,
			0b01001100,
			0b00100100,
			0b00100000,
			0b00001111,
			0b00000000,
			0b00000100,
	};

uint8_t SEGMENT_u8Display(uint8_t port_id,uint8_t num)
{
	uint8_t error_status = SEGMENT_u8Initialize(port_id);
	if(error_status==E_OK&&num>=0&&num<10)
	{
		error_status = DIO_u8SetPortValue(port_id,segment[num]);
	}else error_status=E_NOK;
	return error_status;
}

