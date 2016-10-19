#ifndef LINETRACE_DRIVE_TASK_H
#define LINETRACE_DRIVE_TASK_H

#include "ev3api.h"
#include "ETGyroSensor.h"
#include "TurnCalc.h"
#include "WheelMotor.h"
#include "TailMotor.h"
#include "balancer.h"

namespace linetrace
{
class DriveTask
{
protected:
	ETGyroSensor* gyro;
	TurnCalc* turn;
	WheelMotor* wheel;
	TailMotor* tail;

public:
	DriveTask(TurnCalc* turn, WheelMotor* wheel, TailMotor* tail, ETGyroSensor* gyro);

public:
	void run();

};

}  // namespace linetrace
#endif
