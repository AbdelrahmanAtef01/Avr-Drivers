#ifndef LM35_INTERFACE_H_
#define LM35_INTERFACE_H_

#include <stdint.h>

// Function to initialize the LM35 sensor
void LM35_Init(void);

// Function to read the temperature from the LM35 sensor (returns temperature in °C)
uint16_t LM35_ReadTemperature(void);

#endif /* LM35_INTERFACE_H_ */
