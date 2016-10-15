#ifndef LINETRACE_E_T_GYRO_SENSOR_H
#define LINETRACE_E_T_GYRO_SENSOR_H

#include "ev3api.h"
#include "GyroSensor.h"
namespace linetrace
{
class ETGyroSensor
{
public:
	ev3api::GyroSensor*     gyro;

public:
	float getGyro_deg_per_sec();

public:
	ETGyroSensor(ev3api::GyroSensor* addedGyroSensor);
};

}  // namespace linetrace
#endif
