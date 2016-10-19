#include "ev3api.h"
#include "app.h"
#include "TouchSensor.h"
#include "ColorSensor.h"
#include "GyroSensor.h"
#include "Clock.h"
#include "ETGyroSensor.h"
#include "ETBrightSensor.h"
#include "ETTouchSensor.h"
#include "WheelMotor.h"
#include "TailMotor.h"
#include "Motor.h"
#include "TurnCalc.h"
#include "CommandTask.h"
#include "DistanceTask.h"
#include "DriveTask.h"

using namespace ev3api;

#define DEBUG

#ifdef DEBUG
#define _debug(x) (x)
#else
#define _debug(x)
#endif

#define CALIB_FONT (EV3_FONT_SMALL)
#define CALIB_FONT_WIDTH (6/*TODO: magic number*/)
#define CALIB_FONT_HEIGHT (8/*TODO: magic number*/)

void calibration();

TouchSensor*    touchSensor;
ColorSensor*    colorSensor;
GyroSensor*     gyroSensor;
Motor* right;
Motor* left;
Motor* tailMotor;
Clock* clock;

linetrace::CommandTask* ct;
linetrace::ETGyroSensor* gyro;
linetrace::ETTouchSensor* touch;
linetrace::ETBrightSensor* bright;
linetrace::WheelMotor* wheel;
linetrace::TailMotor* tail;
linetrace::TurnCalc* turn;
linetrace::DistanceTask* dt;
linetrace::DriveTask* drivet;

float BLACK = 0.0;
float WHITE = 0.0;

void main_task(intptr_t unused) {

  uint32_t start = 0,end = 0;

  touchSensor = new TouchSensor(PORT_1);
  colorSensor = new ColorSensor(PORT_3);
  gyroSensor  = new GyroSensor(PORT_4);
  left   = new Motor(PORT_C);
  right  = new Motor(PORT_B);
  tailMotor = new Motor(PORT_A);
  clock = new Clock();

  gyroSensor->reset();
  bright = new linetrace::ETBrightSensor(colorSensor);
  touch = new linetrace::ETTouchSensor(touchSensor);
  gyro = new linetrace::ETGyroSensor(gyroSensor);
  wheel = new linetrace::WheelMotor(right,left);
  tail = new linetrace::TailMotor(tailMotor, 2.0);
  turn = new linetrace::TurnCalc(bright,0.0,0.0);
  ct = new linetrace::CommandTask(touch);
  dt = new linetrace::DistanceTask(wheel);
  drivet = new linetrace::DriveTask(turn,wheel,tail,gyro);

  act_tsk(BT_TASK);
  //act_tsk(DIS_TASK);
  ev3_speaker_play_tone	(NOTE_C4,100 );

  tail->resetEncord();

  calibration();

  turn->setTarget(WHITE, BLACK);

  char buff[256] = {'\0'};
  int32_t value = 0;
  while(1){
    tail->controlTail(90);

    if(ct->checkStartCommand() == true){
      break;
    }
    clock->sleep(10);
  }

  ter_tsk(BT_TASK);

  act_tsk(DIS_TASK);

  wheel->resetEncord();
  balance_init();

  start = clock->now();
  while(1){

    if(touch->isButtonPressed() == true){
      break;
    }

    if(dt->getDistanceMeter() > 2.0){
      break;
    }

    drivet->run();
    clock->sleep(4);
  }
  end = clock->now();

  ev3_speaker_play_tone	(NOTE_C4,100 );

  ter_tsk(DIS_TASK);
  wheel->controlWheel(0,0);

  value = end-start;
  sprintf(buff,"%d",(int)value);
  ev3_lcd_fill_rect(0, 0, EV3_LCD_WIDTH, EV3_LCD_HEIGHT, EV3_LCD_WHITE);
  ev3_lcd_draw_string(buff, 0, CALIB_FONT_HEIGHT*1);

  ext_tsk();

}

void calibration(){

  bool flag = false;

  ev3_lcd_fill_rect(0, 0, EV3_LCD_WIDTH, EV3_LCD_HEIGHT, EV3_LCD_WHITE);
  ev3_lcd_draw_string("Detect BLACK", 0, CALIB_FONT_HEIGHT*1);
  while(1){

    if(touch->isButtonPressed() == true){
      flag = true;
    }else{
      if(flag == true){
        break;
      }
    }
    clock->sleep(20);
  }
  ev3_speaker_play_tone	(NOTE_C4,100 );
  BLACK = bright->getBright();
  flag = false;

  ev3_lcd_fill_rect(0, 0, EV3_LCD_WIDTH, EV3_LCD_HEIGHT, EV3_LCD_WHITE);
  ev3_lcd_draw_string("Detect WHITE", 0, CALIB_FONT_HEIGHT*1);
  while(1){
    if(touch->isButtonPressed() == true){
      flag = true;
    }else{
      if(flag == true){
        break;
      }
    }
    clock->sleep(20);
  }
  ev3_speaker_play_tone	(NOTE_C4,100 );
  WHITE = bright->getBright();
  flag = false;

}

void bt_task(intptr_t unused)
{
  while(1){
    ct->run();
    clock->sleep(20);
  }
}

void dis_task(intptr_t unused){
  while(1){
    dt->run();
    clock->sleep(100);
  }
}
