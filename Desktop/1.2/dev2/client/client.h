#pragma once
#include"tcpsocket.h"
class client
{
public:
	SOCKET fd;
	client(const char* ip);
};

