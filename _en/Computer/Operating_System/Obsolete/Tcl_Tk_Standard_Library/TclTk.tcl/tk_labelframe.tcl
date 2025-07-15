################################################################################
### 基本用法

# package require Tk
# 
# labelframe .lf -text "Options"
# button .lf.btn1 -text "Option1"
# button .lf.btn2 -text "Option2"
# pack .lf.btn1 .lf.btn2
# pack .lf

################################################################################
### 自定义样式

# package require Tk
# 
# labelframe .lf -text "Settings" -labelanchor nw -relief groove -background "#F0F0F0" -foreground "blue"
# button .lf.btn1 -text "Setting 1"
# button .lf.btn2 -text "Setting 2"
# pack .lf.btn1 .lf.btn2
# pack .lf

################################################################################
### 使用grid布局

# package require Tk
# 
# labelframe .lf -text "Controls"
# button .lf.btn1 -text "Start"
# button .lf.btn2 -text "Stop"
# grid .lf.btn1 -row 0 -column 0
# grid .lf.btn2 -row 0 -column 1
# pack .lf

################################################################################
###

# package require Tk
# 
# labelframe .lf -text "Controls"
# button .lf.btn1 -text "Start"
# button .lf.btn2 -text "Stop"
# grid .lf.btn1 -row 0 -column 0
# grid .lf.btn2 -row 0 -column 1
# pack .lf
# 
# set labelWidget [.lf cget -labelwidget]
# puts "labelWidget = $labelWidget";    # 默认情况下，labelframe使用内置的标签部件，因此cget -labelwidget返回空字符串

################################################################################
###

package require Tk

ttk::labelframe .frame -text "Frame" 
button .frame.btn -text "Button"
label .frame.lbl -text "Label"
pack .frame -fill both -expand 1
pack .frame.lbl

bind . <Configure> {	
	set scaling [tk scaling]
	set scaling 1.5
	set frm_width  [winfo width .frame]
	set btn_width  [winfo width .frame.btn]
	set btn_height [winfo height .frame.btn]
	puts "scaling = $scaling, frm_width = $frm_width, btn_width = $btn_width, btn_height = $btn_height"
	
	set x_offset [expr {$scaling * 24}]
	set y_offset [expr {$scaling * 20}]
	place .frame.btn -x [expr {$frm_width - $btn_width - $x_offset}] -y [expr {-$y_offset/2 - $btn_height/2}]
	update idletasks
	puts "y = [winfo y .frame.btn]"
}


