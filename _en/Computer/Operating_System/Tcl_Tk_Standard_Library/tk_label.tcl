################################################################################
### 显示静态文本

# package require Tk
# 
# label .label -text "Hello, Tcl/Tk!"
# grid .label

################################################################################
### 显示图像

# package require Tk
# package require Img
# 
# image create photo logo -file "images/colorpicker.gif"
# label .label -image logo
# grid .label

################################################################################
### 动态更新内容

# package require Tk
# 
# set msg "Initial Message"
# label .label -textvariable msg
# grid .label
# 
# after 2000 {
# 	set msg "Updated Message"
# }

################################################################################
### 文本和图像结合

# package require Tk
# package require Img
# 
# image create photo icon -file "images/colorpicker.gif"
# label .label -text "Click Me" -image icon -compound center
# grid .label

################################################################################
### 设置字体和颜色

# package require Tk
# 
# label .label -text "Styled Label" -font {Arial 12 bold} -fg red -bg yellow
# grid .label

################################################################################
### 文本换行

package require Tk

label .label -text "This is a long text that will wrap automatically." -wraplength 100
grid .label
