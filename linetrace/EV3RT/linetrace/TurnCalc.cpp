#include "ETBrightSensor.h"
#include "TurnCalc.h"

namespace linetrace
{

TurnCalc::TurnCalc(ETBrightSensor* bright)
:KP(100.0F), KD(0.0F), BrightTarget(0.0F), prediff(0.0F)
{
	this->bright = bright;
}

float TurnCalc::getTurn()
{
	float curdiff = BrightTarget - this->bright->getBright();

	float turn = (KP * curdiff) + (KD * (curdiff - prediff));

	prediff = curdiff;

	return turn;
}

void TurnCalc::setTarget(float white, float black)
{
	BrightTarget = (white + black) / 2.0;
}
}  // namespace linetrace
