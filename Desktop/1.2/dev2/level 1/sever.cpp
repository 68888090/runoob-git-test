#include "sever.h"
#include"tcpsocket.h"
#include<time.h>
sever::sever() {
	fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);//��һ����������ʹ�õ���IPV4��ַ��
	//�ڶ�������ʹ����ʽ�׽��֣���������������ʹ��TCPЭ��,
	if (fd==INVALID_SOCKET)
	{
		printf("error\n socket()can`t create new socket\n");
	}
	///�ڹ������а�socket
	///////Ϊʲô���ܰ�ip����˿ں�
	struct sockaddr_in addr;//////ʹ������sockaddr���ʹ��socketaddr���͵��´���
	addr.sin_family = AF_INET;///////////////////////////////////////////////////////////�󶨼���
	addr.sin_port =htons( PORT);//��С�˵�ת������,�����ֽ����뱾���ֽ����ת��//////////�󶨶˿�
	addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");///////////��ip��ַ//////////����/////ip��ַ�ĸ�ʽ����
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
	//clone.fd	=   accept(Sever.fd, NULL, NULL);////���ڻ�û�н��г�ʼ������client
	SOCKET fd= accept(Sever.fd, NULL, NULL);/////û�����������Խ����˿��ǡ�������
	if (fd == INVALID_SOCKET)
	{
		printf("error\n accept()can`t create new socket\n");
	}
	 require req[20];
	int i = 0;
	int ret;
	int Session_id;
	int flag = 0;///������sess�Ƿ񴫳�
	char* p;
	srand(time(NULL));
	std::string miyao;
	/// <summary>
	/// //ʵ���Ͼ���������������
	/// </summary>
	printf("created successfully,wait for connect\n");
	//std::cout << "����������Ҫ���������\n" << std::endl;
	while (1)
	{
		if (!flag)
		{
			Session_id = rand() % 10000;
		}
		/// <summary>
		/// �Ƚ���req.method�������ж�������ʲô���Ľ���
		/// </summary>
		
		ret = recv(fd, req[i].method, 1024, 0);////���ݲ�ͬ�ķ��������в�ͬ�����ݽ���
		switch (*(req[i].method))
		{
		case 'O':httprecvO(fd, req[i]);
			send(fd, "���յ��������", 1024, 0);
			//send(fd, "", 0, 0);
			std::cout << req[i].zhengwen << std::endl;
			break;

		case 'S':httprecvS(fd, req[i]);
			//std::cin >> req[i].transport >> req[i].client_port >> req[i].zhengwen;
			//std::cout << "��������,���������˽����Կ" << std::endl;
			send(fd, "��������,���������˽����Կ", 1024, 0);
			miyao=std:: to_string(Session_id);//�������ַ���ת��
			 p=const_cast<char*>(miyao.c_str());
			 strcpy(req[i].Session_id, p);
			 send(fd, req[i].Session_id, 1024, 0);
			 std::cout << req[i].zhengwen << std::endl;
			break;
		case'P':
			httprecvP(fd, req[i]);
			for (int j = 0; j < 20; j++)
			{
				if (!strcmp(req[i].Session_id, req[j].Session_id)) {
					send(fd, "��Կ���ϣ����մ���", 1024, 0);
					send(fd, "��ʼ��", 1024, 0);
					send(fd, req[i].ntp, 1024, 0);
					send(fd, "����", 1024, 0);
					break;
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
					send(fd, "��Կ���ϣ��Ͽ�����", 1024, 0);
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
	//if (SOCKET_ERROR == send(fd, t, 12, 0)) {//////����������send���͵��δ���֪
	//	printf("error\n send()can`t create new socket\n");
	//}//https://learn.microsoft.com/zh-cn/windows/win32/api/winsock2/nf-winsock2-send
	//char recvbuf[1024];
	//memset(recvbuf, 0, 1024);
	//int ret;
	//ret = recv(fd, recvbuf, 1024, 0);//////����������recv���������Ĳ�֪
	//std::cout << recvbuf << std::endl;
	closesocket(fd);
	closesocket(Sever.fd);
	//close_Socket();
	closeinit();
	/*delete(t);
	t = NULL;*/
}
