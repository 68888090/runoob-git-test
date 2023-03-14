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
	//SOCKET fd = accept(Client.fd, NULL, NULL);//完成连接
	//client clone;
	//clone.fd	=   accept(Sever.fd, NULL, NULL);////现在还没有进行初始化对象client
	//SOCKET fd = accept(Sever.fd, NULL, NULL);/////没有连接项所以进行了卡壳
	printf("created successfully,require connection\n");
	//char recvbuf[1024];
	//int ret;
	int i = 0;
	 require req[20];
	 int recvtal=1;
	while (1) {
	// memset(req[i].method, 0, 1024);

		std::cout << "请输入您的请求" << std::endl;
		std::cin >> req[i].method;
		//std::string name{};
		//std::getline(std::cin >> std::ws, name);
		//scanf("%s", req[i].method);
		//getchar();
		//getchar();
		std::cin>> req[i].Cseq;
		//scanf("%s", req[i].Cseq);
		switch (*(req[i].method))
		{
		case 'O':
			//scanf("%s", req[i].zhengwen);
			std::cin >> req[i].zhengwen;
			//定义一个发送函数
			/// <summary>
				/// 再定义一个解析发送函数
				/// </summary>
			httpsend(Client.fd, req[i]);
			//////还没发
			if (SOCKET_ERROR == send(Client.fd, req[i].zhengwen, 1024, 0)) {

				printf("error\n send()can`t create new socket\n");
			}
			break;
		case 'S':
			std::cin >> req[i].transport >> req[i].client_port >> req[i].zhengwen;
			httpsend(Client.fd, req[i]);
			if (SOCKET_ERROR == send(Client.fd, req[i].transport, 1024, 0)) {

				printf("error\n send()can`t create new socket\n");
			}
			if (SOCKET_ERROR == send(Client.fd, req[i].client_port, 1024, 0)) {

				printf("error\n send()can`t create new socket\n");
			}
			if (SOCKET_ERROR == send(Client.fd, req[i].zhengwen, 1024, 0)) {

				printf("error\n send()can`t create new socket\n");
			}				
			break;
		case'P':std::cin >> req[i].Session_id >> req[i].ntp >> req[i].zhengwen;
			httpsend(Client.fd, req[i]);
			if (SOCKET_ERROR == send(Client.fd, req[i].Session_id, 1024, 0)) {

				printf("error\n send()can`t create new socket\n");
			}
			if (SOCKET_ERROR == send(Client.fd, req[i].ntp, 1024, 0)) {

				printf("error\n send()can`t create new socket\n");
			}
			if (SOCKET_ERROR == send(Client.fd, req[i].zhengwen, 1024, 0)) {

				printf("error\n send()can`t create new socket\n");
			}
			break;
		case'T':std::cin >> req[i].Session_id >> req[i].zhengwen;
			httpsend(Client.fd, req[i]);
			if (SOCKET_ERROR == send(Client.fd, req[i].Session_id, 1024, 0)) {

				printf("error\n send()can`t create new socket\n");
			}
			if (SOCKET_ERROR == send(Client.fd, req[i].zhengwen, 1024, 0)) {

				printf("error\n send()can`t create new socket\n");
			}
			
			
			break;
		default:
			break;

		}
	
		char recvvv[1024];
		/// <summary>
		/// recv解决不了循环发送的问题
		/// </summary>
		//while (recvtal > 0) {

		//	recv(Client.fd, recvvv, 1024, 0);
		//	std::cout << recvvv << std::endl;////循环接收
		//	recvtal = recv(Client.fd, recvvv, 1024, 0);
		//}////////接收时的问题
		switch (*(req[i].method))
		{
		case'O':
				recv(Client.fd, recvvv, 1024, 0);
				std::cout << recvvv << std::endl;////循环接收
				break;
		case 'S':
			recv(Client.fd, recvvv, 1024, 0);
			std::cout << recvvv << std::endl;////循环接收
			recv(Client.fd, recvvv, 1024, 0);
			std::cout << recvvv << std::endl;////循环接收
			break;
		case'P':
			recv(Client.fd, recvvv, 1024, 0);
			std::cout << recvvv << std::endl;////循环接收
			recv(Client.fd, recvvv, 1024, 0);
			std::cout << recvvv << std::endl;////循环接收
			recv(Client.fd, recvvv, 1024, 0);
			std::cout << recvvv << std::endl;////循环接收
			recv(Client.fd, recvvv, 1024, 0);
			std::cout << recvvv << std::endl;////循环接收
			break;
		case'T':
			recv(Client.fd, recvvv, 1024, 0);
			std::cout << recvvv << std::endl;////循环接收
			goto A;
			//break;
		default:
			break;
		}
		i++;
		//getchar();
	}
	//ret = recv(Client.fd, recvbuf, 1024, 0);//////启动，但是recv的数据在哪不知
	//
 //                
	//std::cout << recvbuf << std::endl;
	//if (SOCKET_ERROR == send(Client.fd,"客户端接收到了您的请求", 48, 0)) {//////启动，但是send发送到何处不知
	//	printf("error\n send()can`t create new socket\n");
	//}//https://learn.microsoft.com/zh-cn/windows/win32/api/winsock2/nf-wi
	//
	//printf("created successfully,wait for connect\n");
	//if (ret == 0)
	//{
	//	printf("服务器正常下线\n");
	//}
	//else if (ret <= 0)
	//{
	//	printf("服务器非正常下线\n");
	//}
	//std::cout << "完成传输" << std::endl;
	A:
	closesocket(Client.fd);
	closeinit();
	getchar();
}
