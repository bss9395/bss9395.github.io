################################################################################
### 创建简单的 Frame

package require Tk

wm title . "ttk::frame 示例"

ttk::frame .frame -borderwidth 2 -relief raised -padding {10 5}
pack .frame -fill both -expand 1

button .frame.button -text "按钮"
# pack .frame.button

tkwait window .


