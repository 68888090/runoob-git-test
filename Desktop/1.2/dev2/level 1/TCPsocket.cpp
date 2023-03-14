
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
