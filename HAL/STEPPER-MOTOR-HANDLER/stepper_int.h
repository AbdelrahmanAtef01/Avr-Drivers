#ifndef HAL_STEPPER_MOTOR_HANDLER_STEPPER_INT_H_
#define HAL_STEPPER_MOTOR_HANDLER_STEPPER_INT_H_

void STEPPER_vidStepperInit();
void STEPPER_vidRightRotateCycles(uint8_t no_of_iterations);
void STEPPER_vidLeftRotateCycles(uint8_t no_of_iterations);
void STEPPER_vidRightRotateAngle(uint16_ angle);
void STEPPER_vidLeftRotateAngle(uint16_ angle);
void STEPPER_vidStepperOff();

#endif
