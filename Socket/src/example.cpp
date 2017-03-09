#include <WinSock2.h>
#include <stdio.h>
#include <Windows.h>
/* 要使用winsock API，就要包含ws2_32.lib这个库 */
#pragma comment(lib, "ws2_32.lib")
int main(int argc, char* argv[])
{
	//为端口号赋值
	short port;
	//判断输入参数是否正确
	if (argc != 2)
	{
		printf("Usage:%s PortNumber\n", argv[0]);
		//exit(-1); or default port 8889
		port = 8889;
	} 
	else if ((port = atoi(argv[1])) == 0)
	{
		printf("portnumber wrong\n");
		exit(-1);
	}
	/*    第一步：初始化（注册）Winsock.dll    */
	WSADATA wsaData;
	//init Winsock.dll
	if (WSAStartup(MAKEWORD(1, 1), &wsaData) != 0)
	{
		printf("fail to init winsock.dll!\n");
		exit(-1);
	}
	/*    第二步：创建监听套接字    */
	//creat socket
	SOCKET servSoc;
	if ((servSoc = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET)
	{
		printf("create socket error!\n");
		exit(-1);
	}
	/*    填写一些服务器的地址信息（三元组）    */
	struct sockaddr_in servAddr;
	memset(&servAddr, 0, sizeof(sockaddr_in));
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons(port);
	servAddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	/*    第三步：绑定地址到监听套接字    */
	//bind
	if (bind(servSoc, (sockaddr*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR)
	{
		printf("bind error! port:%d\n", port);
		exit(-1);
	}
	/*    第四步：开始监听（最多允许2个客户机连接）    */
	//listen
	if (listen(servSoc, 2) == SOCKET_ERROR)
	{
		printf("listen error!\n");
		exit(-1);
	}
	printf("Server %d is listening...\n", port);
	/*    创建连接套接字，负责和客户端通信
	*    初始化客户端地址信息
	*/
	SOCKET clientSoc;
	struct sockaddr_in clientAddr;
	memset(&clientAddr, 0, sizeof(clientAddr));
	int addrlen = sizeof(clientAddr);
	/*    第五步：接受客户端的连接    */
	//accept
	if ((clientSoc = accept(servSoc, (sockaddr*)&clientAddr, &addrlen)) == INVALID_SOCKET)
	{
		printf("accept error!\n");
		exit(-1);
	}
	printf("Accept connection from %s\n", inet_ntoa(clientAddr.sin_addr));
	/*    第六步：数据交互    */
	char buf[4096];
	while (1)
	{
		int bytes;
		if ((bytes = recv(clientSoc, buf, sizeof(buf), 0)) == SOCKET_ERROR)
		{
			printf("recv error!\n");
			exit(-1);
		}
		buf[bytes] = '\0';
		printf("Message from %s:%s\n", inet_ntoa(clientAddr.sin_addr), buf);
		if (send(clientSoc, buf, bytes, 0) == SOCKET_ERROR)
		{
			printf("send error!\n");
			exit(-1);
		}
	}
	/*    第七步：清除套接字，释放该条连接所占用的全部资源    */
	//clean socket
	WSACleanup();
	return 0;
}
