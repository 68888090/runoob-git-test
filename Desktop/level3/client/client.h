#pragma once
#include"tcpsocket.h"
#include<stdlib.h>
class client
{
public:
	SOCKET fd;
	client(const char* ip);
};

