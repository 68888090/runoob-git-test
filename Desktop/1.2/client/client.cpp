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
	//SOCKET fd = accept(Client.fd, NULL, NULL);//�������
	//client clone;
	//clone.fd	=   accept(Sever.fd, NULL, NULL);////���ڻ�û�н��г�ʼ������client
	//SOCKET fd = accept(Sever.fd, NULL, NULL);/////û�����������Խ����˿���
	printf("created successfully,require connection\n");
	//char recvbuf[1024];
	//int ret;
	int i = 0;
	 require req[20];
	 int recvtal=1;
	while (1) {
	// memset(req[i].method, 0, 1024);

		std::cout << "��������������" << std::endl;
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
			//����һ�����ͺ���
			/// <summary>
				/// �ٶ���һ���������ͺ���
				/// </summary>
			httpsend(Client.fd, req[i]);
			//////��û��
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
		/// recv�������ѭ�����͵�����
		/// </summary>
		//while (recvtal > 0) {

		//	recv(Client.fd, recvvv, 1024, 0);
		//	std::cout << recvvv << std::endl;////ѭ������
		//	recvtal = recv(Client.fd, recvvv, 1024, 0);
		//}////////����ʱ������
		switch (*(req[i].method))
		{
		case'O':
				recv(Client.fd, recvvv, 1024, 0);
				std::cout << recvvv << std::endl;////ѭ������
				break;
		case 'S':
			recv(Client.fd, recvvv, 1024, 0);
			std::cout << recvvv << std::endl;////ѭ������
			recv(Client.fd, recvvv, 1024, 0);
			std::cout << recvvv << std::endl;////ѭ������
			break;
		case'P':
			recv(Client.fd, recvvv, 1024, 0);
			std::cout << recvvv << std::endl;////ѭ������
			recv(Client.fd, recvvv, 1024, 0);
			std::cout << recvvv << std::endl;////ѭ������
			recv(Client.fd, recvvv, 1024, 0);
			std::cout << recvvv << std::endl;////ѭ������
			recv(Client.fd, recvvv, 1024, 0);
			std::cout << recvvv << std::endl;////ѭ������
			break;
		case'T':
			recv(Client.fd, recvvv, 1024, 0);
			std::cout << recvvv << std::endl;////ѭ������
			goto A;
			//break;
		default:
			break;
		}
		i++;
		//getchar();
	}
	//ret = recv(Client.fd, recvbuf, 1024, 0);//////����������recv���������Ĳ�֪
	//
 //                
	//std::cout << recvbuf << std::endl;
	//if (SOCKET_ERROR == send(Client.fd,"�ͻ��˽��յ�����������", 48, 0)) {//////����������send���͵��δ���֪
	//	printf("error\n send()can`t create new socket\n");
	//}//https://learn.microsoft.com/zh-cn/windows/win32/api/winsock2/nf-wi
	//
	//printf("created successfully,wait for connect\n");
	//if (ret == 0)
	//{
	//	printf("��������������\n");
	//}
	//else if (ret <= 0)
	//{
	//	printf("����������������\n");
	//}
	//std::cout << "��ɴ���" << std::endl;
	A:
	closesocket(Client.fd);
	closeinit();
	getchar();
}
