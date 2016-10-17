#include "ev3api.h"
#include "ETBrightSensor.h"
#include "ColorSensor.h"

namespace linetrace
{

ETBrightSensor::ETBrightSensor(ev3api::ColorSensor* addedSensor)
:min(0.0F), max(1.0F), min_api(0.0F), max_api(100.0F)
{
	color = addedSensor;
}

float ETBrightSensor::getBright()
{
	return ((color->getBrightness() - min_api)/(max_api-min_api)) * (max - min);
}
}  // namespace linetrace
