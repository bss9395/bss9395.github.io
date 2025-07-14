################################################################################
### 基本示例

# package require Tk
# 
# wm title . "Notebook示例"
# ttk::notebook .nb
# pack .nb -fill both -expand 1
# 
# frame .nb.frame1
# label .nb.frame1.label -text "这是标签页1"
# pack .nb.frame1.label -padx 20 -pady 20
# .nb add .nb.frame1 -text "标签页 1"
# 
# frame .nb.frame2
# label .nb.frame2.label -text "这是标签页2"
# pack .nb.frame2.label -padx 20 -pady 20
# .nb add .nb.frame2 -text "标签页 2"
# 
# tkwait window .

################################################################################
### 动态添加和删除标签页

# package require Tk
# 
# wm title . "动态botebook"
# ttk::notebook .nb
# pack .nb -fill both -expand 1
# 
# frame .buttons 
# pack .buttons -fill x
# button .buttons.add -text "添加标签页" -command {
# 	set index [.nb index end]
# 	set frame [frame .nb.frame$index]
# 	label $frame.label -text "这是标签页 $index"
# 	pack $frame.label -padx 20 -pady 20
# 	.nb add $frame -text "标签页 $index"
# }
# pack .buttons.add -side left -padx 5
# 
# button .buttons.delete -text "删除标签页" -command {
# 	set index [.nb select]
# 	if {$index != ""} {
# 		puts "index = $index"
# 		.nb forget $index
# 		destroy $frame
# 	}
# }
# pack .buttons.delete -side left -padx 5
# 
# tkwait window .

################################################################################
### 配置标签页属性

package require Tk

wm title . "配置标签页"
ttk::notebook .nb
pack .nb -fill both -expand 1

frame .nb.frame1
label .nb.frame1.label -text "这是标签页 1"
pack .nb.frame1.label -padx 20 -pady 20
.nb add .nb.frame1 -text "标签页 1" -underline 3 

frame .nb.frame2
label .nb.frame2.label -text "这是标签页 2"
pack .nb.frame2.label -padx 20 -pady 20
.nb add .nb.frame2 -text "标签页 2"

puts ".nb class = [winfo class .nb]"
.nb tab .nb.frame1 -text "标题1"
.nb itemconfigure .nb.frame2 -text "标题2"


tkwait window .
