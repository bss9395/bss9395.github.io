################################################################################
### 基本复选框

# package require Tk
# 
# checkbutton .chk -text "Enable Feature" -variable featureEnabled
# grid .chk

################################################################################
### 显示图像

# package require Tk
# 
# image create photo icon -file "images/colorpicker.gif"
# checkbutton .chk -image icon -variable featureEnabled
# grid .chk

################################################################################
### 文本和图像结合

# package require Tk
# 
# image create photo icon -file "images/colorpicker.gif"
# checkbutton .chk -text "Enable Feature" -image icon -compound left -variable featureEnabled
# grid .chk

################################################################################
### 动态更新状态

# package require Tk
# 
# set featureEnabled 0
# checkbutton .chk -text "Enable Feature" -variable featureEnabled
# grid .chk
# 
# after 2000 {
# 	set featureEnabled 1
# }

################################################################################
### 禁用复选框

# package require Tk
# 
# checkbutton .chk -text "Enable Feature" -state disabled
# grid .chk

################################################################################
### 事件绑定

package require Tk

ttk::checkbutton .chk -text "Enable Feature" -variable featureEnabled -onvalue "on" -offvalue "off"  -command {
	puts "Checkbox state: $featureEnabled"
}
grid .chk

# set featureEnabled 2
# .chk configure -state alternate
puts [.chk configure]
