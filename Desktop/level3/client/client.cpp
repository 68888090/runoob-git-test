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
	 for (int ij = 0; ij < 20; ij++)
	 {
		 strcpy(req[ij].method, "");
		 strcpy(req[ij].Cseq, "");
		 strcpy(req[ij].transport, "");
		 strcpy(req[ij].client_port, "");
		 strcpy(req[ij].Session_id, "");
		 strcpy(req[ij].ntp, "");
		 strcpy(req[ij].zhengwen, "");
	 }
	 require* p=NULL;
	 int recvtal=1;
	 char nh[4];
	// std::string str;
	
	while (1) {
	// memset(req[i].method, 0, 1024);

		std::cout << "��������������" << std::endl;
		inchars(req[i].method);
		//std::cin >> req[i].method;
		//std::string name{};
		//std::getline(std::cin >> std::ws, name);
		//scanf("%s", req[i].method);
		//getchar();
		//getchar();
		inchars(req[i].Cseq);

		//std::cin>> req[i].Cseq;
		//scanf("%s", req[i].Cseq);
		switch (*(req[i].method))
		{
		case 'O':
			//scanf("%s", req[i].zhengwen);
			inchars(req[i].zhengwen);

			//dCseq(&req[i], i);
			//std::cin >> req[i].zhengwen;
			//����һ�����ͺ���
			/// <summary>
				/// �ٶ���һ���������ͺ���
				/// </summary>
			httpsend(Client.fd, req[i]);
			//////��û��
			if (SOCKET_ERROR == send(Client.fd, req[i].zhengwen, 1024, 0)) {

				printf("error\n send()can`t create new socket\n");
			}
			create(&p, req[i]);
			break;
		case 'S':
			inchars(req[i].transport);
			inchars(req[i].client_port);
			inchars(req[i].zhengwen);
	
			//std::cin >> req[i].transport >> req[i].client_port >> req[i].zhengwen;
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
			create(&p, req[i]);
			break;
		case'P':
			inchars(req[i].Session_id);
			inchars(req[i].ntp);
			inchars(req[i].zhengwen);

			//std::cin >> req[i].Session_id >> req[i].ntp >> req[i].zhengwen;
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
			create(&p, req[i]);
			break;
		case'T':
			inchars(req[i].Session_id);
			inchars(req[i].zhengwen);

			//std::cin >> req[i].Session_id >> req[i].zhengwen;
			httpsend(Client.fd, req[i]);
			if (SOCKET_ERROR == send(Client.fd, req[i].Session_id, 1024, 0)) {

				printf("error\n send()can`t create new socket\n");
			}
			if (SOCKET_ERROR == send(Client.fd, req[i].zhengwen, 1024, 0)) {

				printf("error\n send()can`t create new socket\n");
			}
			create(&p, req[i]);
			break;
		case 'D':
			inchars(req[i].Session_id);
			httpsend(Client.fd, req[i]);
			if (SOCKET_ERROR == send(Client.fd, req[i].Session_id, 1024, 0)) {

				printf("error\n send()can`t create new socket\n");
			}
			create(&p, req[i]);
			break;
		default:
			std::cout << "�����޷���������������" << std::endl;
			
			break;

		}
	
		char recvvv[1024];

		switch (*(req[i].method))
		{
		case'O':
				recv(Client.fd, recvvv, 1024, 0);
				std::cout << recvvv << std::endl;////ѭ������
				break;
		case 'S':
			recv(Client.fd, recvvv, 1024, 0);
			std::cout << recvvv << std::endl;////ѭ������
	
			break;
		case'P':
			recv(Client.fd, recvvv, 1024, 0);
			std::cout << recvvv << std::endl;////ѭ������
			for (int l = 0; l < 6; l++)
			{
				recv(Client.fd, recvvv, 1024, 0);
				std::cout << recvvv << std::endl;////ѭ������
				Sleep(1000);
			}//////�ߴν���
			break;
		case'T':
			recv(Client.fd, recvvv, 1024, 0);
			std::cout << recvvv << std::endl;////ѭ������


			goto A;
		case'D':
			
			recv(Client.fd, recvvv, 1024, 0);
			std::cout << recvvv << std::endl;////ѭ������
			recv(Client.fd, nh, 1024, 0);
			//std::stringstream *ss;
			//*ss << nh;

			Sleep(500);
			if (!strcmp(recvvv, "ƥ��ʧ�ܣ�session����"))
			{
				break;
			}
			else
			{
				for (int il = 0; il < 4*7; il++)
				{
					recv(Client.fd, recvvv, 1024, 0);
					std::cout << recvvv << std::endl;////ѭ������
				}
			}
			break;
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
	int watch = 0;
	std::cout << "�Ƿ�鿴��ʷ��¼,1Ϊ�鿴������Ϊ���鿴" << std::endl;
	//��������

	std::cin >> watch;/////////////////////////////////////////////////�����ļ�
	if (watch==1)
	{
		printstruct(p);
	}getchar();
	//FILE* fp;
	//if ((fp = fopen("Cookie,txt", "wb")) == NULL)
	//{
	//	std::cout << "��ʧ��" << std::endl;
	//}
	//int session = 0;
	//fwrite(req[i].Session_id, sizeof(req[i].Session_id), 1, fp);
	//while (session < i)
	//{
	//	fwrite(&req[session], sizeof(require), 1, fp);
	//	session++;
	//}
	free(p);
	closesocket(Client.fd);
	//closeinit();                 
	getchar();
	//char  o = '\r\n';
}
