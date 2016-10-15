#include "ev3api.h"
#include "app.h"
#include "TouchSensor.h"
#include "ColorSensor.h"
#include "GyroSensor.h"
#include "Clock.h"
#include "ETGyroSensor.h"
#include "ETBrightSensor.h"
#include "ETTouchSensor.h"

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

TouchSensor*    touchSensor;
ColorSensor*    colorSensor;
GyroSensor*     gyroSensor;
Clock* clock;

linetrace::ETGyroSensor* gyro;
linetrace::ETTouchSensor* touch;
linetrace::ETBrightSensor* bright;

void main_task(intptr_t unused) {

  touchSensor = new TouchSensor(PORT_1);
  colorSensor = new ColorSensor(PORT_2);
  gyroSensor  = new GyroSensor(PORT_4);
  clock = new Clock();

  gyroSensor->reset();
  bright = new linetrace::ETBrightSensor(colorSensor);
  touch = new linetrace::ETTouchSensor(touchSensor);
  gyro = new linetrace::ETGyroSensor(gyroSensor);

  char buff[256] = {'\0'};
  float value = 0.0;
  while(1){
    value = gyro->getGyro_deg_per_sec();

    sprintf(buff,"%f",value);

    ev3_lcd_fill_rect(0, 0, EV3_LCD_WIDTH, EV3_LCD_HEIGHT, EV3_LCD_WHITE);
    ev3_lcd_draw_string(buff, 0, CALIB_FONT_HEIGHT*1);

    clock->sleep(50);

    if(touch->isButtonPressed()==true){
      break;
    }
  }

  while(1){
    value = bright->getBright();

    sprintf(buff,"%f",value);

    ev3_lcd_fill_rect(0, 0, EV3_LCD_WIDTH, EV3_LCD_HEIGHT, EV3_LCD_WHITE);
    ev3_lcd_draw_string(buff, 0, CALIB_FONT_HEIGHT*1);

    clock->sleep(50);

    if(touch->isButtonPressed()==true){
      break;
    }
  }

  ext_tsk();

}
