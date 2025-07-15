################################################################################
### 自定义 TButton 样式

# package require Tk
# 
# wm title . "ttk::style 示例"
# 
# ttk::style configure TButton -background green -foreground white -font {Arial 12}
# ttk::style map TButton -background [list active blue]
# 
# ttk::button .button -text "自定义按钮"
# pack .button -pady 20
# 
# tkwait window .

################################################################################
### 切换主题

# package require Tk
# 
# wm title . "ttk::style 主题示例"
# 
# ttk::button .button -text "切换主题"
# pack .button -pady 20
# 
# .button configure -command {
#     set current_theme [ttk::style theme use]
#     if {$current_theme == "clam"} {
#         ttk::style theme use alt
#     } else {
#         ttk::style theme use clam
#     }
# }
# 
# tkwait window .

################################################################################
### 获取所有可用主题

package require Tk

set names [ttk::style theme names]
puts "names = $names"
set use   [ttk::style theme use]
puts "use   = $use"
