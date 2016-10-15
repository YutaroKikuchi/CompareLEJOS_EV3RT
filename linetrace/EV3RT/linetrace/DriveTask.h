#ifndef LINETRACE_DRIVE_TASK_H
#define LINETRACE_DRIVE_TASK_H

#include "java/util/TimerTask.h"
#include "linetrace/ETGyroSensor.h"
#include "linetrace/TurnCalc.h"
#include "linetrace/WheelMotor.h"
#include "linetrace/TailMotor.h"

namespace linetrace
{
class DriveTask : public java::util::TimerTask
{
protected:
	ETGyroSensor gyro;
	TurnCalc turncalc;
	WheelMotor wheel;
	TailMotor tail;

protected:
	DriveTask(TurnCalc turn, WheelMotor wheel, TailMotor tail, ETGyroSensor gyro);

public:
	void run();

};

}  // namespace linetrace
#endif
