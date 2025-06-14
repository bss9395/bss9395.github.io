################################################################################
### 基本用法

# package require Tk
# 
# ttk::progressbar .progressbar -orient horizontal -length 200 -mode determinate -maximum 100 -value 50
# pack .progressbar

################################################################################
### 动态更新进度

# package require Tk
# 
# set progress 0
# ttk::progressbar .progressbar -orient horizontal -length 200 -mode determinate -maximum 100 -variable progress
# pack .progressbar
# 
# button .startBtn -text "Start" -command {
# 	for {set i 0} {$i <= 100} {incr i} {
# 		set progress $i
# 		update 
# 		after 100
# 	}
# }
# pack .startBtn

################################################################################
### 不确定进度

# package require Tk
# 
# ttk::progressbar .progressbar -orient horizontal -length 200 -mode indeterminate -value 50 -maximum 100
# pack .progressbar
# 
# button .startBtn -text "Start" -command {
# 	.progressbar start
# }
# button .stopBtn -text "Stop" -command {
# 	.progressbar stop
# }
# pack .startBtn .stopBtn

################################################################################
### 垂直进度条

package require Tk

ttk::progressbar .progressbar -orient vertical -length 200 -mode determinate -maximum 100 -value 50
pack .progressbar

