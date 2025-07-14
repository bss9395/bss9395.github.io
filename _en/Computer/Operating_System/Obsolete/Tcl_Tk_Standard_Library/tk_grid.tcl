################################################################################
### 复杂示例

# package require Tk
# 
# ttk::frame .c -padding "3 3 12 12"
# ttk::frame .c.f -borderwidth 5 -relief ridge -width 200 -height 200
# ttk::label .c.namelbl -text "Name"
# ttk::entry .c.name
# ttk::checkbutton .c.one -text "One" -variable one -onvalue 1; set one 1;
# ttk::checkbutton .c.two -text "Two" -variable two -onvalue 1; set two 0;
# ttk::checkbutton .c.three -text "Three" -variable three -onvalue 1; set three 1;
# ttk::button .c.ok -text "Okay"
# ttk::button .c.cancel -text "Cancel"
# 
# grid .c -column 0 -row 0 -sticky nsew
# grid .c.f -column 0 -row 0 -columnspan 3 -rowspan 2 -sticky nsew
# grid .c.namelbl -column 3 -row 0 -columnspan 2 -sticky nw -padx 5
# grid .c.name -column 3 -row 1 -columnspan 2 -sticky new -pady 5 -padx 5
# grid .c.one -column 0 -row 3
# grid .c.two -column 1 -row 3
# grid .c.three -column 2 -row 3
# grid .c.ok -column 3 -row 3
# grid .c.cancel -column 4 -row 3
# 
# grid columnconfigure . 0 -weight 1
# grid rowconfigure . 0 -weight 1
# grid columnconfigure .c 0 -weight 3
# grid columnconfigure .c 1 -weight 3
# grid columnconfigure .c 2 -weight 3
# grid columnconfigure .c 3 -weight 1
# grid columnconfigure .c 4 -weight 1
# grid rowconfigure .c 1 -weight 1
# 
# puts [grid slaves .c]
# puts [grid slaves .c -row 3]
# puts [grid slaves .c -column 0]
# puts [grid info .c.namelbl]

################################################################################
### 基本网格布局

# package require Tk
# button .btn1 -text "Button 1"
# button .btn2 -text "Button 2"
# button .btn3 -text "Button 3"
# button .btn4 -text "Button 4"
# 
# grid .btn1 -row 0 -column 0
# grid .btn2 -row 0 -column 1
# grid .btn3 -row 1 -column 0
# grid .btn4 -row 1 -column 1

################################################################################
### 跨行跨列

# package require Tk
# 
# button .btn1 -text "Button 1"
# button .btn2 -text "Button 2"
# button .btn3 -text "Button 3"
# 
# grid .btn1 -row 0 -column 0 -columnspan 2
# grid .btn2 -row 0 -column 0 -rowspan 2
# grid .btn3 -row 1 -column 1

################################################################################
### 对齐方式

# package require Tk
# 
# button .btn1 -text "Button 1"
# button .btn2 -text "Button 2"
# button .btn3 -text "Button 3"
# button .btn4 -text "Button 4"
# 
# grid .btn1 -row 0 -column 0 -sticky n
# grid .btn2 -row 0 -column 1 -sticky s
# grid .btn3 -row 1 -column 0 -sticky e
# grid .btn4 -row 1 -column 1 -sticky w

################################################################################
### 动态调整布局

# package require Tk
# 
# button .btn1 -text "Button 1"
# button .btn2 -text "Button 2"
# button .btn3 -text "Button 3"
# button .btn4 -text "Button 4"
# 
# grid .btn1 -row 0 -column 0 -sticky nsew
# grid .btn2 -row 0 -column 1 -sticky nsew
# grid .btn3 -row 1 -column 0 -sticky nsew
# grid .btn4 -row 1 -column 1 -sticky nsew
# 
# grid columnconfigure . 0 -weight 1
# grid columnconfigure . 1 -weight 1
# grid rowconfigure . 0 -weight 1
# grid rowconfigure . 1 -weight 1

################################################################################
### 基本用法

# package require Tk
# 
# button .btn -text "Click Me"
# grid .btn
# 
# button .hideBtn -text "Hide Button" -command {
# 	grid forget .btn
# }
# grid .hideBtn

################################################################################
### 动态显示和隐藏

# package require Tk
# 
# button .toggleBtn -text "Toggle Button" -command {
#     if {[winfo ismapped .btn]} {
#         grid forget .btn
#     } else {
#         grid .btn
#     }
# }
# grid .toggleBtn
# 
# button .btn -text "Click Me"
# grid .btn

################################################################################
### 隐藏多个控件

# package require Tk
# 
# button .btn1 -text "Button 1"
# button .btn2 -text "Button 2"
# grid .btn1 .btn2
# 
# button .hideAllBtn -text "Hide All Buttons" -command {
#     grid forget .btn1 .btn2
# }
# grid .hideAllBtn

################################################################################
### 重新布局

# package require Tk
# 
# button .btn1 -text "Button 1"
# button .btn2 -text "Button 2"
# grid .btn1 -row 0 -column 0
# grid .btn2 -row 0 -column 1
# 
# button .rearrangeBtn -text "Rearrange" -command {
# #    grid forget .btn1 .btn2
#     grid .btn1 -row 1 -column 0
#     grid .btn2 -row 2 -column 1
# }
# grid .rearrangeBtn -row 3 -column 0 -columnspan 2

################################################################################
### grid info

# package require Tk
# 
# toplevel .top
# button .top.btn -text "Clicke Me"
# grid .top.btn -row 0 -column 0 -ipadx 10 -ipady 10
# set info [grid info .top.btn]
# puts $info

################################################################################
###

# package require Tk
# 
# frame .frame
# frame .frame.frame
# button .frame.frame.button -text "button" -width 6 -height 2
# 
# pack .frame.frame.button -side top
# pack .frame.frame
# pack .frame
# 
# update
# 
# puts "geometry = [winfo geometry .frame.frame.button], reqheight = [winfo reqheight .frame.frame.button], reqwidth = [winfo reqwidth .frame.frame.button], height = [winfo height .frame.frame.button], width = [winfo width .frame.frame.button]"


################################################################################
### 

package require Tk

frame .frame
button .frame.button -text "Click Me"
pack .frame.button
pack .frame

update

puts "geometry = [winfo geometry .frame.button], reqheight = [winfo reqheight .frame.button], reqwidth = [winfo reqwidth .frame.button], height = [winfo height .frame.button], width = [winfo width .frame.button]"
