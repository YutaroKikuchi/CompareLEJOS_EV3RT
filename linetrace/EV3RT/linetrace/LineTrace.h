#ifndef LINETRACE_LINE_TRACE_H
#define LINETRACE_LINE_TRACE_H

#include "java/lang/String.h"
#include "linetrace/ETBrightSensor.h"
#include "linetrace/ETTouchSensor.h"

namespace linetrace
{
class LineTrace
{
protected:
	static float BLACK;

	static float WHITE;


private:
	static void calibration(ETBrightSensor bright, ETTouchSensor touch);

public:
	static void main(java::lang::String args[]);

};

}  // namespace linetrace
#endif
