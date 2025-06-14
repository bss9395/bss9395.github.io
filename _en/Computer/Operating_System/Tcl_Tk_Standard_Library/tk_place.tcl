################################################################################
### 绝对位置

# package require Tk
# 
# button .btn -text "Click Me"
# place .btn -x 50 -y 100

################################################################################
### 相对位置

# package require Tk
# 
# button .btn -text "Clicke Me"
# place .btn -relx 0.5 -rely 0.5 -anchor center

################################################################################
### 相对大小

# package require Tk
# 
# button .btn -text "Click Me"
# place .btn -relx 0.3 -rely 0.6 -relwidth 0.4 -relheight 0.4 -anchor center

################################################################################
### 混合使用

# package require Tk
# 
# button .btn -text "Click Me"
# place .btn -x 50 -y 100 -width 200 -height 100

################################################################################
### 删除place布局

package require Tk

button .btn -text "Click Me"
place .btn -x 50 -y 100 -width 200 -height 100

place forget .btn 

