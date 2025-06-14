################################################################################
### 非模态调用与回调调用

# package require Tk
# 
# grid [ttk::label .l -text "Hello World" -font {helvetica 24}] -padx 10 -pady 10
# proc font_changed {font} {
# 	.l configure -font $font
# }
# tk fontchooser configure -font {helvetica 24} -command font_changed
# tk fontchooser show

################################################################################
### 基本用法

# package require Tk
# 
# variable font ""
# tk fontchooser configure -command "set font"
# tk fontchooser show
# 
# if {$font != ""} {
#     puts "Selected font: $font"
# } else {
#     puts "No font selected."
# }

################################################################################
### 指定初始字体

# package require Tk
# 
# variable font ""
# tk fontchooser configure -parent . -title "Choose Font" -command "set font"
# tk fontchooser show
# 
# if {$font != ""} {
#     puts "Selected font: $font"
# } else {
#     puts "No font selected."
# }

################################################################################
### 完整示例

package require Tk

label .lbl -text "Sample Text"
button .btn -text "Change Font" -command {
    variable font ""
	tk fontchooser configure -title "Choose Font" -command "set font"
	tk fontchooser show

    if {$font != ""} {
        .lbl configure -font $font
    }
}
pack .lbl .btn
