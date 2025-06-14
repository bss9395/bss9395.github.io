################################################################################

# set file [open "tcl_chan.tcl" r]
# chan event $file readable {
# 	if {[gets $file line] >= 0} {
# 		puts "Read line: $line"
# 	} else {
# 		close $file
# 		puts "File read complete."
# 	}
# }
# vwait forever

################################################################################
### 创建和配置通道

# set file [open "output.txt" w]
# chan configure $file -buffering line
# chan puts $file "Hello, World!"
# chan close $file

################################################################################
### 读取文件内容

# set file [open "output.txt" r]
# set data [chan read $file]
# puts $data
# chan close $file

################################################################################
### 检查文件是否到达末尾

# set file [open "tcl_chan.tcl" r]
# while {![chan eof $file]} {
# 	set line [chan gets $file]
# 	if {$line != ""} {
# 		puts $line
# 	}
# }
# chan close $file

################################################################################
### 刷新通道缓冲区

# set file [open "output.txt" w]
# chan puts $file "Hello, World!"
# chan flush $file
# chan close $file

################################################################################
### 移动文件指针

# set file [open "tcl_chan.tcl" r]
# set data [chan read $file 5]
# puts "First 5 bytes: $data"
# chan seek $file 0 start
# set data [chan read $file 5]
# puts "First 5 bytes again: $data"
# chan close $file

################################################################################
### 获取文件指针位置

set file [open "tcl_chan.tcl" r]
set data [chan read $file 10]
set pos [chan tell $file]
puts "Read 10 bytes, current position: $pos"
chan close $file

