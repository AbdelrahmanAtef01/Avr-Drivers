#include "USART_Configuration.h"
#include "USART_Interface.h"
#include "USART_Address.h"
#include "USART_Private.h"

void USART_Init(USART_BaudRate_t baud, USART_CharSize_t charSize, USART_Parity_t parity, USART_StopBits_t stopBits) {
	// Set baud rate
	UBRRL = (uint8_t)baud;
	UBRRH = (uint8_t)(baud >> 8);

	// Enable receiver and transmitter
	UCSRB = (1 << RXEN) | (1 << TXEN);

	// Set frame format: character size, parity, and stop bits
	UCSRC = (1 << URSEL) | (parity << 4) | (stopBits << 3) | (charSize << 1);
}

void USART_Transmit(uint8_t data) {
	// Wait until the transmit buffer is empty
	while (!(UCSRA & (1 << UDRE)));

	// Put data into the buffer, which sends it
	UDR = data;
}

uint8_t USART_Receive(void) {
	// Wait for data to be received
	while (!(UCSRA & (1 << RXC)));

	// Get and return received data from buffer
	return UDR;
}

void USART_TransmitString(uint8_t *str) {
	while ((*str)!='/0') {
		USART_Transmit((*str));
		str++;
		_delay_ms(30);
	}
	USART_Transmit('/0');
}
