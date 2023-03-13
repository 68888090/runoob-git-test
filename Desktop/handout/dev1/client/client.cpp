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
	if (ret == 0)
	{
		printf("服务器正常下线\n");
	}
	else if (ret <= 0)
	{
		printf("服务器非正常下线\n");
	}
	closesocket(Client.fd);
	closeinit();
	std::cout << recvbuf << std::endl;
	std::cout << "完成传输" << std::endl;
	getchar();
}
