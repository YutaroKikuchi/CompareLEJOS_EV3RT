#ifndef LINETRACE_DISTANCE_TASK_H
#define LINETRACE_DISTANCE_TASK_H

#include "WheelMotor.h"

namespace linetrace
{
class DistanceTask
{
private:
	float curposRight;

	float curposLeft;

	float distance_CM;


protected:
	WheelMotor* wheel;

public:
	DistanceTask(WheelMotor* wheel);

public:
	void run();

	float getDistanceCMeter();

	float getDistanceMeter();

};

}  // namespace linetrace
#endif
