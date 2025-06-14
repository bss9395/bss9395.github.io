################################################################################
###

# package require Tk
# 
# button .btn1 -text "Button 1"
# button .btn2 -text "Button 2"
# label .lbl -text "Label"
# 
# pack .btn1 .btn2 .lbl
# 
# # 获取当前窗口的所有子小部件
# set children [winfo children .]
# 
# # 遍历子小部件并打印信息
# foreach child $children {
#     puts "Child: $child, Class: [winfo class $child], Width: [winfo width $child], Height: [winfo height $child]"
# }

################################################################################
###

# package require Tk
# 
# puts "color depth=[winfo screendepth .]([winfo screenvisual .])"
# puts "pixels per inch=[winfo pixels . 1i]"
# puts "width=[winfo screenwidth .] height=[winfo screenheight .]"
# 
# set tk_scaling [tk scaling]
# puts "tk scaling = $tk_scaling"
# set scale [expr {[winfo pixels . 1i] / 96.0}]
# puts "scale=$scale"

################################################################################
### 获取小部件的顶层窗口

# package require Tk
# 
# toplevel .main
# wm title .main "winfo toplevel 示例"
# 
# ttk::frame .main.frame
# pack .main.frame -fill both -expand 1
# 
# button .main.frame.button -text "按钮"
# pack .main.frame.button
# 
# set toplevel [winfo toplevel .main.frame.button]
# puts "按钮的顶层窗口: $toplevel" 
# 
# tkwait window .main

################################################################################
### 获取顶层窗口自身

# package require Tk
# 
# toplevel .main
# wm title .main "winfo toplevel 示例"
# 
# set toplevel [winfo toplevel .main]
# puts "主窗口的顶层窗口: $toplevel" 
# 
# tkwait window .main

################################################################################
### 在嵌套结构中获取顶层窗口

# package require Tk
# 
# toplevel .main
# wm title .main "winfo toplevel 示例"
# 
# ttk::frame .main.frame
# pack .main.frame -fill both -expand 1
# 
# ttk::frame .main.frame.subframe
# pack .main.frame.subframe -fill both -expand 1
# 
# button .main.frame.subframe.button -text "按钮"
# pack .main.frame.subframe.button
# 
# set toplevel [winfo toplevel .main.frame.subframe.button]
# puts "按钮的顶层窗口: $toplevel"
# 
# tkwait window .main

################################################################################
### 获取按钮的父窗口

package require Tk

toplevel .main
wm title .main "winfo parent 示例"

frame .main.frame

button .main.frame.button -text "按钮"

set parent [winfo parent .main.frame.button]

label .main.label -text "按钮的父窗口是: $parent"
pack .main.frame .main.frame.button .main.label

tkwait window .main
