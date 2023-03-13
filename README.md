# level 1
Level one 
疑点：在使用同一开发环境下的不同文件如何查看他们的IP地址与创建他们的接口
难点 ：Socket编程下各类变量与函数的使用

现解决方法，在微软文档内查询winsock2的库函数以及相关使用
使用https://learn.microsoft.com/zh-cn/windows/win32/api/winsock2/网址来进行函数的查看与使用
还与视频结合加强练习
疑点：对WSASData结构的认识问题，以及wsasdata对我们开始双端连接的重要性
疑点：socket数据结构的使用，开始时服务端的创建与绑定问题
绑定时端口的大小端的转换问题,网络字节序与本地字节序的转换
ip地址的指定问题，因为addr.sin_addr.S_un.S_addr是一个ULONG形，而ip是一个字符串，无法进行指定，又不想用ADDR_ANY来使用（发现inet_addr转换函数）
////还没有进行初始化对象client
	//没有连接项所以进行了卡壳,直接无法进行程序，检查成本增加
  启动，但是send发送到何处不知，recv接收不到问题（实际上没有对接收数据进行输出）
  git远程传输
  疑点：再次登录如何进行用户再绑定（实际上是不会主动解除绑定），更换分支时，ls后发现分支中依旧是原分支的内容
  重点：各函数的使用与具体意义
  1.bind(s,name,namelen)
[in] s

标识未绑定套接字的描述符。

[in] name

指向要分配给绑定套接字的本地地址的 sockaddr 结构的指针。

[in] namelen

名称参数指向的值的长度（以字节为单位）。
2.listen(s,backing)
[in] s

标识绑定的未连接套接字的描述符。

[in] backlog

挂起连接队列的最大长度。
3.connect(s,name,namelen)
[in] s

标识未连接套接字的描述符。

[in] name

指向应建立连接的 sockaddr 结构的指针。

[in] namelen

名称参数指向的 sockaddr 结构的长度（以字节为单位）。
4.accept(s,addr,addrlen)
[in] s

一个描述符，用于标识已使用 侦听 函数处于侦听状态的套接字。 连接实际上是使用 接受返回的套接字建立的。

[out] addr

指向接收连接实体地址（称为通信层）的缓冲区的可选指针。 添加器参数的确切格式由创建 sockaddr 结构中的套接字时建立的地址系列确定。

[in, out] addrlen

指向包含 addr 参数指向的结构长度的整数的可选指针。
到此是两端之间的连接部分
5.send(s,buf,len,flags)
[in] s

标识连接的套接字的描述符。

[in] buf

指向包含要传输的数据的缓冲区的指针。

[in] len

buf 参数指向的缓冲区中数据的长度（以字节为单位）。

[in] flags

一组指定调用方式的标志。 此参数是使用以下任一值的按位 OR 运算符构造的
6.recv(s,buf,len,flags)
[in] s

标识连接的套接字的描述符。

[out] buf

指向用于接收传入数据的缓冲区的指针。

[in] len

buf 参数指向的缓冲区的长度（以字节为单位）。

[in] flags

一组影响此函数行为的标志。 请参阅下面的备注。 有关此参数可能值的详细信息，请参阅“备注”部分。
