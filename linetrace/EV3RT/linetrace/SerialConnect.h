#ifndef LINETRACE_SERIAL_CONNECT_H
#define LINETRACE_SERIAL_CONNECT_H

#include "java/net/Socket.h"
#include "java/net/ServerSocket.h"
#include "java/io/InputStream.h"
#include "java/io/DataInputStream.h"

namespace linetrace
{
class SerialConnect
{
private:
	static int remoteCommand;

	static int SOCKET_PORT;

	static java::io::InputStream inputStream;
	static java::io::DataInputStream dataInputStream;
	static java::net::Socket client;
	static java::net::ServerSocket server;

protected:
	SerialConnect();

public:
	void checkCommand();

	int getCommand();

};

}  // namespace linetrace
#endif
