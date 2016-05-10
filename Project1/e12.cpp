#include <string>
#include <memory>
#include <iostream>

using namespace std;

struct connection
{
	string ip;
	int port;
	connection(string ip_, int port_) : ip(ip_), port(port_) {}
};

struct destination
{
	string ip;
	int port;
	destination(string ip_, int port_) : ip(ip_), port(port_) {}
};

connection connect(destination * pDest)
{
	unique_ptr<connection> pConn(new connection(pDest->ip, pDest->port));
	cout << "creating connection(" << 1 << ")" << endl;
	return *pConn;
}

void disconnect(connection pConn)
{
	cout << "connection close(" << pConn.ip << ":" << pConn.port << ")" << endl;
}

void end_connection(connection *pConn)
{
	disconnect(*pConn);
}

int main()
{
	destination des("192.168.1.112", 8080);
	connection conn = connect(&des);
	unique_ptr<connection, decltype(end_connection) *> ptr(&conn, end_connection);
	cout << "connecting now (" << 1 << ")" << endl;

	return 0;
}