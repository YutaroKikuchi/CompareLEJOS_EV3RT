#include "ev3api.h"
#include "GyroSensor.h"
#include "ETGyroSensor.h"

namespace linetrace
{

ETGyroSensor::ETGyroSensor(ev3api::GyroSensor* addedGyroSensor)
{
	gyro = addedGyroSensor;
	gyro->reset();
}

float ETGyroSensor::getGyro_deg_per_sec()
{
	return (float)gyro->getAnglerVelocity();
}
}  // namespace linetrace
