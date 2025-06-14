################################################################################
### 基本用法

# package require Tk
# 
# set color [tk_chooseColor]
# 
# if {$color != ""} {
#     puts "Selected color: $color"
# } else {
#     puts "No color selected."
# }

################################################################################
### 指定初始颜色

# package require Tk
# 
# set color [tk_chooseColor -initialcolor "#FFF000"]
# 
# if {$color != ""} {
#     puts "Selected color: $color"
# } else {
#     puts "No color selected."
# }

################################################################################
### 指定父窗口和标题

# package require Tk
# 
# set color [tk_chooseColor -parent . -title "Choose Color"]
# 
# if {$color != ""} {
#     puts "Selected color: $color"
# } else {
#     puts "No color selected."
# }

################################################################################
### 完整示例

package require Tk

set dpi [winfo pixels . 1i]
set scale [expr {$dpi / 96.0}]
set size [expr {int(20 * $scale)}]
puts "size = $size"

source "Tk_ScaleImage.tcl"
set icon [scaleImage "images/Luffy.png" $size $size]

button .btn -text "Choose Color" -width $size -height $size -image $icon -command {
    set color [tk_chooseColor]

    if {$color != ""} {
        .lbl configure -background $color
    }
}
label .lbl -text "Selected Color" -width 20 -height 5
pack .btn 
pack .lbl
