#ifndef HAL_KEY_PAD_HANDLER_KEY_PAD_INT_H_
#define HAL_KEY_PAD_HANDLER_KEY_PAD_INT_H_

/*
 * modes to define what to return when a switch is pressed
 */
#define  ARRAY_MODE    (uint8_t)0
#define  DEFINING_MODE (uint8_t)1

void KEYPAD_vidInit(void);
void KEYPAD_vidGetPressedSwitch(uint8_t * pressed_switch);

#endif
