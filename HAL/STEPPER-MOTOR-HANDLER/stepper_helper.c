#include"../../libraries/std_types.h"
#include "../../mcal/dio_driver/dio_int.h"
#include "util/delay.h"
#include "stepper_cfg.h"


typedef struct{
	uint8_t port;
	uint8_t pin;
} MOTOR_PIN;

MOTOR_PIN stepper_pins[4] = {STEPPER_PIN_1,STEPPER_PIN_2,STEPPER_PIN_3,STEPPER_PIN_4};

void STEPPER_VidStepperFullStep(uint8_t coil)
{
	DIO_u8SetPinValue(stepper_pins[coil].port,stepper_pins[coil].pin,HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(stepper_pins[coil].port,stepper_pins[coil].pin,LOW);
}

void STEPPER_VidStepperHalfStep(uint8_t coil_1,uint8_t coil_2)
{
	DIO_u8SetPinValue(stepper_pins[coil_1].port,stepper_pins[coil_1].pin,HIGH);
	DIO_u8SetPinValue(stepper_pins[coil_1].port,stepper_pins[coil_1].pin,HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(stepper_pins[coil_2].port,stepper_pins[coil_2].pin,LOW);
	DIO_u8SetPinValue(stepper_pins[coil_2].port,stepper_pins[coil_2].pin,LOW);
}

void STEPPER_VidStepperFullCycleRight()
{
	STEPPER_VidStepperFullStep(0);
	STEPPER_VidStepperFullStep(1);
	STEPPER_VidStepperFullStep(2);
	STEPPER_VidStepperFullStep(3);

}

void STEPPER_VidStepperFullCycleLeft()
{
	STEPPER_VidStepperFullStep(3);
	STEPPER_VidStepperFullStep(2);
	STEPPER_VidStepperFullStep(1);
	STEPPER_VidStepperFullStep(0);

}

void STEPPER_VidStepperFullCycleHalfStepRight()
{
	STEPPER_VidStepperFullStep(0);
	STEPPER_VidStepperHalfStep(0,1);
	STEPPER_VidStepperFullStep(1);
	STEPPER_VidStepperHalfStep(1,2);
	STEPPER_VidStepperFullStep(2);
	STEPPER_VidStepperHalfStep(2,3);
	STEPPER_VidStepperFullStep(3);
}

void STEPPER_VidStepperFullCycleHalfStepLeft()
{
	STEPPER_VidStepperFullStep(3);
	STEPPER_VidStepperHalfStep(3,2);
	STEPPER_VidStepperFullStep(2);
	STEPPER_VidStepperHalfStep(2,1);
	STEPPER_VidStepperFullStep(1);
	STEPPER_VidStepperHalfStep(1,0);
	STEPPER_VidStepperFullStep(0);
}
