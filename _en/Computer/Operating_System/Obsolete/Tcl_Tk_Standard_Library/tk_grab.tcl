################################################################################
### 模态对话框

# package require Tk
# 
# wm title . "主窗口"
# button ..btn -text "打开对话框" -command {
#     toplevel .dialog
#     wm title .dialog "对话框"
#     grab set .dialog
#     button .dialog.btn -text "关闭" -command { 
# 		destroy .dialog 
# 	}
#     pack .dialog.btn
# }
# pack .btn
# 
# tkwait window .

################################################################################
### 释放抓取

# package require Tk
# 
# wm title . "主窗口"
# button .btn -text "打开对话框" -command {
#     toplevel .dialog
#     wm title .dialog "对话框"
# 	  wm transient .dialog .
#     grab set .dialog
#     button .dialog.btn -text "关闭" -command {
#         grab release .dialog
#         # destroy .dialog
#     }
#     pack .dialog.btn
# }
# pack .btn
# 
# tkwait window .

################################################################################
### 全局抓取

package require Tk

wm title . "主窗口"
button .btn -text "全局抓取" -command {
	toplevel .dialog
	wm title .dialog "对话框"
	wm transient .dialog .
    grab set -global .dialog    ;# 全局抓取在某些操作系统或窗口管理器中可能不受支持。
	puts [grab status .dialog]
    button .dialog.btn -text "关闭" -command {
		grab release .dialog
		# destroy .dialog
	}
	pack .dialog.btn
}
pack .btn
tkwait window .
