################################################################################
### 自定义事件

# package require Tk
# 
# event add <<MyEvent>> <Button-1>;    # 鼠标左键
# event add <<MyEvent>> <Button-3>;    # 鼠标右键 
# bind . <<MyEvent>> {
# 	puts "Custom event triggered"
# }
# after 50 {
# 	event generate . <<MyEvent>>
# }

################################################################################
### 生成和处理自定义事件

# package require Tk
# 
# proc onCustomEvent {args} {
#     puts "Custom event triggered with args: $args"
# }
# 
# bind . <<CustomEvent>> {
# 	onCustomEvent %d
# }
# after 50 { 
# 	event generate . <<CustomEvent>> -data {arg1 arg2}
# }

################################################################################
### 模拟鼠标点击按钮

# package require Tk
# 
# button .b -text "Click Me"
# bind .b <Button-1> {
# 	puts "Button clicked!"
# }
# pack .b
# after 50 {
# 	event generate .b <Button-1> -x 10 -y 10
# }

################################################################################
### 模拟键盘事件

# package require Tk
# 
# event add <<CustomEvent>> <KeyPress>
# 
# entry .e
# pack .e
# bind .e <<CustomEvent>> {
# 	puts "Key pressed: %K"
# }
# focus .e
# 
# after 1000 {
# 	event generate .e <KeyPress> -keycode 65
# }

################################################################################
### 触发自定义事件

package require Tk

button .b -text "Click Me"
event add <<MyEvent>> <Control-Button-1>
bind .b <<MyEvent>> {
	puts "Custom event triggered!"
}
pack .b

after 50 {
	event generate .b <Control-Button-1>
}
