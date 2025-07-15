################################################################################
### 获取默认标签部件

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
### 设置并获取自定义标签部件

# package require Tk
# 
# labelframe .lf -text "Frame"
# button .lf.labelBtn -text "Custom Label"
# .lf configure -labelwidget .lf.labelBtn
# button .lf.btn -text "Button"
# pack .lf.btn
# pack .lf
# 
# set labelWidget [.lf cget -labelwidget]
# puts "labelWidget = $labelWidget"

################################################################################
### 动态修改标签部件

package require Tk

labelframe .lf
button .lf.labelBtn1 -text "Label 1"
button .lf.labelBtn2 -text "Label 2"
.lf configure -labelwidget .lf.labelBtn1
puts "Current label widget: [.lf cget -labelwidget]"
.lf configure -labelwidget .lf.labelBtn2
puts "Current label widget: [.lf cget -labelwidget]"
button .lf.btn -text "Button"
pack .lf.btn
pack .lf
