#pragma once
#ifndef _TCPSOCKET_H_
#define _TCPSOCKET_H_
#include<WinSock2.h>
#pragma comment(lib,"ws2_32.lib")


#endif  _TCPSOCKET_H_
#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
#include<malloc.h>
//#include"sever.h"
#include"client.h"
////������ʵ�ֹ���
//��һ���������Ŀ�����ʹ��
// �ڶ����Ƿ������Ľ��������ӣ�����������
//�������ǿͻ��˵Ľ������ӣ������ͻ��ˡ���ͬʱʹ������
//
//�����Ŀ���
bool createinit();
//������1�ر�
bool closeinit();
#define PORT 1200
/////�趨����ṹ
typedef struct Require{
	char method[1024];
	char Cseq[10];
	char transport[10];
	char client_port[10];
	char Session_id[10];
	char ntp[20];
	char zhengwen[1024];
	Require* next;
}require;
require* create(require** p,require&req);
void printstruct(require* p);

void httpsend(SOCKET fd, require& req);
void httprecvO(SOCKET fd, require& req);
void httprecvS(SOCKET fd, require& req);
void httprecvP(SOCKET fd, require& req);
void httprecvT(SOCKET fd, require& req);

void inchars(char*);