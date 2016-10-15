#ifndef LINETRACE_COMMAND_TASK_H
#define LINETRACE_COMMAND_TASK_H

#include "java/util/TimerTask.h"
#include "linetrace/SerialConnect.h"
#include "linetrace/ETTouchSensor.h"

namespace linetrace
{
class CommandTask : public java::util::TimerTask
{
protected:
	boolean startFlag;

	SerialConnect serial;
	ETTouchSensor touch;

protected:
	CommandTask(ETTouchSensor touch);

public:
	void run();

	boolean checkStartCommand();

};

}  // namespace linetrace
#endif
