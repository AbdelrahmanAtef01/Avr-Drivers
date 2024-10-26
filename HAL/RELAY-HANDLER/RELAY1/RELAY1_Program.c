#include "RELAY1_Interface.h"

void RELAY1_Initialization(void)
{
	DIO_SetPinDirection(RELAY1_PORT, RELAY1_PIN, RELAY1_OUTPUT);
}
void RELAY1_ON (void)
{
	DIO_SetPinValue(RELAY1_PORT, RELAY1_PIN, RELAY1_HIGH);
}
void RELAY1_OFF(void)
{
	DIO_SetPinValue(RELAY1_PORT, RELAY1_PIN, RELAY1_LOW);
}