#include "sever.h"
#include"tcpsocket.h"
sever::sever() {
	fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);//第一个参数代表使用的是IPV4地址，
	//第二个代表使用流式套接字，第三个代表我们使用TCP协议,
	if (fd==INVALID_SOCKET)
	{
		printf("error\n socket()can`t create new socket");
	}
	///在构造器中绑定socket
	///////为什么不能绑定ip号与端口号
	struct sockaddr_in addr;//////使用类型sockaddr变成使用socketaddr类型导致错误
	addr.sin_family = AF_INET;///////////////////////////////////////////////////////////绑定家族
	addr.sin_port =htons( PORT);//大小端的转换问题,网络字节序与本地字节序的转换//////////绑定端口
	addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");///////////绑定ip地址//////////问题/////ip地址的格式问题
	if (SOCKET_ERROR == bind(fd, (struct sockaddr*)&addr, sizeof(addr))) {
		printf("error\n bind()can`t create new socket");
	}
	listen(fd, 5);
	printf("created successfully");
	}
void main() {
	createinit();
	sever Sever;
	//client clone;
	//clone.fd	=   accept(Sever.fd, NULL, NULL);////现在还没有进行初始化对象client
	SOCKET fd= accept(Sever.fd, NULL, NULL);/////
	printf("created successfully,wait for connect");
	if (fd==INVALID_SOCKET)
	{
		printf("error\n accept()can`t create new socket");
	}
	if (SOCKET_ERROR == send(fd, "hello world", 12, 0)) {
		printf("error\n send()can`t create new socket");
	}//https://learn.microsoft.com/zh-cn/windows/win32/api/winsock2/nf-winsock2-send
	closesocket(fd);
	closesocket(Sever.fd);
	//close_Socket();
	closeinit();
}
