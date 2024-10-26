#ifndef HAL_KEY_PAD_HANDLER_KEY_PAD_CFG_H_
#define HAL_KEY_PAD_HANDLER_KEY_PAD_CFG_H_

/*
 * THIS DRIVER SUPPORTS UP TO 10*10 KEYPAD
 */


/*
 * define which mode you want to set the key pad on
 * choose array mode to return the position of the switch the array
 * choose defining mode to be able to define a value for each button and return it
 */

#define  KEYPAD_MODE  ARRAY_MODE

/*
 * define here the number of columns and rows in your keypad
 */

#define COLUMNS_NUMBER  (uint8_t)4
#define ROWS_NUMBER  (uint8_t)4


/*
 * enter each pin as following and leave the unused pins on unused
 * #define pin name   {port,pin_number}
 */

#define COL_1_PIN	{PORT_D,PIN_3}
#define COL_2_PIN	{PORT_D,PIN_2}
#define COL_3_PIN	{PORT_D,PIN_1}
#define COL_4_PIN	{PORT_D,PIN_0}
#define COL_5_PIN	{PORT_A,PIN_3}
#define COL_6_PIN	{PORT_A,PIN_3}
#define COL_7_PIN	{PORT_A,PIN_3}
#define COL_8_PIN	{PORT_A,PIN_3}
#define COL_9_PIN	{PORT_A,PIN_3}
#define COL_10_PIN	{PORT_A,PIN_3}

#define ROW_1_PIN	{PORT_D,PIN_4}
#define ROW_2_PIN	{PORT_D,PIN_5}
#define ROW_3_PIN	{PORT_D,PIN_6}
#define ROW_4_PIN	{PORT_D,PIN_7}
#define ROW_5_PIN	{PORT_A,PIN_3}
#define ROW_6_PIN	{PORT_A,PIN_3}
#define ROW_7_PIN	{PORT_A,PIN_3}
#define ROW_8_PIN	{PORT_A,PIN_3}
#define ROW_9_PIN	{PORT_A,PIN_3}
#define ROW_10_PIN	{PORT_A,PIN_3}


/*
 * here you can define a value for each button
 */

#define BUTTON_0_0_ '2'
#define BUTTON_0_1_ '3'
#define BUTTON_0_2_ '4'
#define BUTTON_0_3_ '5'
#define BUTTON_0_4_ '6'
#define BUTTON_0_5_ '1'
#define BUTTON_0_6_ '1'
#define BUTTON_0_7_ '1'
#define BUTTON_0_8_ '1'
#define BUTTON_0_9_ '1'

#define BUTTON_1_0_ '1'
#define BUTTON_1_1_ '1'
#define BUTTON_1_2_ '1'
#define BUTTON_1_3_ '1'
#define BUTTON_1_4_ '1'
#define BUTTON_1_5_ '1'
#define BUTTON_1_6_ '1'
#define BUTTON_1_7_ '1'
#define BUTTON_1_8_ '1'
#define BUTTON_1_9_ '1'

#define BUTTON_2_0_ '1'
#define BUTTON_2_1_ '1'
#define BUTTON_2_2_ '3'
#define BUTTON_2_3_ '1'
#define BUTTON_2_4_ '1'
#define BUTTON_2_5_ '1'
#define BUTTON_2_6_ '1'
#define BUTTON_2_7_ '1'
#define BUTTON_2_8_ '1'
#define BUTTON_2_9_ '1'

#define BUTTON_3_0_ '1'
#define BUTTON_3_1_ '1'
#define BUTTON_3_2_ '1'
#define BUTTON_3_3_ '1'
#define BUTTON_3_4_ '1'
#define BUTTON_3_5_ '1'
#define BUTTON_3_6_ '1'
#define BUTTON_3_7_ '1'
#define BUTTON_3_8_ '1'
#define BUTTON_3_9_ '1'

#define BUTTON_4_0_ '1'
#define BUTTON_4_1_ '1'
#define BUTTON_4_2_ '1'
#define BUTTON_4_3_ '1'
#define BUTTON_4_4_ '1'
#define BUTTON_4_5_ '1'
#define BUTTON_4_6_ '1'
#define BUTTON_4_7_ '1'
#define BUTTON_4_8_ '1'
#define BUTTON_4_9_ '1'

#define BUTTON_5_0_ '1'
#define BUTTON_5_1_ '1'
#define BUTTON_5_2_ '1'
#define BUTTON_5_3_ '1'
#define BUTTON_5_4_ '1'
#define BUTTON_5_5_ '1'
#define BUTTON_5_6_ '1'
#define BUTTON_5_7_ '1'
#define BUTTON_5_8_ '1'
#define BUTTON_5_9_ '1'

#define BUTTON_6_0_ '1'
#define BUTTON_6_1_ '1'
#define BUTTON_6_2_ '1'
#define BUTTON_6_3_ '1'
#define BUTTON_6_4_ '1'
#define BUTTON_6_5_ '1'
#define BUTTON_6_6_ '1'
#define BUTTON_6_7_ '1'
#define BUTTON_6_8_ '1'
#define BUTTON_6_9_ '1'

#define BUTTON_7_0_ '1'
#define BUTTON_7_1_ '1'
#define BUTTON_7_2_ '1'
#define BUTTON_7_3_ '1'
#define BUTTON_7_4_ '1'
#define BUTTON_7_5_ '1'
#define BUTTON_7_6_ '1'
#define BUTTON_7_7_ '1'
#define BUTTON_7_8_ '1'
#define BUTTON_7_9_ '1'

#define BUTTON_8_0_ '1'
#define BUTTON_8_1_ '1'
#define BUTTON_8_2_ '1'
#define BUTTON_8_3_ '1'
#define BUTTON_8_4_ '1'
#define BUTTON_8_5_ '1'
#define BUTTON_8_6_ '1'
#define BUTTON_8_7_ '1'
#define BUTTON_8_8_ '1'
#define BUTTON_8_9_ '1'

#define BUTTON_9_0_ '1'
#define BUTTON_9_1_ '1'
#define BUTTON_9_2_ '1'
#define BUTTON_9_3_ '1'
#define BUTTON_9_4_ '1'
#define BUTTON_9_5_ '1'
#define BUTTON_9_6_ '1'
#define BUTTON_9_7_ '1'
#define BUTTON_9_8_ '1'
#define BUTTON_9_9_ '1'



#endif
