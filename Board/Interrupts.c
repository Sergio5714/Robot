#include "Interrupts.h"
extern RobotStatus Robot;

// Interrupt handler for motor control
void TIM6_DAC_IRQHandler(void)
{
	if (MOTOR_CONTROL_TIM_MODULE->SR & TIM_SR_UIF)
	{
		timClearStatusRegisterFlag(MOTOR_CONTROL_TIM_MODULE, TIM_SR_UIF);
		
		// Read data from Encoders (Encoders -> wheelsSpeed (+ wheelsCoord) -> robotSpeedCs1 (+ robotCoordCs1) )
		readEnc();
		// Calculate global speed and coordinate (robotSpeedCs1 -> robotSpeedCsGlobal (+ robotCoordCsGlobal))
		calcGlobSpeedAndCoord();
		
		if (Robot.forwardKinCalcStatusFlag)
		{
			// Calculate Forward kinematics ( robotTargetSpeedCs1 -> robotTargetMotorSpeedCs1)
			calcForwardKin();
			// Set speeds for motors (robotTargetMotorSpeedCs1 -> PWM)
			setMotorSpeeds();
		}
		// Update robot status
		updateRobotStatus();
	}
	return;
}
