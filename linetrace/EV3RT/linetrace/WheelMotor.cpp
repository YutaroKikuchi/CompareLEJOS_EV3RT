#include "ev3api.h"
#include "Motor.h"

#include "WheelMotor.h"

namespace linetrace
{

WheelMotor::WheelMotor(ev3api::Motor* motorR, ev3api::Motor* motorL)
{
	right = motorR;
	left = motorL;
}

void WheelMotor::resetEncord()
{
	right->reset();
	left->reset();
}

void WheelMotor::controlWheel(int rightPWM, int leftPWM)
{
	right->setPWM(rightPWM);
	left->setPWM(leftPWM);
}

int WheelMotor::getEncordL()
{
	return left->getCount();
}

int WheelMotor::getEncordR()
{
	return right->getCount();
}
}  // namespace linetrace
