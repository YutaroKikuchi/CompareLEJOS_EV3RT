#include "TurnCalc.h"

namespace linetrace
{

TurnCalc::TurnCalc(ETBrightSensor bright)
:KP(0.0F), KD(0.0F), BrightTarget(0.0F), prediff(0.0F)
{
}

float TurnCalc::getTurn()
{
	return 0;
}

void TurnCalc::setTarget(float white, float black)
{
}
}  // namespace linetrace
