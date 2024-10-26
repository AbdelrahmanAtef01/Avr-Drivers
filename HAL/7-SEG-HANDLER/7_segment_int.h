#ifndef HAL_7_SEGMENT_DRIVER_7_SEGMENT_INT_H_
#define HAL_7_SEGMENT_DRIVER_7_SEGMENT_INT_H_

/*
 * macros to be used in port_id param
 */
#define PORT_A (uint8_t)0
#define PORT_B (uint8_t)1
#define PORT_C (uint8_t)2
#define PORT_D (uint8_t)3

/*
 * error messages
 */
#define E_OK (uint8_t)0
#define E_NOK (uint8_t)1

uint8_t SEGMENT_u8Display(uint8_t port_id,uint8_t num);


#endif
