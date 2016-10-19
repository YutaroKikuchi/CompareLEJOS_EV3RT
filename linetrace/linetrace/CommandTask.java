package linetrace;

import java.util.TimerTask;

public class CommandTask extends TimerTask{

	SerialConnect serial = new SerialConnect();
	TouchSensor touch;

	boolean startFlag = false;

	CommandTask(TouchSensor touch){
		this.touch = touch;
	}

	@Override
	public void run() {
		// TODO 自動生成されたメソッド・スタブ

		serial.checkCommand();

		if(serial.getCommand() == 83){
			startFlag = true;
		}else if(touch.isButtonPressed() == true){
			startFlag = true;
		}else{

		}

	}

	public boolean checkStartCommand(){
		return startFlag;
	}

}
