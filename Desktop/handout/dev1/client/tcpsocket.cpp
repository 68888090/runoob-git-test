
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
