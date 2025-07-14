################################################################################
### 基本用法

# package require Tk
# 
# scale .scale -from 0 -to 100 -orient horizontal
# pack .scale

################################################################################
### 绑定变量和命令

# package require Tk
# 
# set value 50
# scale .scale -from 0 -to 100 -orient horizontal -variable value -command func
# pack .scale
# 
# proc func {arg} {
# 	puts "Current Value: $arg"
# }

################################################################################
### 添加标签和刻度

# package require Tk
# 
# scale .scale -length 300 -from 0 -to 100 -orient horizontal -label "Volume" -tickinterval 10
# pack .scale

################################################################################
### 动态配置控件

# package require Tk
# 
# scale .scale -from 0 -to 100 -orient horizontal
# pack .scale
# 
# button .changeRangeBtn -text "Change Range" -command {
# 	.scale configure -from 0 -to 200
# }
# pack .changeRangeBtn

################################################################################
### 垂直滑动条

# package require Tk
# 
# scale .scale -from 0 -to 100 -orient vertical -length 200
# pack .scale

################################################################################
### 复杂示例

package require Tk

grid [ttk::label .auto -textvariable num] -column 0 -row 0 -sticky we
grid [ttk::label .manual] -column 0 -row 1 -sticky we
ttk::scale .scale -orient horizontal -length 200 -from 1.0 -to 100.0 -variable num -command update_lbl
grid .scale -column 0 -row 2 -sticky we


proc update_lbl {val} {
	.manual configure -text "Scale at $val"
}
.scale set 20
