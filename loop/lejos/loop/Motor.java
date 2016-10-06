package motor;

import Balancer.Balancer;
import lejos.hardware.Battery;
import lejos.hardware.Button;
import lejos.hardware.lcd.LCD;
import lejos.hardware.port.BasicMotorPort;
import lejos.utility.Delay;


public class Motor {

	 private static EV3Body         body    = new EV3Body();
	 private static final int   PWM_ABS_MAX          = 60;   // 完全停止用モータ制御PWM絶対最大値
	private static final float P_GAIN = 2.5F;

	 public static void main(String[] args) {
	        LCD.drawString("Please Wait...  ", 0, 4);
	        body.gyro.reset();
	        body.sonar.enable();
	        body.motorPortL.setPWMMode(BasicMotorPort.PWM_BRAKE);
	        body.motorPortR.setPWMMode(BasicMotorPort.PWM_BRAKE);
	        body.motorPortT.setPWMMode(BasicMotorPort.PWM_BRAKE);

	        // Java の初期実行性能が悪く、倒立振子に十分なリアルタイム性が得られない。
	        // 走行によく使うメソッドについて、HotSpot がネイティブコードに変換するまで空実行する。
	        // HotSpot が起きるデフォルトの実行回数は 1500。
	        for (int i=0; i < 1500; i++) {
	            body.motorPortL.controlMotor(0, 0);
	            body.motorPortR.controlMotor(0, 0);
	            body.motorPortT.controlMotor(0, 0);
	            body.motorPortL.getTachoCount();
	            body.motorPortR.getTachoCount();
	            body.motorPortT.getTachoCount();
	            body.getBrightness();
	            body.getSonarDistance();
	            body.getGyroValue();
	            Battery.getVoltageMilliVolt();
	            Balancer.control(0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 8000);
	        }
	        Delay.msDelay(10000);       // 別スレッドで HotSpot が完了するだろう時間まで待つ。

	        body.motorPortL.controlMotor(0, 0);
	        body.motorPortR.controlMotor(0, 0);
	        body.motorPortT.controlMotor(0, 0);
	        body.motorPortL.resetTachoCount();   // 左モータエンコーダリセット
	        body.motorPortR.resetTachoCount();   // 右モータエンコーダリセット
	        body.motorPortT.resetTachoCount();   // 尻尾モータエンコーダリセット


	        long start = System.currentTimeMillis();

	        for (int i=0; i < 3000; i++) {


	            body.motorPortL.controlMotor(20, 1);
	            body.motorPortR.controlMotor(20, 1);
	            tailControl(body,90);
	            body.motorPortL.getTachoCount();
	            body.motorPortR.getTachoCount();
	            body.motorPortT.getTachoCount();
	            body.getBrightness();
	            body.getSonarDistance();
	            body.getGyroValue();
	            Battery.getVoltageMilliVolt();
	            Balancer.control(0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 8000);
	            Delay.msDelay(4);
	        }

	        long end = System.currentTimeMillis();

            body.motorPortL.controlMotor(0, 0);
            body.motorPortR.controlMotor(0, 0);
            body.motorPortT.controlMotor(0, 0);

	        long time = (end - start);

	        LCD.clear();
	        LCD.drawString("Time:"+time +"[ms]", 0, 0);

	        Button.waitForAnyEvent();

	 }

	 private static final void tailControl(EV3Body body, int angle) {
	        float pwm = (float)(angle - body.motorPortT.getTachoCount()) * P_GAIN; // 比例制御
	        // PWM出力飽和処理
	        if (pwm > PWM_ABS_MAX) {
	            pwm = PWM_ABS_MAX;
	        } else if (pwm < -PWM_ABS_MAX) {
	            pwm = -PWM_ABS_MAX;
	        }
	        body.motorPortT.controlMotor((int)pwm, 1);
	    }
}
