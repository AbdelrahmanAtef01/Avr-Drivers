#ifndef LM35_CONFIGURATION_H_
#define LM35_CONFIGURATION_H_

#include "../../MCAL/ADC/ADC_Configuration.h"

// Configuration Options for LM35
#define LM35_ADC_CHANNEL  ADC_CHANNEL_2  // Define which ADC channel the LM35 is connected to

// LM35 temperature sensor constants
#define LM35_VOLTAGE_REF   5000    // Voltage reference in millivolts (usually 5V -> 5000 mV)
#define LM35_STEP_SIZE     (fint32_t)(LM35_VOLTAGE_REF / 1024.0) // ADC step size (for 10-bit resolution)

#endif /* LM35_CONFIGURATION_H_ */
