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

float BLACK = 0.0;
float WHITE = 0.0;

void main_task(intptr_t unused) {

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
  tail = new linetrace::TailMotor(tailMotor);
  turn = new linetrace::TurnCalc(bright);
  ct = new linetrace::CommandTask(touch);

  //calibration();

  act_tsk(BT_TASK);
  ev3_speaker_play_tone	(NOTE_C4,100 );

/*
  wheel->resetEncord();

  calibration();

  turn->setTarget(WHITE, BLACK);

  char buff[256] = {'\0'};
  float value = 0.0;
  */

  while(1){
    /*
    value = gyro->getGyro_deg_per_sec();

    sprintf(buff,"%f",value);

    ev3_lcd_fill_rect(0, 0, EV3_LCD_WIDTH, EV3_LCD_HEIGHT, EV3_LCD_WHITE);
    ev3_lcd_draw_string(buff, 0, CALIB_FONT_HEIGHT*1);

    value = bright->getBright();
    sprintf(buff,"%f",value);
    ev3_lcd_draw_string(buff,0,CALIB_FONT_HEIGHT*2);

    wheel->controlWheel(20,20);
    */

    if(ct->checkStartCommand() == true){
      ev3_lcd_fill_rect(0, 0, EV3_LCD_WIDTH, EV3_LCD_HEIGHT, EV3_LCD_WHITE);
      ev3_lcd_draw_string("TRUE", 0, CALIB_FONT_HEIGHT*1);
    }else{
      ev3_lcd_fill_rect(0, 0, EV3_LCD_WIDTH, EV3_LCD_HEIGHT, EV3_LCD_WHITE);
      ev3_lcd_draw_string("FALSE", 0, CALIB_FONT_HEIGHT*1);
    }

    clock->sleep(20);
  }
  ev3_speaker_play_tone	(NOTE_C4,100 );


  ter_tsk(BT_TASK);

/*
  while(1){
    value = bright->getBright();

    sprintf(buff,"%f",value);
    ev3_lcd_fill_rect(0, 0, EV3_LCD_WIDTH, EV3_LCD_HEIGHT, EV3_LCD_WHITE);
    ev3_lcd_draw_string(buff, 0, CALIB_FONT_HEIGHT*1);

    while(1){
      if(touch->isButtonPressed()==true){
        break;
      }
      clock->sleep(50);
    }
  }
  */
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
