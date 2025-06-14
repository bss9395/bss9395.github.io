################################################################################
### 基本用法

# package require Tk
# 
# text .text
# pack .text
# 
# .text insert end "Hello, World!\nThis is a multi-line text widget."

################################################################################
### 添加滚动条

# package require Tk
# 
# text .text -wrap none -yscrollcommand ".scrollbar set"
# scrollbar .scrollbar -orient vertical -command ".text yview"
# pack .text -side left -fill both -expand true
# pack .scrollbar -side right -fill y
# 
# .text insert end "This is a long line of text that requires vertical scrolling.\n"
# for {set i 1} {$i <= 50} {incr i} {
#     .text insert end "Line $i\n"
# }

################################################################################
### 使用标记格式化文本

# package require Tk
# 
# text .text
# pack .text
# 
# .text insert end "This is normal text.\n"
# .text insert end "This is bold text.\n" bold
# .text insert end "This is red text.\n" red
# 
# .text tag configure bold -font {Arial 12 bold}
# .text tag configure red -foreground red

################################################################################
### 搜索文本

# package require Tk
# 
# text .text
# pack .text
# 
# .text insert end "This is a sample text with the word 'sample' in it.\n"
# 
# set index [.text search -forwards "sample" 1.0]
# .text tag add highlight $index $index+6chars
# .text tag configure highlight -background yellow

################################################################################
### 动态配置控件

package require Tk

text .text
pack .text

.text insert end "This is a text widget.\n"

button .changeFontBtn -text "Change Font" -command {
    .text configure -font {Courier 14}
}
pack .changeFontBtn
