/*
 * LED0_Configuration.h
 *
 * Created: 1/13/2024 5:45:23 PM
 *  Author: karim
 */ 


#ifndef RELAY0_CONFIGURATION_H_
#define RELAY0_CONFIGURATION_H_

#include "../../../MCAL/CONFIG/CPU_Configuration.h"
#include "../../../MCAL/DIO/DIO_Interface.h"

//Renaming Port
#define RELAY0_PORT   DIO_PORTD
//Renaming Pin
#define RELAY0_PIN    DIO_PIN4
//Renaming State
#define RELAY0_OUTPUT DIO_OUTPUT
//Renaming Status
#define RELAY0_LOW    DIO_LOW
#define RELAY0_HIGH   DIO_HIGH




#endif /* LED0_CONFIGURATION_H_ */
