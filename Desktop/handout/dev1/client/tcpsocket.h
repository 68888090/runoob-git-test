
#ifndef _TCPSOCKET_H_
#define _TCPSOCKET_H_
#include<WinSock2.h>
#pragma comment(lib,"ws2_32.lib")


#endif  _TCPSOCKET_H_
#include<stdio.h>
#include<string.h>
#include<iostream>
//#include"sever.h"
#include"client.h"
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