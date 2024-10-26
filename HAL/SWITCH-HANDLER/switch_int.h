#ifndef HAL_SWITCH_DRIVER_SWITCH_INT_H_
#define HAL_SWITCH_DRIVER_SWITCH_INT_H_

/*
 * macros to be used in port_id param
 */
#define PORT_A (uint8_t)0
#define PORT_B (uint8_t)1
#define PORT_C (uint8_t)2
#define PORT_D (uint8_t)3

/*
 * macros to be used with pin_no param
 */
#define PIN_0 (uint8_t)0
#define PIN_1 (uint8_t)1
#define PIN_2 (uint8_t)2
#define PIN_3 (uint8_t)3
#define PIN_4 (uint8_t)4
#define PIN_5 (uint8_t)5
#define PIN_6 (uint8_t)6
#define PIN_7 (uint8_t)7

/*
 * macros to be used with value param
 */
#define PRESSED (uint8_t)1
#define NOTPRESSED (uint8_t)0

/*
 * macros to be used in pullup mode param
 */
#define Enabled (uint8_t)1
#define Disabled  (uint8_t)0

/*
 * error messages
 */
#define E_OK (uint8_t)0
#define E_NOK (uint8_t)1

uint8_t SWITCH_u8GetSwitch(uint8_t port_id,uint8_t switch_pin,uint8_t pull_up_enable,uint8_t * value);

uint8_t SWITCH_u8GetSwitchPort(uint8_t port_id,uint8_t pull_up_enable,uint8_t * value);

#endif
