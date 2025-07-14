################################################################################
### 基本单选按钮

# package require Tk
# 
# set choice "Option1"
# radiobutton .rb1 -text "Option 1" -variable choice -value "Option1"
# radiobutton .rb2 -text "Option 2" -variable choice -value "Option2"
# pack .rb1 .rb2

################################################################################
### 动态更新状态

# package require Tk
# 
# set choice "Option1"
# radiobutton .rb1 -text "Option 1" -variable choice -value "Option1"
# radiobutton .rb2 -text "Option 2" -variable choice -value "Option2"
# pack .rb1 .rb2
# 
# after 2000 {
# 	set choice "Option2"
# }

################################################################################
### 禁用单选按钮

# package require Tk
# 
# set choice "Option1"
# radiobutton .rb1 -text "Option 1" -variable choice -value "Option1"
# radiobutton .rb2 -text "Option 2" -variable choice -value "Option2" -state disabled
# pack .rb1 .rb2

################################################################################
### 事件绑定

package require Tk

set choice "Option1"
radiobutton .rb1 -text "Option 1" -variable choice -value "Option1" -command {
	puts "Selected: $choice"
}
radiobutton .rb2 -text "Option 2" -variable choice -value "Option2" -command {
	puts "Selected: $choice"
}
pack .rb1 .rb2
