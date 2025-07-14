################################################################################

### 鼠标点击事件

# package require Tk
# 
# button .btn -text "Click Me"
# bind .btn <Button-1> {
# 	puts "Button clicked!"
# }
# pack .btn

################################################################################

### 键盘事件

# package require Tk
# 
# entry .entry
# bind .entry <KeyPress> {
# 	# %K是事件替换符，表示按键。
# 	puts "Key pressed: %K"    
# }
# pack .entry

################################################################################

### 窗口事件

# package require Tk
# 
# bind . <Configure> {
# 	puts "Window resized or moved"
# }

################################################################################

### 事件替换符

# package require Tk
# 
# bind . <Motion> {
# 	# %x和%y是事件替换符，表示鼠标的X和Y坐标。
# 	puts "Mouse at: %x %y"
# }

################################################################################

### 多事件绑定

package require Tk

bind . <Button-1> {
	puts "Left click"
}
bind . <Button-3> {
	puts "Right click"
}

