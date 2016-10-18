#ifndef LINETRACE_SERIAL_CONNECT_H
#define LINETRACE_SERIAL_CONNECT_H

#include "ev3api.h"

namespace linetrace
{
class SerialConnect
{
private:
	uint8_t remoteCommand = 0;
	FILE *bluetooth = NULL;

public:
	SerialConnect();

public:
	void checkCommand();

	int getCommand();

};

}  // namespace linetrace
#endif
