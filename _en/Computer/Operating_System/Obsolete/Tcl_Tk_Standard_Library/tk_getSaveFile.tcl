################################################################################
### 基本用法

# package require Tk
# 
# set file [tk_getSaveFile]
# 
# if {$file != ""} {
# 	puts "Save file to: $file"
# } else {
# 	puts "Save canceled."
# }

################################################################################
### 指定文件类型过滤器

# package require Tk
# 
# set file [tk_getSaveFile -filetypes {
#     {"Text Files" {.txt}}
#     {"All Files" *}
# }]
# 
# if {$file != ""} {
#     puts "Save file to: $file"
# } else {
#     puts "Save canceled."
# }

################################################################################
### 指定初始目录和默认扩展名

# package require Tk
# 
# set file [tk_getSaveFile -initialdir "C:/Users" -defaultextension ".txt"]
# 
# if {$file ne ""} {
#     puts "Save file to: $file"
# } else {
#     puts "Save canceled."
# }

################################################################################
### 指定父窗口和标题

# package require Tk
# 
# set file [tk_getSaveFile -parent . -title "Save File"]
# 
# if {$file ne ""} {
#     puts "Save file to: $file"
# } else {
#     puts "Save canceled."
# }

################################################################################
### 保存文件内容

package require Tk

text .txt -wrap word
button .btn -text "Save File" -command {
    set file [tk_getSaveFile -filetypes {
        {"Text Files" {.txt}}
        {"All Files" *}
    }]

    if {$file != ""} {
        set fp [open $file w]
        puts $fp [.txt get 1.0 end]
        close $fp

        puts "File saved to: $file"
    } else {
        puts "Save canceled."
    }
}
pack .txt .btn

