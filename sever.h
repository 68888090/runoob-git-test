#pragma once
#include"tcpsocket.h"
//绑定ip与端口
//创建端口

class sever
{
public:
	SOCKET fd;
	
	sever();

};
//进行输入项目
//使用函数模板与重载函数来进行多功能输入
//template<class T>
//char* inputsta() {
//	//std::cout << "请输入您想要传输的数据" << std::endl;
//	char* t=new char[1024];
//	std::cin >> t;
//	return t;
//}
////////////////////////实践发现模板函数是不同意没有实参的这样不符合模板定义





/// <summary>
/// 失败的，重载函数看的是后面的形参的种类。而我的模板函数是没有形参的，所以无法使用
///所以选择使用特化的方式去书写 
/// 
///
/// </summary>
/// <returns></returns>
//template<>
//char* inputsta<char*>() {
//	std::cout << "请输入您想要传输的数据" << std::endl;
//	T t;
//}
///没有这样的顾虑ios是一个输出流，无关类型
///
////////
////

