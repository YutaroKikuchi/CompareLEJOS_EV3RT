#include "ev3api.h"
#include "TouchSensor.h"
#include "ETTouchSensor.h"

namespace linetrace
{

ETTouchSensor::ETTouchSensor(ev3api::TouchSensor* touch)
{
	touchSensor = touch;
}

bool ETTouchSensor::isButtonPressed()
{
	if(touchSensor->isPressed()){
		return true;
	}else{
		return false;
	}
}
}  // namespace linetrace
