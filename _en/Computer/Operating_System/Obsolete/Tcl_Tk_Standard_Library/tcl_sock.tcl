# 创建一个TCP服务器，监听端口12345
# 当有客户端连接时，调用acceptConnection过程。
# 将套接字的可读事件绑定到readData过程，读取客户端发送的数据。
# 当客户端断开连接时，关闭套接字并输出提示信息。

socket -server acceptConnection 12345
proc acceptConnection {sock addr port} {
	puts "Connection accepted from $addr:$port"
	fileevent $sock readable [list readData $sock]
}
proc readData {sock} {
	set data [read $sock]
	if {[eof $sock]} {
		close $sock
		puts "Connection closed."
	} else {
		puts "Received data: $data"
	}
}
vwait forever