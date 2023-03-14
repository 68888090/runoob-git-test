#pragma once
#ifndef _TCPSOCKET_H_
#define _TCPSOCKET_H_

#pragma comment(lib,"ws2_32.lib")
#define WIN32_LEAN_AND_MEAN
#include<WinSock2.h>
#include<Windows.h>
#endif  _TCPSOCKET_H_
#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
#include"sever.h"
//#include"client.h"
////三对象实现过程
//第一个是网络库的开启与使用
// 第二个是服务器的建立，连接，监听，发送
//第三个是客户端的建立连接，与多个客户端·的同时使用问题
//
//网络库的开启
bool createinit();
//网络库的1关闭
bool closeinit();
#define PORT 1200
typedef struct {
	char method[1024];
	char Cseq[10];
	char transport[10];
	char client_port[10];
	char Session_id[10];
	char ntp[20];
	char zhengwen[1024];
}require;
void httpsend(SOCKET fd,  require& req);
void httprecvO(SOCKET fd,  require& req);
void httprecvS(SOCKET fd, require& req);
void httprecvP(SOCKET fd, require& req);
void httprecvT(SOCKET fd, require& req);
void inchars(char*);

