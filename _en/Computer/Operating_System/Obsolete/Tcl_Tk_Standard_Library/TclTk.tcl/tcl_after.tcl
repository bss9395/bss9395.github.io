################################################################################

### 延迟执行

# puts "Start"
# after 2000 {
# 	puts "2 seconds later"
# }
# puts "End"

################################################################################

### 定时器（周期性执行）

# proc print_time {} {
# 	puts "Current time: [clock format [clock seconds]]"
# 	after 1000 print_time
# }
# 
# print_time

################################################################################

### 取消任务

# set timer [after 3000 {
# 	puts "This will not run"
# }]
# 
# after 1000 {
# 	after cancel $timer
# }

################################################################################

# 结合vwait实现异步等待

# set done 0
# after 2000 {
# 	set done 1
# }
# vwait done
# puts "2 seconds later"

################################################################################

### 动态调整定时器

# set count 0
# 
# proc increment {} {
# 	global count
# 	incr count
# 	puts "Count: $count"
# 	if {$count < 5} {
# 		after 1000 increment
# 	}
# }
# increment

################################################################################

### 在GUI中使用after

# package require Tk
# 
# label .lbl -text "Hello, World!"
# pack .lbl
# 
# after 2000 {
# 	.lbl configure -text "2 seconds later"
# }

################################################################################

vwait forever
