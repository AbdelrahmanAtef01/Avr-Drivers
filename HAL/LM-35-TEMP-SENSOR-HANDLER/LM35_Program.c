#include "LM35_Interface.h"
#include "../../MCAL/ADC/ADC_Interface.h"
#include "LM35_Configuration.h"

void LM35_Init(void) {
	// Initialize the ADC to be able to read from the LM35 sensor's channel
	ADC_Init();
}

uint16_t LM35_ReadTemperature(void) {
	// Read ADC value from the configured channel
	uint16_t adc_value = ADC_Read(LM35_ADC_CHANNEL);
	
	// Convert the ADC value to millivolts
	fint32_t millivolts = (fint32_t)adc_value * LM35_STEP_SIZE;
	
	// Convert millivolts to temperature in Celsius
	fint32_t temperature = millivolts / 10.0;  // LM35 gives 10mV per degree Celsius
	
	// Return the temperature value
	return (uint16_t)temperature;
}

