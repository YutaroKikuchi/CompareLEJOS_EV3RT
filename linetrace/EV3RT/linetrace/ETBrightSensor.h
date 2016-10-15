#ifndef LINETRACE_E_T_BRIGHT_SENSOR_H
#define LINETRACE_E_T_BRIGHT_SENSOR_H

#include "ev3api.h"
#include "ColorSensor.h"
namespace linetrace
{
class ETBrightSensor
{
private:
	float min;

	float max;

	float min_api;

	float max_api;

	ev3api::ColorSensor* color;

public:
	ETBrightSensor(ev3api::ColorSensor* addedSensor);

	float getBright();

};

}  // namespace linetrace
#endif
