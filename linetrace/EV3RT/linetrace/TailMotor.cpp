#include "TailMotor.h"

namespace linetrace
{

TailMotor::TailMotor(ev3api::Motor* tail)
:P(2.0F), PWM_MAX(60)
{
  motorPortT = tail;
  motorPortT->reset();
}

void TailMotor::resetEncord()
{
  motorPortT->reset();
}

void TailMotor::pwmControlTail(int pwm)
{
  motorPortT->setPWM(pwm);
}

void TailMotor::controlTail(int angle)
{
  float pwm = (float)(angle - motorPortT->getCount()) * P;
  if (pwm > PWM_MAX)
  {
      pwm = PWM_MAX;
  }
  else if (pwm < -PWM_MAX)
  {
      pwm = -PWM_MAX;
  }

  motorPortT->setPWM(pwm);
}
}  // namespace linetrace
