################################################################################
### 基本用法

# package require Tk
# 
# set file [tk_getOpenFile]
# 
# if {$file != ""} {
# 	puts "Selected file: $file"
# } else {
# 	puts "No file selected."
# }

################################################################################
### 指定文件类型过滤器

# package require Tk
# 
# set file [tk_getOpenFile -filetypes {
# 	{"Text Files" {.txt}}
# 	{"All Files" {*}}
# }]
# 
# if {$file != ""} {
# 	puts "Selected file: $file"
# } else {
# 	puts "No file selected."
# }

################################################################################
### 指定初始目录和默认扩展名

# package require Tk
# 
# set file [tk_getOpenFile -initialdir "C:/Users/" -defaultextension ".txt" -filetypes {
# 	{"All Files" {*}}
# 	{"Text Files" {.txt}}
# }]
# 
# if {$file != ""} {
# 	puts "Selected file: $file"
# } else {
# 	puts "No file selected."
# }

################################################################################
### 允许选择多个文件

# package require Tk
# 
# set files [tk_getOpenFile -multiple 1]
# 
# if {[llength $files] != 0} {
# 	foreach file $files {
# 		puts "Selected file: $file"
# 	}	
# } else {
# 	puts "No files selected."
# }

################################################################################
### 指定父窗口和标题

# package require Tk
# 
# set file [tk_getOpenFile -parent . -title "Select a File" -multiple 1]
# if {[llength $file] != 0} {
# 	puts "Selected file: $file"
# } else {
# 	puts "No file selected"
# }

################################################################################
### 完整示例

package require Tk

button .btn -text "Open File" -command {
    set file [tk_getOpenFile -filetypes {
        {"Text Files" {.txt}}
        {"All Files" *}
    }]

    if {$file ne ""} {
        set fp [open $file r]
        set content [read $fp]
        close $fp

        text .txt -wrap word
        .txt insert end $content
        pack .txt
    } else {
        puts "No file selected."
    }
}
pack .btn
