#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

#include "USART_Configuration.h"

// Function prototypes for USART
void USART_Init(USART_BaudRate_t baud, USART_CharSize_t charSize, USART_Parity_t parity, USART_StopBits_t stopBits);
void USART_Transmit(uint8_t data);
uint8_t USART_Receive(void);
void USART_TransmitString(uint8_t *str);

#endif /* USART_INTERFACE_H_ */

