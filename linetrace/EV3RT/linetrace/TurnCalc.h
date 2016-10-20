#ifndef LINETRACE_TURN_CALC_H
#define LINETRACE_TURN_CALC_H

#include "ETBrightSensor.h"

namespace linetrace
{
class TurnCalc
{
private:
	float KP;

	float KD;

	float BrightTarget;

	float prediff;

	ETBrightSensor* bright;

public:
	TurnCalc(ETBrightSensor* bright, float KP, float KD);

	float getTurn();

	void setTarget(float white, float black);

};

}  // namespace linetrace
#endif
