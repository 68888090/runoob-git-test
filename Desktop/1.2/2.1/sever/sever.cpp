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
	SOCKET fd= accept(Sever.fd, NULL, NULL);/////没有连接项所以进行了卡壳、、、、
	if (fd == INVALID_SOCKET)
	{
		printf("error\n accept()can`t create new socket\n");
	}
	 require req[20];
	int i = 0;
	int ret;
	int Session_id;
	int flag = 0;///用来看sess是否传出
	char* p;



	char respnod[1024] = { "TCP 0.5  200 OK\n%s\nsomething\nsomething\n\n" };
	


	srand(time(NULL));

	std::string miyao;
	/// <summary>
	/// //实际上就是这辆进行连接
	/// </summary>
	printf("created successfully,wait for connect\n");
	//std::cout << "请输入您想要传输的数据\n" << std::endl;
	while (1)
	{
		if (!flag)
		{
			Session_id = rand() % 10000;
		}
		/// <summary>
		/// 先进行req.method方法的判断来进行什么样的接受
		/// </summary>
		
		ret = recv(fd, req[i].method, 1024, 0);////依据不同的方法来进行不同的数据接收
		switch (*(req[i].method))
		{
		case 'O':httprecvO(fd, req[i]);
			sprintf(respnod, "TCP 0.5  200 OK\n%s\nWe have four ways :OPTION SETUP PLAY TEARDOWN\\n",req[i].Cseq);
			send(fd, respnod, 1024, 0);

			//send(fd, "", 0, 0);
			std::cout << req[i].zhengwen << std::endl;
			break;

		case 'S':httprecvS(fd, req[i]);
			//std::cin >> req[i].transport >> req[i].client_port >> req[i].zhengwen;
			//std::cout << "建立连接,请接收您的私人秘钥" << std::endl;
			//send(fd, "建立连接,请接收您的私人秘钥", 1024, 0);
		
			miyao=std:: to_string(Session_id);//数字向字符的转换
			 p=const_cast<char*>(miyao.c_str());
			 strcpy(req[i].Session_id, p);
			 sprintf(respnod, "TCP 0.5  200 OK\n%s\n%s\nis your private key\n\n", req[i].Cseq, req[i].Session_id);
			 send(fd, respnod, 1024, 0);

			 std::cout << req[i].zhengwen << std::endl;
			break;
		case'P':
			httprecvP(fd, req[i]);
			for (int j = 0; j < 20; j++)
			{
				if (!strcmp(req[i].Session_id, req[j].Session_id)) {
					sprintf(respnod,  "TCP 0.5  200 OK\n%s\n%s\n your private key is addmitted\nnow you will accept some vedios\n\n", req[i].Cseq, req[i].Session_id);
					send(fd, respnod, 1024, 0);
					//send(fd, "开始从", 1024, 0);
					//send(fd, req[i].ntp, 1024, 0);
					//send(fd, "播放", 1024, 0);
					break;

					///如何实现连续发送问题
				}
			}
			std::cout << req[i].zhengwen << std::endl;
			break;
			//std::cin >> req[i].Session_id >> req[i].ntp >> req[i].zhengwen;break;
		case'T':
			httprecvO(fd, req[i]);
			for (int j = 0; j < 20; j++)
			{
				if (!strcmp(req[i].Session_id, req[j].Session_id)) {
					sprintf(respnod, "TCP 0.5  200 OK\n%s\n%s\nsever accept your quit\n", req[i].Cseq, req[i].Session_id);
					send(fd, respnod, 1024, 0);
					std::cout << req[i].zhengwen << std::endl;
					goto A;
				}
			}
			
			break;
			//std::cin >> req[i].Session_id >> req[i].zhengwen;break;
		default:
			break;

		}
		
		//std::cout << req[i].method << std::endl;
		//std::cout << req[i].Cseq << std::endl;
		//std::cout << req[i].zhengwen << std::endl;
		//getchar();
		i++;
	}
	//char* t = new char[1024];
	//std::cin >> t;
	A:
	//if (SOCKET_ERROR == send(fd, t, 12, 0)) {//////启动，但是send发送到何处不知
	//	printf("error\n send()can`t create new socket\n");
	//}//https://learn.microsoft.com/zh-cn/windows/win32/api/winsock2/nf-winsock2-send
	//char recvbuf[1024];
	//memset(recvbuf, 0, 1024);
	//int ret;
	//ret = recv(fd, recvbuf, 1024, 0);//////启动，但是recv的数据在哪不知
	//std::cout << recvbuf << std::endl;
	closesocket(fd);
	closesocket(Sever.fd);
	//close_Socket();
	closeinit();
	/*delete(t);
	t = NULL;*/
}
