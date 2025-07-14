################################################################################
### 基本用法

# package require Tk
# 
# set dir [tk_chooseDirectory]
# 
# if {$dir != ""} {
#     puts "Selected directory: $dir"
# } else {
#     puts "No directory selected."
# }

################################################################################
### 指定初始目录

# package require Tk
# 
# set dir [tk_chooseDirectory -initialdir "C:/Users"]
# 
# if {$dir != ""} {
#     puts "Selected directory: $dir"
# } else {
#     puts "No directory selected."
# }

################################################################################
### 限制选择已存在的目录

# package require Tk
# 
# set dir [tk_chooseDirectory -mustexist 1]
# 
# if {$dir != ""} {
#     puts "Selected directory: $dir"
# } else {
#     puts "No directory selected."
# }

################################################################################
### 指定父窗口和标题

# package require Tk
# 
# set dir [tk_chooseDirectory -parent . -title "Select Directory"]
# 
# if {$dir != ""} {
#     puts "Selected directory: $dir"
# } else {
#     puts "No directory selected."
# }

################################################################################
### 列出目录中的目录与文件

package require Tk

button .btn -text "Select Directory" -command {
    set dir [tk_chooseDirectory -title "Select a Directory"]

    if {$dir != ""} {
        set files [glob -directory $dir *]
        foreach file $files {
            puts "File: $file"
        }
    } else {
        puts "No directory selected."
    }
}
pack .btn
