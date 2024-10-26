#include"../../libraries/std_types.h"
#include "../../mcal/dio_driver/dio_int.h"
#include "motor_int.h"
#include "motor_cfg.h"

typedef struct{
	uint8_t port;
	uint8_t pin;
} MOTOR_PIN;

MOTOR_PIN motor_pins[2] = {MOTOR_LEFT,MOTOR_RIGHT};

void MOTOR_vidMotorInit()
{
	DIO_u8SetPinMode(motor_pins[0].port,motor_pins[0].pin,OUTPUT);
	DIO_u8SetPinMode(motor_pins[1].port,motor_pins[1].pin,OUTPUT);
}

void MOTOR_vidRightRotate()
{
	DIO_u8SetPinValue(motor_pins[0].port,motor_pins[0].pin,LOW);
	DIO_u8SetPinValue(motor_pins[0].port,motor_pins[0].pin,HIGH);
}

void MOTOR_vidLeftRotate()
{
	DIO_u8SetPinValue(motor_pins[0].port,motor_pins[0].pin,LOW);
	DIO_u8SetPinValue(motor_pins[0].port,motor_pins[0].pin,HIGH);
}

void MOTOR_vidMotorOff()
{
	DIO_u8SetPinValue(motor_pins[0].port,motor_pins[0].pin,LOW);
	DIO_u8SetPinValue(motor_pins[0].port,motor_pins[0].pin,LOW);
}
