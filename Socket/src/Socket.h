#pragma once
#ifndef __SOCKET__
#define __SOCKET__

#include <WinSock2.h>
#include <stdio.h>
#include <Windows.h>

/* 要使用winsock API，就要包含ws2_32.lib这个库 */
#pragma comment(lib, "ws2_32.lib")

#include <iostream>
#include <string>
using namespace std;

#define IF_COND_PRINT(cond, str) if (cond) { printf("%s", str); }
#define IF_COND_EXIT(cond, status) if (cond) { exit(status); }
#define IF_COND_PRINT_AND_EXIT(cond, str, status) \
if (cond) { printf("%s", str); exit(status); }

class Socket {
public:
    virtual bool sendSTR(string) = 0;
    virtual bool recvSTR(string&) = 0;
};

class Server : public Socket {
public:
    Server(int);
    Server(char*, int);
    ~Server();
    bool isAccepted();
    bool sendSTR(string str);
    bool recvSTR(string &str);
private:
    unsigned int servSock;
    unsigned int clientSock;
    struct sockaddr_in clientAddr;
    void initBindingAndListening(char*ip, int port);
};

class Client : public Socket {
public:
    Client();
    Client(char*, int);
    ~Client();
    bool connectTo(char*, int);
    bool sendSTR(string str);
    bool recvSTR(string &str);
private:
    unsigned int servSock;
};

#endif
