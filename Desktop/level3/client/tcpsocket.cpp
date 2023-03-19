
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
void httpsend(SOCKET fd,  require& req) {
    if (SOCKET_ERROR == send(fd, req.method, 1024, 0)) {

        printf("error\n send()can`t create new socket\n");
    }
    ////char intermediary[100] = { '\0' };
    ////sprintf(intermediary, "%d", req.Cseq);
    if (SOCKET_ERROR == send(fd,req.Cseq, 1024, 0)) {

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
   // ret = recv(fd, req.method, 1024, 0);//////启动，但是recv的数据在哪不知
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
    //ret = recv(fd, req.method, 1024, 0);//////启动，但是recv的数据在哪不知
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
    //ret = recv(fd, req.method, 1024, 0);//////启动，但是recv的数据在哪不知
    //char intermediary[100] = { '\0' };
    //ret = recv(fd, intermediary, 1024, 0);//////启动，但是recv的数据在哪不知
    //req.Cseq = atoi(intermediary);
    ret = recv(fd, req.Cseq, 1024, 0);
    ret = recv(fd, req.Session_id, 1024, 0);
    ret = recv(fd, req.zhengwen, 1024, 0);
}


void inchars(char* p)
{
    int i = 0;
    while ((p[i] = getchar())!='\n')
    {
        
        i++;
    }
    p[i] = '\0';
    // return p;
}

void printstruct(require* p) {
    while (p != NULL) {
        //printf("%s\n", p->a);
        //printf("%s\n", p->b);
        std::cout << p->method << std::endl;
        std::cout << p->Cseq << std::endl;
        std::cout << p->transport << std::endl;
        std::cout << p->client_port << std::endl;
        std::cout << p->Session_id << std::endl;
        std::cout << p->ntp << std::endl;
        std::cout << p->zhengwen << std::endl;
        p = p->next;
        //return p;
    }
}
require* create(require** p, require& req)
{
    require* book, * temp;
    static require* last;
    book = (require*)malloc(sizeof(require));
    strcpy(book->method, "");
    strcpy(book->Cseq, "");
    strcpy(book->transport, "");
    strcpy(book->Session_id, "");
    strcpy(book->ntp, "");
    strcpy(book->client_port, "");
    strcpy(book->zhengwen, "");
    switch (*req.method)
    {
    case 'O':
        strcpy(book->method, req.method);
        strcpy(book->Cseq, req.Cseq);
        strcpy(book->zhengwen, req.zhengwen);
        break;
    case 'S':
        strcpy(book->method, req.method);
        strcpy(book->Cseq, req.Cseq);
        strcpy(book->transport, req.transport);
        strcpy(book->client_port, req.client_port);
        strcpy(book->zhengwen, req.zhengwen);
        break;
    case 'P':
        strcpy(book->method, req.method);
        strcpy(book->Cseq, req.Cseq);
        strcpy(book->Session_id, req.Session_id);
        strcpy(book->ntp, req.ntp);
        strcpy(book->zhengwen, req.zhengwen);
        break;
    case 'T':
        strcpy(book->method, req.method);
        strcpy(book->Cseq, req.Cseq);
        strcpy(book->Session_id, req.Session_id);
        strcpy(book->zhengwen, req.zhengwen);
        break;
    case'D':
        strcpy(book->method, req.method);
        strcpy(book->Cseq, req.Cseq);
        strcpy(book->Session_id, req.Session_id);
        break;
    default:
        break;
    }


    //////////////////////////////////////////////////////////////////////有个问题不知道赋值的字符串是否需要赋值
    //strcat(book->method, "\0");
    //strcat(book->Cseq, "\0");
    //strcat(book->transport, "\0");
    //strcat(book->Session_id, "\0");
    //strcat(book->ntp, "\0");
    //strcat(book->zhengwen, "\0");
    //strcat(book->client_port, "\0");
    /// <summary>
    /// //完成赋值
    /// </summary>
    /// <param name="p"></param>
    /// <param name=""></param>
    /// <returns></returns>
    if (*p == NULL)
    {
        *p = book;
        book->next = NULL;

    }
    else {
        last->next = book;
        book->next = NULL;
    }
    last = book;
    return book;
}//尾插法