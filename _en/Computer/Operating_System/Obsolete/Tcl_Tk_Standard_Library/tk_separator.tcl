################################################################################
### 水平分隔线

# package require Tk
# 
# wm title . "分隔线示例"
# 
# label .label1 -text "第一部分"
# pack .label1 -side top -pady 10
# 
# ttk::separator .sep -orient horizontal 
# pack .sep -side top -fill x -pady 10
# 
# label .label2 -text "第二部分"
# pack .label2 -side top -pady 10
# 
# tkwait window .

################################################################################
### 垂直分隔线

# package require Tk
# 
# wm title . "分隔线示例"
# frame .left
# frame .right 
# label .left.label -text "左侧内容"
# pack .left.label -side top -pady 10
# label .right.label -text "右侧内容"
# pack .right.label -side top -pady 10
# ttk::separator .sep -orient vertical
# pack .left -side left -fill y -padx 10
# pack .sep -side left -fill y -pady 10
# pack .right -side left -fill y -padx 10
# 
# tkwait window .

################################################################################
### 自定义样式

package require Tk

ttk::style configure Custom.Separator.TSeparator -background red

wm title . "自定义分隔线"
label .label1 -text "第一部分"
pack .label1 -side top -pady 10
ttk::separator .sep -orient horizontal -style Custom.Separator.TSeparator
pack .sep -fill x -pady 10
label .label2 -text "第二部分"
pack .label2 -side top -pady 10

tkwait window .
