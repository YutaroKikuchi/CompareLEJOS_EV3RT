#include "ETBrightSensor.h"
#include "TurnCalc.h"

namespace linetrace
{

TurnCalc::TurnCalc(ETBrightSensor* bright, float KP, float KD)
:BrightTarget(0.0F), prediff(0.0F)
{
	this->bright = bright;
	this->KP = KP;
	this->KD = KD;
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
