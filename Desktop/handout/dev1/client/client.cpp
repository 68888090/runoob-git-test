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
	addr.sin_addr.S_un.S_addr = inet_addr(ip);//��ip��ַ
	if (INVALID_SOCKET == connect(fd, (struct sockaddr*)&addr, sizeof(addr)))
		printf("error\n connect()can`t create new socket\n");

	///////ת��sockaddr_in��sockaddr����

}
void main() {
	createinit();
	client Client("127.0.0.1");
	//client clone;
	//clone.fd	=   accept(Sever.fd, NULL, NULL);////���ڻ�û�н��г�ʼ������client
	//SOCKET fd = accept(Sever.fd, NULL, NULL);/////û�����������Խ����˿���
	printf("created successfully,require connection\n");
	char recvbuf[1024];
	int ret;
	ret = recv(Client.fd, recvbuf, 1024, 0);//////����������recv���������Ĳ�֪
	SOCKET fd = accept(Client.fd, NULL, NULL);/////û�����������Խ����˿���
	printf("created successfully,wait for connect\n");
	if (ret == 0)
	{
		printf("��������������\n");
	}
	else if (ret <= 0)
	{
		printf("����������������\n");
	}
	
	                     
	std::cout << recvbuf << std::endl;
	if (SOCKET_ERROR == send(Client.fd,"�ͻ��˽��յ�����������", 12, 0)) {//////����������send���͵��δ���֪
		printf("error\n send()can`t create new socket\n");
	}//https://learn.microsoft.com/zh-cn/windows/win32/api/winsock2/nf-wi
	std::cout << "��ɴ���" << std::endl;
	closesocket(Client.fd);
	closeinit();
	getchar();
}
