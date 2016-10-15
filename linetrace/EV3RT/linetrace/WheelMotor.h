#ifndef LINETRACE_WHEEL_MOTOR_H
#define LINETRACE_WHEEL_MOTOR_H

#include "lejos/hardware/port/TachoMotorPort.h"

namespace linetrace
{
class WheelMotor
{
private:
	lejos::hardware::port::TachoMotorPort motorPortR;
	lejos::hardware::port::TachoMotorPort motorPortL;

public:
	WheelMotor(void motorR, void motorL);

	void resetEncord();

	void controlWheel(int right, int left);

	int getEncordL();

	int getEncordR();

};

}  // namespace linetrace
#endif
