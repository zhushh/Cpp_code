#include "stdafx.h"

#include "Socket.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	//初始化WSA  
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA wsaData;
	if (WSAStartup(sockVersion, &wsaData) != 0)
	{
		return 0;
	}

	Server s(8889);
	while (s.isAccepted()) {
		// do something here
	}

	system("pause");
    return 0;
}
