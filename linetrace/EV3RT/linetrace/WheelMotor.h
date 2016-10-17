#ifndef LINETRACE_WHEEL_MOTOR_H
#define LINETRACE_WHEEL_MOTOR_H

#include "ev3api.h"
#include "Motor.h"

namespace linetrace
{
class WheelMotor
{
private:
	ev3api::Motor* right;
	ev3api::Motor* left;

public:
	WheelMotor(ev3api::Motor* motorR, ev3api::Motor* motorL);

	void resetEncord();

	void controlWheel(int rightPWM, int leftPWM);

	int getEncordL();

	int getEncordR();

};

}  // namespace linetrace
#endif
