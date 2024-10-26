
#include "RELAY0_Interface.h"

void RELAY0_Initialization(void)
{
	DIO_SetPinDirection(RELAY0_PORT, RELAY0_PIN, RELAY0_OUTPUT);
}
void RELAY0_ON (void)
{
	DIO_SetPinValue(RELAY0_PORT, RELAY0_PIN, RELAY0_HIGH);
}
void RELAY0_OFF(void)
{
	DIO_SetPinValue(RELAY0_PORT, RELAY0_PIN, RELAY0_LOW);
}
