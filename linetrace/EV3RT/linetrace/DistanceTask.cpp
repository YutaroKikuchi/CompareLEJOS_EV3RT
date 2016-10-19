#include "DistanceTask.h"

namespace linetrace
{

DistanceTask::DistanceTask(WheelMotor* wheel)
:curposRight(0.0F), curposLeft(0.0F), distance_CM(0.0)
{
	this->wheel = wheel;
}

void DistanceTask::run()
{
	this->curposLeft = this->wheel->getEncordL();
	this->curposRight = this->wheel->getEncordR();

	this->distance_CM = (((curposLeft + curposRight)/2.0) / 360.0) * 26.2;
}

float DistanceTask::getDistanceCMeter()
{
	return this->distance_CM;
}

float DistanceTask::getDistanceMeter()
{
	return this->distance_CM / 100.0;
}
}  // namespace linetrace
