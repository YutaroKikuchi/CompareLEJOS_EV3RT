#include "CommandTask.h"

namespace linetrace
{

CommandTask::CommandTask(ETTouchSensor touch)
:startFlag(false)
{
}

void CommandTask::run()
{
}

boolean CommandTask::checkStartCommand()
{
	return 0;
}
}  // namespace linetrace
