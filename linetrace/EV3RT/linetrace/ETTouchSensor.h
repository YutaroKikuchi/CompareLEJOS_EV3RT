#ifndef LINETRACE_E_T_TOUCH_SENSOR_H
#define LINETRACE_E_T_TOUCH_SENSOR_H

#include "ev3api.h"
#include "TouchSensor.h"

namespace linetrace
{
class ETTouchSensor
{
private:
	ev3api::TouchSensor* touchSensor;

public:
	ETTouchSensor(ev3api::TouchSensor* touch);

	bool isButtonPressed();

};

}  // namespace linetrace
#endif
