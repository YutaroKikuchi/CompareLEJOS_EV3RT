#include "CommandTask.h"
#include "ETTouchSensor.h"
#include "SerialConnect.h"

namespace linetrace
{

CommandTask::CommandTask(ETTouchSensor* touch)
:startFlag(false)
{
	this->touch = touch;
	this->serial = new SerialConnect();
}

void CommandTask::run()
{
	serial->checkCommand();

	if(serial->getCommand() == 's'){
		startFlag = true;
	}
}

bool CommandTask::checkStartCommand()
{
	if(this->touch->isButtonPressed() == true){
		this->startFlag = true;
	}

	return startFlag;
}
}  // namespace linetrace
