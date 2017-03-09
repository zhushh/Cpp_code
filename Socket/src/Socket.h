#pragma once
#ifndef __SOCKET__
#define __SOCKET__

#include <WinSock2.h>
#include <stdio.h>
#include <Windows.h>
/* 要使用winsock API，就要包含ws2_32.lib这个库 */
#pragma comment(lib, "ws2_32.lib")

#include <string>
using std::string;

class Socket {
public:
	virtual bool send(string) = 0;
	virtual bool recv(string) = 0;
};

class Server : public Socket {
public:
	Server(int);
	Server(char*, int);
	~Server();
private:
	int fd;
	struct sockaddr_in clientSock;
};

class Client : public Socket {
public:
	Client();
	Client(char*, int);
	~Client();
	bool connect(char*, int);
private:
	int fd;
};


#endif


