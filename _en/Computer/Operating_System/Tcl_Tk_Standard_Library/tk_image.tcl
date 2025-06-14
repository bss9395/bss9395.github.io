################################################################################
### 在标签中显示图像

# package require Tk
# package require Img
# 
# image create photo logo -file "images/colorpicker.gif"
# label .l -image logo
# pack .l

################################################################################
### 在按钮中显示图像

# package require Tk
# package require Img
# 
# image create photo icon -file "images/colorpicker.gif"
# button .btn -imag icon -command {
# 	puts "Button clicked!"
# }
# pack .btn

################################################################################
### 在画布中显示图像

# package require Tk
# package require Img
# 
# image create photo bg -file "images/colorpicker.gif"
# canvas .c -width 300 -height 200
# .c create image 0 0 -anchor nw -image bg
# pack .c

################################################################################
### 动态更新图像

# package require Tk
# package require Img
# 
# image create photo img
# label .l -image img
# pack .l
# 
# proc updateImg {file} {
# 	img read $file
# }
# 
# updateImg "images/colorpicker.gif"
# after 2000 {
# 	updateImg "images/Luffy.png"
# }

################################################################################
### 删除图像

# package require Tk
# package require Img
# 
# image create photo img -file "images/colorpicker.gif"
# label .l -image img
# pack .l
# 
# after 2000 {
# 	image delete img
# 	image create photo img -file "images/Luffy.png"
# }

################################################################################
### 显示图片

package require Tk
package require Img

image create photo imgobj -file "images/colorpicker.gif"
label .label
pack .label
.label configure -image imgobj

