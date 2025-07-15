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

# package require Tk
# 
# text .text
# pack .text
# 
# .text insert end "This is a text widget.\n"
# 
# button .changeFontBtn -text "Change Font" -command {
#     .text configure -font {Courier 14}
# }
# pack .changeFontBtn

################################################################################
### 在文本中嵌入按钮

# package require Tk
# 
# text .txt
# pack .txt
# 
# button .btn -text "Click Me" -command {
# 	puts "Button clicked!"
# }
# 
# .txt window create end -window .btn
# .txt insert 1.0 " This is a button."

################################################################################
### 在文本中嵌入标签

# package require Tk
# 
# text .txt
# pack .txt
# 
# label .lbl -text "Important:" -foreground red
# .txt window create end -window .lbl
# .txt insert end " This is an important message."

################################################################################
### 在文本中嵌入输入框

# package require Tk
# 
# text .txt
# pack .txt
# 
# entry .entry -width 20
# .txt window create end -window .entry
# .txt insert end " Enter your name:"

################################################################################
### 复杂布局

package require Tk

text .txt
button .btn0 -text "button"
button .txt.btn1 -text "button"
button .btn2 -text "button"
button .btn3 -text "button"
button .btn4 -text "button"
button .btn5 -text "button"

.txt window create end -window .btn0      ;# .btn0需要放在.txt之后创建
.txt window create end -window .txt.btn1  
.txt window create end -window .btn2
.txt window create end -window .btn3
.txt window create end -window .btn4
.txt window create end -window .btn5

pack .txt -fill both -expand 1
.txt configure -width 20

bind . <Configure> {
	::adjustTextHeight .txt
}

proc adjustTextHeight {widget} {
	set parent [winfo parent $widget]
	set children  [winfo children $widget]
	set child [lindex $children 0]

	set text_width  [winfo width $parent]
	set text_height [winfo height $parent]
	set text_reqwidth  [winfo reqwidth $parent]
	set text_reqheight [winfo reqheight $parent]
	set button_width  [winfo width $child]
	set button_height [winfo height $child]
	set button_reqwidth  [winfo reqwidth $child]
	set button_reqheight [winfo reqheight $child]
	set spacing 4
	set button_width_spacing [expr ($spacing + $button_width + $spacing)]

    set column [expr ($text_reqwidth / $button_reqwidth)]
	set count  [$widget count -displayindices 1.0 end-1c] 
	
	set lineCount [expr ($count / $column)]
	if { $count % $column != 0 } {
		set lineCount [expr ($lineCount + 1)]
	}
		
	set font  [.txt cget -font]
	set linespace [font metrics $font -linespace]
	set height [expr (1.0 * $lineCount * $button_reqheight / $linespace)]

    $widget configure -height $height
	$widget configure -background "red"

puts "text_width = $text_width, text_height = $text_height, text_reqwidth = $text_reqwidth, text_reqheight = $text_reqheight"
puts "button_width = $button_width, button_height = $button_height, button_reqwidth = $button_reqwidth, button_reqheight = $button_reqheight"
puts "column = $column, count = $count"
puts "lineCount = $lineCount, linespace = $linespace, height = $height"
}



