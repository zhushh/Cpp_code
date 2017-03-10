// Client.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "Socket.h"

int main()
{
	//初始化WSA  
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA wsaData;
	if (WSAStartup(sockVersion, &wsaData) != 0)
	{
		return 0;
	}

	Client c("127.0.0.1", 8889);

	system("pause");
    return 0;
}

