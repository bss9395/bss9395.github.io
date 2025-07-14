################################################################################
### 水平布局

# package require Tk
# 
# panedwindow .pw -orient horizontal
# frame .pw.left -background "red" -width 100
# frame .pw.right -background "blue" -width 100
# .pw add .pw.left
# .pw add .pw.right
# pack .pw -fill both -expand true

################################################################################
### 垂直布局

package require Tk

# panedwindow .pw -orient vertical
# frame .pw.top -background "green" -height 100
# frame .pw.bottom -background "yellow" -height 100
# .pw add .pw.top
# .pw add .pw.bottom
# pack .pw -fill both -expand true

################################################################################
### 自定义分隔条

# package require Tk
# 
# panedwindow .pw -orient horizontal -sashrelief groove -sashwidth 5 -sashpad 2
# frame .pw.left -background "red" -width 100
# frame .pw.right -background "blue" -width 100
# .pw add .pw.left
# .pw add .pw.right
# pack .pw -fill both -expand true

################################################################################
### 动态添加和删除子部件

package require Tk

panedwindow .pw -orient horizontal
frame .pw.left -background "red" -width 100
frame .pw.right -background "blue" -width 100
.pw add .pw.left
.pw add .pw.right
pack .pw -fill both -expand true

.pw forget .pw.left

frame .pw.middle -background "green" -width 100
.pw add .pw.middle


