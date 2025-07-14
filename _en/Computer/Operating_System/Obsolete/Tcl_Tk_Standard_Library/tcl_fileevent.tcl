################################################################################

### 读取文件

# set file [open "tcl_fileevent.tcl" r]
# fileevent $file readable {
# 	if {[gets $file line] >= 0} {
# 		puts "Read line: $line"
# 	} else {
# 		close $file
# 		puts "File read complete."
# 	}
# }
# 
# vwait forever

################################################################################

### 管道通信，与子进程交互

# # 在windows上dir报错，cmd可使用。
# set pipe [open "|cmd" r]
# fileevent $pipe readable {
# 	if {[gets $pipe line] > 0} {
# 		puts "Output: $line"
# 	} else {
# 		close $pipe
# 		puts "Process completed."
# 	} 
# }
# vwait forever

################################################################################

### 写入文件

set file [open "output.txt" w]
fileevent $file writable {
	puts $file "Hello, World!"
	close $file
	puts "Write complete."
}
vwait forever


