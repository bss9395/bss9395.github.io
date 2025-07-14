################################################################################
### 显示信息对话框

# package require Tk
# 
# tk_messageBox -type ok -message "操作成功！" -title "提示" -icon info

################################################################################
### 显示“是/否”对话框

# package require Tk
# 
# set result [tk_messageBox -type yesno -message "是否继续？" -title "确认" -icon question]
# 
# if {$result == "yes"} {
#     puts "用户选择了“是”。"
# } else {
#     puts "用户选择了“否”。"
# }

################################################################################
### 显示“确定/取消”对话框

# package require Tk
# 
# set result [tk_messageBox -type okcancel -message "确定要删除吗？" -title "警告" -icon warning]
# 
# if {$result == "ok"} {
#     puts "用户选择了“确定”。"
# } else {
#     puts "用户选择了“取消”。"
# }

################################################################################
### 显示“中止/重试/忽略”对话框

# package require Tk
# 
# set result [tk_messageBox -type abortretryignore -message "操作失败！" -title "错误" -icon error]
# 
# switch $result {
#     "abort" { 
# 		puts "用户选择了“中止”。" 
# 	}
#     "retry" { 
# 		puts "用户选择了“重试”。"
# 	}
#     "ignore" { 
# 		puts "用户选择了“忽略”。" 
# 	}
# }

################################################################################
### 指定父窗口

package require Tk

tk_messageBox -parent . -type ok -message "这是一个子窗口的对话框。" -title "子窗口" -icon info
