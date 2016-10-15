#ifndef LINETRACE_DISTANCE_TASK_H
#define LINETRACE_DISTANCE_TASK_H

#include "java/util/TimerTask.h"
#include "linetrace/WheelMotor.h"

namespace linetrace
{
class DistanceTask : public java::util::TimerTask
{
private:
	float curposRight;

	float curposLeft;


protected:
	WheelMotor wheel;

protected:
	DistanceTask(WheelMotor wheel);

public:
	void run();

	float getDistanceCMeter();

	float getDistanceMeter();

};

}  // namespace linetrace
#endif
