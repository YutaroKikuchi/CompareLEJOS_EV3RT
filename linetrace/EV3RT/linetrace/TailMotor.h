#ifndef LINETRACE_TAIL_MOTOR_H
#define LINETRACE_TAIL_MOTOR_H

#include "Motor.h"

namespace linetrace
{
class TailMotor
{
private:
	float P;

	int PWM_MAX;

	ev3api::Motor* motorPortT;

public:
	TailMotor(ev3api::Motor* tail);

	void resetEncord();

	void pwmControlTail(int pwm);

	void controlTail(int angle);

};

}  // namespace linetrace
#endif
