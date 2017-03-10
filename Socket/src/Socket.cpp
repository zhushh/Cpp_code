#include "stdafx.h"

#include "Socket.h"

// class Socket {
// public:
// 	  virtual bool send(string) = 0;
//    virtual bool recv(string) = 0;
// };

Server::Server(int port) { initBindingAndListening("127.0.0.1", port); }
Server::Server(char* ip, int port) { initBindingAndListening(ip, port); }
Server::~Server() { closesocket(clientSock); }

void Server::initBindingAndListening(char*ip, int port) {
	cout << "start init" << endl;
	servSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	IF_COND_PRINT_AND_EXIT(servSock == INVALID_SOCKET, "Create socket fail!\n", -1);

	// init sockaddr_in 
	struct sockaddr_in servAddr;
	memset(&servAddr, 0, sizeof(sockaddr_in));
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons(port);
	servAddr.sin_addr.S_un.S_addr = inet_addr(ip);

	// binding
	int retVal = bind(servSock, (sockaddr*)&servAddr, sizeof(servAddr));
	IF_COND_PRINT_AND_EXIT(retVal == SOCKET_ERROR, "Bind socket fail!\n", -1);
	printf("Binding succeed!\n");

	// listening
	IF_COND_PRINT_AND_EXIT(listen(servSock, 10) == SOCKET_ERROR, "Listening fail!\n", -1);
	printf("Server %d is listening...\n", port);
}

bool Server::isAccepted() {
	memset(&clientAddr, 0, sizeof(sockaddr_in));
	int addrlen = sizeof(clientAddr);
	clientSock = accept(servSock, (sockaddr*)&clientAddr, &addrlen);
	IF_COND_PRINT_AND_EXIT(clientSock < 0, "Accept client fail!\n", -1);
	printf("Accept from %s\n", inet_ntoa(clientAddr.sin_addr));
	return true;
}

bool Server::send(string str) { return true; }
bool Server::recv(string str) { return true; }

Client::Client() {}
Client::Client(char* ip, int port) { connectTo(ip, port); }
Client::~Client() { closesocket(servSock); }

bool Client::connectTo(char* ip, int port) {
	servSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	IF_COND_PRINT_AND_EXIT(servSock == INVALID_SOCKET, "Create socket fail!\n", -1);
	struct sockaddr_in servAddr;
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons(port);
	servAddr.sin_addr.S_un.S_addr = inet_addr(ip);

	int retVal = connect(servSock, (sockaddr*)&servAddr, sizeof(servAddr));
	IF_COND_PRINT_AND_EXIT(retVal == SOCKET_ERROR, "Connect to server fail!\n", -1);
	printf("Connect to server %s:%d succeed!\n", ip, port);
	return true;
}

bool Client::send(string str) { return true; }
bool Client::recv(string str) { return true; }

