################################################################################
### 保持GUI响应性

# package require Tk
# 
# button .btn -text "Start" -command {
# 	for {set i 0} {$i < 10} {incr i} {
# 		puts "Processing step $i"
# 		after 1000
# 		update
# 	}
# }
# pack .btn

################################################################################
### 强制刷新界面

# package require Tk
# 
# label .lbl -text "Initial Text"
# pack .lbl
# after 2000 {
# 	.lbl configure -text "Updated Text"
# 	update
# }

################################################################################
### 处理事件队列

# package require Tk
# 
# button .btn -text "Click Me" -command {
# 	puts "Button clicked"
# }
# after 1000 {
# 	update 
# 	puts "Event queue processed"
# }

################################################################################
### 仅处理空闲任务idletasks

package require Tk

label .lbl -text "Initial Text"
pack .lbl
after 2000 {
	.lbl configure -text "Updated Text"
	update idletasks
}


