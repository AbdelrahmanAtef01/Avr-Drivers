#ifndef HAL_STEPPER_MOTOR_HANDLER_STEPPER_HELPER_H_
#define HAL_STEPPER_MOTOR_HANDLER_STEPPER_HELPER_H_

#define HALF_STEP_ANGLE (float32_t)0.08789
#define FULL_STEP_ANGLE (float32_t)0.1757
#define FULL_CYCLE_FULL_STEP_NO_OF_ROTATIONS (uint16_)(360/FULL_STEP_ANGLE/4)
#define FULL_CYCLE_HALF_STEP_NO_OF_ROTATIONS (uint16_)(360/HALF_STEP_ANGLE/4)

void STEPPER_VidStepperFullStep(uint8_t coil);
void STEPPER_VidStepperHalfStep(uint8_t coil_1,uint8_t coil_2);
void STEPPER_VidStepperFullCycleRight();
void STEPPER_VidStepperFullCycleLeft();
void STEPPER_VidStepperFullCycleHalfStepRight();
void STEPPER_VidStepperFullCycleHalfStepLeft();

#endif
