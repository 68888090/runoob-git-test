
#ifndef _TCPSOCKET_H_
#define _TCPSOCKET_H_
#include<WinSock2.h>
#pragma comment(lib,"ws2_32.lib")


#endif  _TCPSOCKET_H_
#include<stdio.h>
#include<string.h>
#include<iostream>
#include"sever.h"
//#include"client.h"
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