################################################################################
### 创建和使用自定义字体

# package require Tk
# 
# wm title . "字体示例"
# font create MyFont -family Arial -size 16 -weight bold -slant italic
# 
# label .label -text "这是自定义字体" -font MyFont
# pack .label -padx 20 -pady 20
# 
# tkwait window .

################################################################################
### 查询系统字体家族

# package require Tk
# 
# wm title . "字体家族查询"
# set families [font families]
# label .label -text "可用字体家族："
# pack .label -padx 20 -pady 20
# text .text -wrap word
# pack .text -fill both -expand 1
# foreach family $families {
# 	.text insert end "$family\n"
# }
# 
# tkwait window .

################################################################################
### 测量文本宽度

# package require Tk
# 
# wm title . "文本宽度测量"
# font create MyFont -family "Arial" -size 12
# set text "Hello, World!"
# set width [font measure MyFont $text]
# label .label -text "文本宽度：$width 像素"
# pack .label -padx 20 -pady 20
# 
# tkwait window .

################################################################################
### 配置现有字体

package require Tk

wm title . "字体配置"
font create MyFont -family "Arial" -size 12
label .label -text "这是原始字体" -font MyFont
pack .label -padx 20 -pady 20

after 2000 {
	font configure MyFont -size 16 -weight bold
	.label configure -font MyFont
}

tkwait window .
