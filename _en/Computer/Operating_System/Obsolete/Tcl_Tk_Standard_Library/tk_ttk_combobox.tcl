################################################################################
### 基本下拉选择框

# package require Tk
# 
# ttk::combobox .cb -state readonly -values {
# 	"Option1" 
# 	"Option2"
# 	"Option3"
# }
# pack .cb

################################################################################
### 绑定变量

# package require Tk
# set selectedOption "Option 1"
# ttk::combobox .cb -textvariable selectedOption -values {
# 	"Option1"
# 	"Option2"
# 	"Option3"
# }
# pack .cb
# 
# button .btn -text "Submit" -command {
# 	puts "Selected: $selectedOption"
# }
# pack .btn

################################################################################
### 动态更新选项

# package require Tk
# ttk::combobox .cb -values {
# 	"Option 1"
# 	"Option 2"
# 	"Option 3"
# }
# pack .cb
# 
# button .btn -text "Update Options" -command {
# 	set li [.cb cget -values]
# 	puts $li
# 	set li [linsert $li 2 "New Option"]
# 	puts $li
# 	.cb configure -values $li
# }
# pack .btn

################################################################################
### 手动输入值

# package require Tk
# 
# ttk::combobox .cb -state normal -values {
# 	"Option 1"
# 	"Option 2"
# 	"Option 3"
# }
# pack .cb

################################################################################
### 设置样式

package require Tk

ttk::combobox .cb -width 20 -font {Arial 12 bold} -foreground red -background blue -values {
	"Option 1"
	"Option 2"
	"Option 3"
}
pack .cb
