#include "DistanceTask.h"

namespace linetrace
{

DistanceTask::DistanceTask(WheelMotor wheel)
:curposRight(0.0F), curposLeft(0.0F)
{
}

void DistanceTask::run()
{
}

float DistanceTask::getDistanceCMeter()
{
	return 0;
}

float DistanceTask::getDistanceMeter()
{
	return 0;
}
}  // namespace linetrace
