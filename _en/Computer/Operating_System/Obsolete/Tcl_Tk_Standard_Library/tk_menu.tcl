################################################################################
### 基本用法

# package require Tk
# 
# wm title . "Menu Example"
# menu .mainMenu -tearoff 0
# . configure -menu .mainMenu
# 
# menu .mainMenu.file -tearoff 0
# .mainMenu add cascade -label "File" -menu .mainMenu.file
# .mainMenu.file add command -label "New" -command {puts "New File"}
# .mainMenu.file add command -label "Open" -command {puts "Open File"}
# .mainMenu.file add separator
# .mainMenu.file add command -label "Exit" -command {exit}
# 
# menu .mainMenu.edit -tearoff 0
# .mainMenu add cascade -label "Edit" -menu .mainMenu.edit
# .mainMenu.edit add command -label "Cut" -command {puts "Cut"}
# .mainMenu.edit add command -label "Copy" -command {puts "Copy"}
# .mainMenu.edit add command -label "Paste" -command {puts "Paste"}
# 
# menu .mainMenu.help -tearoff 0
# .mainMenu add cascade -label "Help" -menu .mainMenu.help
# .mainMenu.help add command -label "About" -command {puts "About"}

################################################################################
### 多级菜单

# package require Tk
# 
# wm title . "Menu Example"
# menu .mainMenu -tearoff 0
# . configure -menu .mainMenu
# 
# menu .mainMenu.file -tearoff 0
# .mainMenu add cascade -label "File" -menu .mainMenu.file
# 
# menu .mainMenu.file.recent -tearoff 0
# .mainMenu.file add cascade -label "Recent" -menu .mainMenu.file.recent
# 
# set files {file1.txt file2.txt file3.txt}
# foreach f $files {
# 	.mainMenu.file.recent add command -label [file tail $f] -command {puts $f}
# }
# 
# .mainMenu.file add command -label "New" -command {puts "New File"}
# .mainMenu.file add command -label "Open" -command {puts "Open File"}
# .mainMenu.file add separator
# .mainMenu.file add command -label "Exit" -command {exit}
# 
# menu .mainMenu.edit -tearoff 0
# .mainMenu add cascade -label "Edit" 

################################################################################
### tk_popup

# package require Tk
# 
# menu .popupMenu -tearoff 0
# .popupMenu add command -label "Option 1" -command {puts "Option 1"}
# .popupMenu add command -label "Option 1" -command {puts "Option 2"}
# bind . <Button-3> {
# 	tk_popup .popupMenu %X %Y
# }

################################################################################
### 复选按钮和单选按钮

# package require Tk
# 
# menu .popupMenu -tearoff 0
# .popupMenu add checkbutton -label "Check" -variable check -onvalue 1 -offvalue 0 -command {
# 	puts "$check"
# }
# .popupMenu add radiobutton -label "One" -variable radio -value 1 -command {
# 	puts "$radio"
# }
# .popupMenu add radiobutton -label "Two" -variable radio -value 2 -command {
# 	puts "$radio"
# }
# 
# bind . <Button-3> {
# 	tk_popup .popupMenu %X %Y
# }

################################################################################
### 菜单设置与快捷键

# package require Tk
# 
# wm title . "Menu Example"
# menu .mainMenu -tearoff 0
# . configure -menu .mainMenu
# 
# menu .mainMenu.file -tearoff 0
# .mainMenu add cascade -label "File" -menu .mainMenu.file
# 
# menu .mainMenu.file.recent -tearoff 0
# .mainMenu.file add cascade -label "Recent" -menu .mainMenu.file.recent
# 
# set files {file1.txt file2.txt file3.txt}
# foreach f $files {
# 	.mainMenu.file.recent add command -label [file tail $f] -command {puts $f}
# }
# 
# .mainMenu.file add command -label "New" -command {puts "New File"}
# .mainMenu.file add command -label "Open" -command {puts "Open File"}
# .mainMenu.file add separator
# .mainMenu.file add command -label "Exit" -command {exit}
# 
# menu .mainMenu.edit -tearoff 0
# .mainMenu add cascade -label "Edit" -menu .mainMenu.edit
# .mainMenu.edit add command -label "Cut" -command {puts "Cut"}
# .mainMenu.edit add command -label "Copy" -command {puts "Copy"} 
# .mainMenu.edit add command -label "Paste" -command {puts "Paste"}
# 
# puts [.mainMenu.file entrycget 0 -label]
# puts [.mainMenu.file entryconfigure 0]
# .mainMenu.file entryconfigure "Exit" -state disabled
# .mainMenu.file entryconfigure "Exit" -label "Enter"
# 
# bind . <Control-v> {
# 	puts "Control-v"
# }

################################################################################
### 图标

# package require Tk
# 
# wm title . "Menu Example"
# menu .mainMenu -tearoff 0
# . configure -menu .mainMenu
# 
# menu .mainMenu.file -tearoff 0
# .mainMenu add cascade -label "File" -menu .mainMenu.file 
# 
# menu .mainMenu.file.recent -tearoff 0
# .mainMenu.file add cascade -label "Recent" -menu .mainMenu.file.recent
# 
# set files {file1.txt file2.txt file3.txt}
# foreach f $files {
# 	.mainMenu.file.recent add command -label [file tail $f] -command {puts $f}
# }
# 
# source "Tk_ScaleImage.tcl"
# set img [scaleImage "images/Luffy.png" 20 20]
# .mainMenu.file add command -label "New" -command {puts "New File"} -image $img -compound left
# .mainMenu.file add command -label "Open" -command {puts "Open File"}
# .mainMenu.file add separator
# .mainMenu.file add command -label "Exit" -command {exit}
# 
# menu .mainMenu.edit -tearoff 0
# .mainMenu add cascade -label "Edit" -menu .mainMenu.edit
# .mainMenu.edit add command -label "Cut" -command {puts "Cut"}
# .mainMenu.edit add command -label "Copy" -command {puts "Copy"} 
# .mainMenu.edit add command -label "Paste" -command {puts "Paste"}

################################################################################
### 事件

package require Tk

menu .m -tearoff 0
. configure -menu .m 
menu .m.edit -tearoff 0
.m add cascade -menu .m.edit -label "Edit"
.m.edit add command -label "Paste"   -command {
	clipboard clear
	clipboard append "Hello, Tcl/Tk!"
	
	event generate [focus] <<Paste>>
}
.m.edit add command -label "Find..." -command {
	event generate . <<OpenFindDialog>>
}

grid [ttk::entry .e]

bind . <<Paste>> {
	puts "Paste"
}

bind . <<OpenFindDialog>> {
	tk_messageBox -message "I hope you find what you're looking for!"
}
