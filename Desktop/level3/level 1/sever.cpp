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
	int j = 0;
	while (1) {
		SOCKET fd = accept(Sever.fd, NULL, NULL);/////����ȡ����ʱ�����߳�
		if (fd == INVALID_SOCKET)
		{
			printf("error\n accept()can`t create new socket\n");
		}
		 std::thread t(pthread, fd);

		t.detach();
	}
	//if (SOCKET_ERROR == send(fd, t, 12, 0)) {//////����������send���͵��δ���֪
	//	printf("error\n send()can`t create new socket\n");
	//}//https://learn.microsoft.com/zh-cn/windows/win32/api/winsock2/nf-winsock2-send
	//char recvbuf[1024];
	//memset(recvbuf, 0, 1024);
	//int ret;
	//ret = recv(fd, recvbuf, 1024, 0);//////����������recv���������Ĳ�֪
	//std::cout << recvbuf << std::endl;
	
	closesocket(Sever.fd);
	//close_Socket();
	closeinit();
	/*delete(t);
	t = NULL;*/
}
