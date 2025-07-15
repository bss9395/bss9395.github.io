################################################################################
### 完全自定义对话框

# package require Tk
# 
# proc custom_message_box {args} {
# 	proc command_button {text} {
# 		set ::custom_result $text
# 		destroy .custom_dialog
# 	}
# 	set ::custom_result ""
# 
# 	set parent .
# 	set title ""
# 	set message ""
# 	set buttons {}
# 	for {set i 0} {$i < [llength $args]} {incr i} {
# 		set arg [lindex $args $i]
# 		switch $arg {
# 			"-parent" {
# 				set parent [lindex $args [incr i]]
# 			}
# 			"-title" {
# 				set title [lindex $args [incr i]]
# 			}
# 			"-message" {
# 				set message [lindex $args [incr i]]
# 			}
# 			"-buttons" {
# 				set buttons [lindex $args [incr i]]
# 			}
# 			default {
# 				puts "未知选项: $arg"
# 			}
# 		}
# 	}
# 
#     toplevel .custom_dialog
#     wm title .custom_dialog $title
#     label .custom_dialog.lbl -text $message
#     pack .custom_dialog.lbl -padx 20 -pady 10 -side top
# 
# 	set it 0
# 	foreach text $buttons {
# 		set name [format "%s%d" "button" $it]
# 		incr it
# 		button .custom_dialog.$name -text $text -command [list command_button $text]
# 		pack .custom_dialog.$name -side left -padx 10 -pady 10
# 	}
# 
# 	raise .custom_dialog $parent
#     tkwait window .custom_dialog
#     return $::custom_result
# }
# 
# set result [custom_message_box -parent . -title "自定义对话框" -message "这是一个自定义对话框" -buttons {"继续" "退出" "取消"}]
# puts "用户选择了：$result"

################################################################################
### 自定义按钮文本

# package require Tk
# 
# set result [tk_dialog .dialog "自定义对话框" "这是一个自定义对话框。" question 1 "继续" "退出" "取消"]
# 
# switch $result {
#     0 { puts "用户选择了“继续”。" }
#     1 { puts "用户选择了“退出”。" }
#     2 { puts "用户选择了“取消”。" }
# }

################################################################################
### 模态对话框

package require Tk

proc dismiss {} {
    grab release .dlg
    destroy .dlg
}

grid [ttk::entry .e]
toplevel .dlg
grid [ttk::button .dlg.b -text "Done" -command dismiss]
wm protocol .dlg WM_DELETE_WINDOW dismiss
wm transient .dlg .    ; # dialog window is related to main
tkwait visibility .dlg ; # can't grab until window appears, so we wait
grab set .dlg          ; # ensure all input goes to our window
tkwait window .dlg     ; # block until window is destroyed
puts "after..."
