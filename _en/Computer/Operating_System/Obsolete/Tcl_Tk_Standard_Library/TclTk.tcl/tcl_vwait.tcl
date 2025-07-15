################################################################################
### 事件驱动程序

# set done 0
# 
# after 3000 {
# 	set done 1
# }
# 
# vwait done
# 
# puts "Event loop exited."

################################################################################
### 结合文件事件

set file [open "test.txt" w]

# vwait会等待文件变为可写状态，然后处理文件事件。
fileevent $file writable {
	puts "File is writable"
	close $file
	set done 1
}

vwait done

puts "File event handled."
