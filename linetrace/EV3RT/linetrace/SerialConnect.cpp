#include "SerialConnect.h"

namespace linetrace
{
int SerialConnect::remoteCommand = 0;
int SerialConnect::SOCKET_PORT = 7360;
java::io::InputStream SerialConnect::inputStream = null;
java::io::DataInputStream SerialConnect::dataInputStream = null;
java::net::Socket SerialConnect::client = null;
java::net::ServerSocket SerialConnect::server = null;

SerialConnect::SerialConnect()
:inputStream(null), dataInputStream(null), client(null), server(null)
{
}

void SerialConnect::checkCommand()
{
}

int SerialConnect::getCommand()
{
	return 0;
}
}  // namespace linetrace
