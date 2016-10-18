#ifndef LINETRACE_COMMAND_TASK_H
#define LINETRACE_COMMAND_TASK_H

#include "SerialConnect.h"
#include "ETTouchSensor.h"

namespace linetrace
{
	class CommandTask
	{
	protected:
		bool startFlag;

		SerialConnect* serial;
		ETTouchSensor* touch;

	public:
		CommandTask(ETTouchSensor* touch);

	public:
		void run();

		bool checkStartCommand();

	};
}  // namespace linetrace
#endif
