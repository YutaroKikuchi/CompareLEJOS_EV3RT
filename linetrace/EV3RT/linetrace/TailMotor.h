#ifndef LINETRACE_TAIL_MOTOR_H
#define LINETRACE_TAIL_MOTOR_H

#include "lejos/hardware/port/TachoMotorPort.h"

namespace linetrace
{
class TailMotor
{
private:
	float P;

	int PWM_MAX;

	lejos::hardware::port::TachoMotorPort motorPortT;

public:
	TailMotor(void tail);

	void resetEncord();

	void pwmControlTail(int pwm);

	void controlTail(int angle);

};

}  // namespace linetrace
#endif
