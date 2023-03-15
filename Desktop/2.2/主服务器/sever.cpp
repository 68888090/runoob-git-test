#include "sever.h"
#include"tcpsocket.h"
#include<time.h>
sever::sever() {
	fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);//第一个参数代表使用的是IPV4地址，
	//第二个代表使用流式套接字，第三个代表我们使用TCP协议,
	if (fd==INVALID_SOCKET)
	{
		printf("error\n socket()can`t create new socket\n");
	}
	///在构造器中绑定socket
	///////为什么不能绑定ip号与端口号
	struct sockaddr_in addr;//////使用类型sockaddr变成使用socketaddr类型导致错误
	addr.sin_family = AF_INET;///////////////////////////////////////////////////////////绑定家族
	addr.sin_port =htons( PORT);//大小端的转换问题,网络字节序与本地字节序的转换//////////绑定端口
	addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");///////////绑定ip地址//////////问题/////ip地址的格式问题
	if (SOCKET_ERROR == bind(fd, (struct sockaddr*)&addr, sizeof(addr))) {
		printf("error\n bind()can`t create new socket\n");
	}
	
	listen(fd, 5);
	printf(" sever is created successfully\n");
	}
void main() {
	createinit();
	sever Sever;
	//client clone; 
	//clone.fd	=   accept(Sever.fd, NULL, NULL);////现在还没有进行初始化对象client
	srand(time(NULL));
	int j = 0;
	//std::thread t[10];

	while (1) {
		SOCKET fd = accept(Sever.fd, NULL, NULL);/////当获取连接时开启线程
		if (fd == INVALID_SOCKET)
		{
			printf("error\n accept()can`t create new socket\n");
		}
		 std::thread t(pthread, fd);

		t.detach();
		
	}
	//if (SOCKET_ERROR == send(fd, t, 12, 0)) {//////启动，但是send发送到何处不知
	//	printf("error\n send()can`t create new socket\n");
	//}//https://learn.microsoft.com/zh-cn/windows/win32/api/winsock2/nf-winsock2-send
	//char recvbuf[1024];
	//memset(recvbuf, 0, 1024);
	//int ret;
	//ret = recv(fd, recvbuf, 1024, 0);//////启动，但是recv的数据在哪不知
	//std::cout << recvbuf << std::endl;
	
	closesocket(Sever.fd);
	//close_Socket();
	closeinit();
	/*delete(t);
	t = NULL;*/
}
