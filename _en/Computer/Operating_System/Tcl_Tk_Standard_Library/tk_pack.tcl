################################################################################
### 基本用法

# package require Tk
# 
# button .btn1 -text "Button 1"
# button .btn2 -text "Button 2"
# button .btn3 -text "Button 3"
# 
# pack .btn1 .btn2 .btn3

################################################################################
### 设置排列方向

# package require Tk
# 
# button .btn1 -text "Button 1"
# button .btn2 -text "Button 2"
# button .btn3 -text "Button 3"
# button .btn4 -text "Button 4"
# 
# pack .btn1 -side left
# pack .btn2 -side right
# pack .btn3 -side top
# pack .btn4 -side bottom

################################################################################
### 填充空间

# package require Tk
# 
# button .btn1 -text "Button 1"
# button .btn2 -text "Button 2"
# 
# pack .btn1 -side left -fill y
# pack .btn2 -side right -fill both -expand true

################################################################################
### 动态调整布局

# package require Tk
# 
# button .btn1 -text "Button 1"
# button .btn2 -text "Button 2"
# 
# pack .btn1 -side left -fill both -expand true
# pack .btn2 -side right -fill both -expand true

################################################################################
###

package require Tk

frame .frame -background "green"
button .frame.button -text "button"
pack .frame.button

ttk::scrollbar .scroll 
pack .frame -side left -fill both -expand 1
pack .scroll -side right -fill y -expand 0

