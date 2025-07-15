################################################################################
### 基本按钮

# package require Tk
# 
# # 若仅有文字，则-width与-height为文字宽度与高度
# # 若有图像，则-width与-height为像素宽度与高度
# button .btn -text "Click Me" -command {
# 	puts "Button clicked!"
# }
# pack .btn

################################################################################
### 显示图像

# package require Tk
# 
# set dpi [winfo pixels . 1i]
# set scale [expr {$dpi / 96.0}]
# set size [expr {int(20 * $scale)}]
# puts "size = $size"
# 
# source "Tk_ScaleImage.tcl"
# set icon [scaleImage "images/Luffy.png" 100 100]
# 
# # 若仅有文字，则-width与-height为文字宽度与高度
# # 若有图像，则-width与-height为像素宽度与高度
# button .btn -image $icon -width $size -height $size - -command {
# 	puts "Button clicked!"
# }
# grid .btn

################################################################################
### 文本和图像结合

# package require Img
# 
# set dpi [winfo pixels . 1i]
# set scale [expr {$dpi / 96.0}]
# set size [expr {int(20 * $scale)}]
# puts "size = $size"
# 
# source "Tk_ScaleImage.tcl"
# set icon [scaleImage "images/Luffy.png" $size $size]
# 
# # 若仅有文字，则-width与-height为文字宽度与高度
# # 若有图像，则-width与-height为像素宽度与高度
# button .btn -text "Clicke Me" -height 10 -image $icon -compound left -command {
# 	puts "Button clicked!"
# }
# grid .btn

################################################################################
### 动态更新按钮文本

# package require Tk
# 
# set btnText "Clicke Me"
# button .btn -textvariable btnText -command {
# 	set btnText "Clicked!"
# }
# grid .btn

################################################################################
### 禁用按钮

# package require Tk
# 
# button .btn -text "Click Me" -state disabled
# grid .btn

################################################################################
### 设置样式

# package require Tk
# 
# button .btn -text "Styled Button" -font {Arial 12 bold} -fg white -bg blue -relief raised
# grid .btn

################################################################################
### 默认按钮

# package require Tk
# 
# button .action -text "Action" -default active -command {
# 	puts "Clicked!"
# }
# bind . <Return> {
# 	.action invoke
# }
# grid .action

################################################################################
### 样式

package require Tk

# 创建主窗口
set mainWindow [toplevel .main]

# 创建按钮
set myButton [button $mainWindow.myButton -text "点击我" -relief flat -overrelief flat -command {
    puts "按钮被点击了！"
}]

# 将按钮放置在主窗口中
pack $myButton

# 进入主事件循环
tkwait window $mainWindow


