################################################################################
### 基本用法

# package require Tk
# 
# spinbox .spinbox -from 0 -to 100
# pack .spinbox

################################################################################
### 设置增量值

# package require Tk
# 
# spinbox .spinbox -from 0 -to 100 -increment 5
# pack .spinbox

################################################################################
### 使用可选值列表

# package require Tk
# 
# spinbox .spinbox -values {10 20 30 45 50}
# pack .spinbox

################################################################################
### 绑定命令

# package require Tk
# 
# spinbox .spinbox -from 0 -to 100 -command {
# 	puts "Current value: [.spinbox get]"
# }
# pack .spinbox

################################################################################
### 动态配置控件

# package require Tk
# 
# spinbox .spinbox -from 0 -to 100
# pack .spinbox
# 
# button .changeRangeBtn -text "Change Range" -command {
# 	.spinbox configure -from 0 -to 200
# }
# pack .changeRangeBtn

################################################################################
### 输入验证

package require Tk

spinbox .spinbox -from 0 -to 100 -validate key -validatecommand {
	set value [string trimleft %P "0"]
	if {0 == [string length $value] || [string is integer $value] && 0 <= $value && $value <= 100} {
		return 1
	} else {
		return 0
	}
}
pack .spinbox
