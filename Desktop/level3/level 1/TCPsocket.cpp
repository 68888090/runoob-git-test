
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
void httprecvD(SOCKET fd, require& req) {
	int ret;
	ret = recv(fd, req.Cseq, 1024, 0);
	ret = recv(fd, req.Session_id, 1024, 0);
}
void pthread(SOCKET fd)
{
	srand(time(NULL));
	require req[20];
	int ret;
	int Session_id;
	int flag = 0;///用来看sess是否传出
	char* p;
	FILE* fp;


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
		//std::cout << i << std::endl;
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
					for (int l = 0; l < 5; l++)
					{
						send(fd, ". . . . . . . . . . . . . . . . . . . . . . . . . . .\n ", 1024, 0);
						//send(fd, "12345678901234567890\n ", 40, 0);
						Sleep(1000);
					}
					send(fd, "发送完毕", 1024, 0);
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
			httprecvT(fd, req[i]);
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
		case'D':
			httprecvD(fd, req[i]);
			
	/*		if ((fp = fopen("Cookie.txt", "wb")) == NULL)
			{
				std::cout << "打开失败" << std::endl;
			}*/
			char sessionid[10];
			if ((fp = fopen("Cookie,txt", "rb")) == NULL)
			{
				std::cout << "打开失败" << std::endl;
			}
			fread(sessionid, sizeof(sessionid), 1, fp);
			if (!strcmp(sessionid,req[i].Session_id))
			{
				char nh[4];
				send(fd, "完成匹配,查看之前记录", 1024, 0);
				fread(nh,sizeof(nh),1,fp);
				send(fd, nh, 1024, 0);
				//////////////////////
				//Sleep(2000);
				require cookie;
				int session = 0;
				//for (int il = 0; il < 2; il++)
				while (session<4)
				{
					fread(&cookie, sizeof(require), 1, fp);
					send(fd, cookie.method, 1024, 0);
					send(fd, cookie.Cseq, 1024, 0);
					send(fd, cookie.transport, 1024, 0);
					send(fd, cookie.client_port, 1024, 0);
					send(fd, cookie.Session_id, 1024, 0);
					send(fd, cookie.ntp, 1024, 0);
					send(fd, cookie.zhengwen, 1024, 0);
					session++;
				}
			}
			else {
				send(fd, "匹配失败，session不符", 1024, 0);
			}
			fclose(fp);
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

	if ((fp = fopen("Cookie,txt", "wb")) == NULL)
	{
		std::cout << "打开失败" << std::endl;
	}
	int session = 0;
	char nh[4];
	miyao = std::to_string(i);//数字向字符的转换
	p = const_cast<char*>(miyao.c_str());
	strcpy(nh, p);
	fwrite(req[i].Session_id, sizeof(req[i].Session_id), 1, fp);
	fwrite(nh, sizeof(nh), 1, fp);
	while (session<4)
	{
		fwrite(&req[session], sizeof(require), 1, fp);
		session++;
	}//完成将所以的读取记录存入持久性cookie文件
	fclose(fp);
	closesocket(fd);
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
