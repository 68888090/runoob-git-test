#include "client.h"

client::client(const char* ip) {
	fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (fd == INVALID_SOCKET)
	{
		printf("error\n socket()can`t create new socket\n");
	}

	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);
	addr.sin_addr.S_un.S_addr = inet_addr(ip);//绑定ip地址
	if (INVALID_SOCKET == connect(fd, (struct sockaddr*)&addr, sizeof(addr)))
		printf("error\n connect()can`t create new socket\n");

	///////转换sockaddr_in到sockaddr类型

}
void main() {
	createinit();
	client Client("127.0.0.1");
	//client clone;
	//clone.fd	=   accept(Sever.fd, NULL, NULL);////现在还没有进行初始化对象client
	//SOCKET fd = accept(Sever.fd, NULL, NULL);/////没有连接项所以进行了卡壳
	printf("created successfully,require connection\n");
	char recvbuf[1024];
	int ret;
	ret = recv(Client.fd, recvbuf, 1024, 0);//////启动，但是recv的数据在哪不知
	SOCKET fd = accept(Client.fd, NULL, NULL);/////没有连接项所以进行了卡壳
	printf("created successfully,wait for connect\n");
	if (ret == 0)
	{
		printf("服务器正常下线\n");
	}
	else if (ret <= 0)
	{
		printf("服务器非正常下线\n");
	}
	
	                     
	std::cout << recvbuf << std::endl;
	if (SOCKET_ERROR == send(Client.fd,"客户端接收到了您的请求", 12, 0)) {//////启动，但是send发送到何处不知
		printf("error\n send()can`t create new socket\n");
	}//https://learn.microsoft.com/zh-cn/windows/win32/api/winsock2/nf-wi
	std::cout << "完成传输" << std::endl;
	closesocket(Client.fd);
	closeinit();
	getchar();
}
