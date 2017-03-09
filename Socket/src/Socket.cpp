#include "Socket.h"

class Socket {
public:
	virtual bool send(string) = 0;
	virtual bool recv(string) = 0;
};


//int fd;
//struct sockaddr_in clientSock;
Server::Server(int port) {}
Server::Server(char* ip, int port) {}
Server::~Server() {}



class Client : public Socket {
public:
	Client();
	Client(char*, int);
	~Client();
	bool connect(char*, int);
private:
	int fd;
};
