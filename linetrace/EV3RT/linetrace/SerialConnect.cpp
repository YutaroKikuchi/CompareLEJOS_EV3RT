#include "SerialConnect.h"

namespace linetrace
{

SerialConnect::SerialConnect()
:remoteCommand(0), bluetooth(NULL)
{
	this->bluetooth = ev3_serial_open_file(EV3_SERIAL_BT);
}

void SerialConnect::checkCommand()
{
	remoteCommand = fgetc(this->bluetooth);
	fputc((uint8_t)remoteCommand, this->bluetooth);
}

int SerialConnect::getCommand()
{
	return remoteCommand;
}
}  // namespace linetrace
