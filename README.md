# 请看各分支任务
计算机网络知识
1.	网络层次划分
标准的OSI七层模型以外，常见的网络层次划分还有TCP/IP四层协议以及TCP/IP五层协议
2. OSI七层网络模型
1）物理层（Physical Layer）: 中继器（Repeater，也叫放大器）和集线器。
2）数据链路层（Data Link Layer）: 如何将数据组合成数据块，在数据链路层中称这种数据块为帧（frame）: 网桥和交换机。
3）网络层（Network Layer）: 路由器
4）传输层（Transport Layer）: 网关


3.IP
4. 子网掩码及网络划分
子网掩码将IP地址分为网络位为与主机位


如果两个IP地址在子网掩码的按位与的计算下所得结果相同，即表明它们共属于同一子网中。
子网掩码的计算？
疑点：已知ip地址如何求子网掩码
，，，子网掩码是同ip地址一同给出的，用来计算网段，查看网络位于主机位的
所以关于子网掩码的计算就在于已知主机位来倒推1的网络位是多少
主机位要注意加上3，分别是网关，网址与广播地址



TCP/IP协议
Ip用于给本地址与接受地址
Tcp协议连接部分
SYN同步位（表示1时为连接请求）
ACK确认位(1时表示连接有效，0时表示为连接无效)
ack 确认号(对方发送序号加1)
seq序号（序号随即生成，每一次传递都会进行加1）
FAN断开连接（为1时断开连接）
握手部分
（客户端）先请求在连接（服务端），（服务端）再发出请求，（客服端）再连接
断开部分
（客户端）说明断开（服务端）表明收到说明，（服务端）后来发出断开连接，（客户端）表示收到信息，断开。
每次两端独立发送时都会伴随一个随即生成的序号seq，随后当另一端回发时，会发出ack=seq+1，表明该端接受到请求，后发出另一个seq，等待另一端发出ack=seq+1来判断是否另一端接受到请求
Udp协议




Level one 
疑点：在使用同一开发环境下的不同文件如何查看他们的IP地址与创建他们的接口
难点 ：Socket编程下各类变量与函数的使用

现解决方法，在微软文档内查询winsock2的库函数以及相关使用
