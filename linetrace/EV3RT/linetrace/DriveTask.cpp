#include "DriveTask.h"

namespace linetrace
{

DriveTask::DriveTask(TurnCalc* turn, WheelMotor* wheel, TailMotor* tail, ETGyroSensor* gyro)
{
  this->turn = turn;
  this->wheel = wheel;
  this->tail = tail;
  this->gyro = gyro;
}

void DriveTask::run()
{
  int8_t pwm_L, pwm_R;

  tail->controlTail(0);

  float tachoR = this->wheel->getEncordR();
  float tachoL = this->wheel->getEncordL();
  float turn = this->turn->getTurn();
  float gyro = this->gyro->getGyro_deg_per_sec();
  float battery = ev3_battery_voltage_mV();

  balance_control(
      100.0,
      (float)turn,
      (float)gyro,
      (float)0.0,
      (float)tachoL,
      (float)tachoR,
      (float)battery,
      (int8_t *)&pwm_L,
      (int8_t *)&pwm_R);

  wheel->controlWheel(pwm_R,pwm_L);
}
}  // namespace linetrace
