
#include "tcpsocket.h"


//开始网络库的实现;
bool createinit() {
    WSADATA wsaData;
    int err = 1;

    //wVersionRequested = MAKEWORD(2, 2);

    err = (int)WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (err != 0) {
        printf("error!!!\nWSAStartup failed ");
        return false;
    }
    return true;



    /* The WinSock DLL is acceptable. Proceed. */

}

bool closeinit() {
    int err;
    err = WSACleanup();
    if (err != 0)
    {
        printf("error!!!\nWSACleanup failed ");
        return false;
    }
    return true;
}
void httpsend(SOCKET fd, require& req) {
    if (SOCKET_ERROR == send(fd, req.method, 1024, 0)) {

        printf("error\n send()can`t create new socket\n");
    }
    ////char intermediary[100] = { '\0' };
    ////sprintf(intermediary, "%d", req.Cseq);
    if (SOCKET_ERROR == send(fd, req.Cseq, 1024, 0)) {

        printf("error\n send()can`t create new socket\n");
    }
}


void httprecvO(SOCKET fd, require& req)
{
    int ret;
    //ret = recv(fd, req.method, 1024, 0);//////启动，但是recv的数据在哪不知
    //char intermediary[100] = { '\0' };
    //ret = recv(fd, intermediary, 1024, 0);//////启动，但是recv的数据在哪不知
    //req.Cseq = atoi(intermediary);
    ret = recv(fd, req.Cseq, 1024, 0);
    ret = recv(fd, req.zhengwen, 1024, 0);
}
void httprecvS(SOCKET fd, require& req)
{
    int ret;
    //ret = recv(fd, req.method, 1024, 0);//////启动，但是recv的数据在哪不知
    //char intermediary[100] = { '\0' };
    //ret = recv(fd, intermediary, 1024, 0);//////启动，但是recv的数据在哪不知
    //req.Cseq = atoi(intermediary);
    ret = recv(fd, req.Cseq, 1024, 0);
    ret = recv(fd, req.transport, 1024, 0);
    ret = recv(fd, req.client_port, 1024, 0);
    ret = recv(fd, req.zhengwen, 1024, 0);
    ///////返回一个随机的号

}
void httprecvP(SOCKET fd, require& req)
{
    int ret;
   // ret = recv(fd, req.method, 1024, 0);//////启动，但是recv的数据在哪不知
    //char intermediary[100] = { '\0' };
    //ret = recv(fd, intermediary, 1024, 0);//////启动，但是recv的数据在哪不知
    //req.Cseq = atoi(intermediary);
    ret = recv(fd, req.Cseq, 1024, 0);
    ret = recv(fd, req.Session_id, 1024, 0);
    ret = recv(fd, req.ntp, 1024, 0);
    ret = recv(fd, req.zhengwen, 1024, 0);
}
void httprecvT(SOCKET fd, require& req)
{
    int ret;
   // ret = recv(fd, req.method, 1024, 0);//////启动，但是recv的数据在哪不知
    //char intermediary[100] = { '\0' };
    //ret = recv(fd, intermediary, 1024, 0);//////启动，但是recv的数据在哪不知
    //req.Cseq = atoi(intermediary);
    ret = recv(fd, req.Cseq, 1024, 0);
    ret = recv(fd, req.Session_id, 1024, 0);
    ret = recv(fd, req.zhengwen, 1024, 0);
}

void pthread(SOCKET fd)
{
	require req[20];
	int ret;
	int Session_id;
	int flag = 0;///用来看sess是否传出
	char* p;



	char respnod[1024] = { "TCP 0.5  200 OK\n%s\nsomething\nsomething\n\n" };





	std::string miyao;
	int i = 0;

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
			sprintf(respnod, "TCP 0.5  200 OK\n%s\nWe have four ways :OPTION SETUP PLAY TEARDOWN\\n", req[i].Cseq);
			send(fd, respnod, 1024, 0);

			//send(fd, "", 0, 0);
			std::cout << req[i].zhengwen << std::endl;
			break;

		case 'S':httprecvS(fd, req[i]);
			//std::cin >> req[i].transport >> req[i].client_port >> req[i].zhengwen;
			//std::cout << "建立连接,请接收您的私人秘钥" << std::endl;
			//send(fd, "建立连接,请接收您的私人秘钥", 1024, 0);

			miyao = std::to_string(Session_id);//数字向字符的转换
			p = const_cast<char*>(miyao.c_str());
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
					sprintf(respnod, "TCP 0.5  200 OK\n%s\n%s\n your private key is addmitted\nnow you will accept some vedios\n\n", req[i].Cseq, req[i].Session_id);
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
A:closesocket(fd);
}

void inchars(char* p)
{
    int i = 0;
    while ((p[i] = getchar()) != '\n')
    {

        i++;
    }
    p[i] = '\0';
    // return p;
}
