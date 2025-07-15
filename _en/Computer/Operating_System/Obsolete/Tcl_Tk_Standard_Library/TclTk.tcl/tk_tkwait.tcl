#############################################3##################################
### 等待变量变化

# package require Tk
# 
# set done 1
# button .btn -text "Click Me" -command {
# 	set done 0
# }
# pack .btn
# tkwait variable done
# puts "Button clicked!"

################################################################################
### 等待窗口可见

# package require Tk
# 
# toplevel .top
# button .top.btn -text "Close" -command {
# 	destroy .top
# }
# pack .top.btn
# tkwait visibility .top
# puts "Window .top is now visible!"

################################################################################
### 等待窗口销毁

package require Tk

toplevel .top
button .top.btn -text "Close" -command {
	destroy .top
}
pack .top.btn
tkwait window .top
puts "Window .top has been destroyed!"
