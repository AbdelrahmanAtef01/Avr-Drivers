#include"../../libraries/std_types.h"
#include "../../mcal/dio_driver/dio_int.h"
#include "stepper_int.h"
#include "stepper_cfg.h"
#include "stepper_helper.h"

typedef struct{
	uint8_t port;
	uint8_t pin;
} MOTOR_PIN;

MOTOR_PIN stepper_pins_1[4] = {STEPPER_PIN_1,STEPPER_PIN_2,STEPPER_PIN_3,STEPPER_PIN_4};

void STEPPER_vidStepperInit()
{
	DIO_u8SetPinMode(stepper_pins_1[0].port,stepper_pins_1[0].pin,OUTPUT);
	DIO_u8SetPinMode(stepper_pins_1[1].port,stepper_pins_1[1].pin,OUTPUT);
	DIO_u8SetPinMode(stepper_pins_1[2].port,stepper_pins_1[2].pin,OUTPUT);
	DIO_u8SetPinMode(stepper_pins_1[3].port,stepper_pins_1[3].pin,OUTPUT);
	DIO_u8SetPinValue(stepper_pins_1[0].port,stepper_pins_1[0].pin,LOW);
	DIO_u8SetPinValue(stepper_pins_1[1].port,stepper_pins_1[1].pin,LOW);
	DIO_u8SetPinValue(stepper_pins_1[2].port,stepper_pins_1[2].pin,LOW);
	DIO_u8SetPinValue(stepper_pins_1[3].port,stepper_pins_1[3].pin,LOW);
}

void STEPPER_vidRightRotateCycles(uint8_t no_of_iterations)
{
	for(uint16_ i=0;i<(uint16_)(FULL_CYCLE_FULL_STEP_NO_OF_ROTATIONS*no_of_iterations);i++)
	{
		STEPPER_VidStepperFullCycleRight();
	}
}

void STEPPER_vidLeftRotateCycles(uint8_t no_of_iterations)
{
	for(uint16_ i=0;i<(uint16_)(FULL_CYCLE_FULL_STEP_NO_OF_ROTATIONS*no_of_iterations);i++)
	{
		STEPPER_VidStepperFullCycleLeft();
	}
}

void STEPPER_vidRightRotateAngle(uint16_ angle)
{
	uint16_ no_of_iterations= (uint16_)(angle/FULL_STEP_ANGLE);
	for(uint8_t i=0;i<no_of_iterations;i++)
		{
			STEPPER_VidStepperFullCycleRight();
		}
}

void STEPPER_vidLeftRotateAngle(uint16_ angle)
{
	uint16_ no_of_iterations= (uint16_)(angle/FULL_STEP_ANGLE);
	for(uint8_t i=0;i<no_of_iterations;i++)
		{
			STEPPER_VidStepperFullCycleLeft();
		}
}

void STEPPER_vidStepperOff()
{
	DIO_u8SetPinValue(stepper_pins_1[0].port,stepper_pins_1[0].pin,LOW);
	DIO_u8SetPinValue(stepper_pins_1[1].port,stepper_pins_1[1].pin,LOW);
	DIO_u8SetPinValue(stepper_pins_1[2].port,stepper_pins_1[2].pin,LOW);
	DIO_u8SetPinValue(stepper_pins_1[3].port,stepper_pins_1[3].pin,LOW);
}
