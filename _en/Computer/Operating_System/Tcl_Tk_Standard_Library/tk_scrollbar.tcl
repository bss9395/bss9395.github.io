################################################################################
### 垂直滚动条与listbox结合

# package require Tk
# 
# listbox .listbox -yscrollcommand ".scrollbar set"
# scrollbar .scrollbar -orient vertical -command ".listbox yview"
# pack .listbox -side left -fill both -expand true
# pack .scrollbar -side right -fill y
# 
# for {set i 1} {$i <= 50} {incr i} {
#     .listbox insert end "Item $i"
# }

################################################################################
### 水平滚动条与text结合

# package require Tk
# 
# text .text -wrap none -xscrollcommand ".hscrollbar set"
# scrollbar .hscrollbar -orient horizontal -command ".text xview"
# pack .text -side top -fill both -expand true
# pack .hscrollbar -side bottom -fill x
# 
# .text insert end "This is a long line of text that requires horizontal scrolling."

################################################################################
### 垂直和水平滚动条与canvas结合

# package require Tk
# 
# canvas .canvas -scrollregion {0 0 500 500} -xscrollcommand ".hscrollbar set" -yscrollcommand ".vscrollbar set"
# scrollbar .vscrollbar -orient vertical -command ".canvas yview"
# scrollbar .hscrollbar -orient horizontal -command ".canvas xview"
# grid .canvas -row 0 -column 0
# grid .vscrollbar -row 0 -column 1 -sticky ns
# grid .hscrollbar -row 1 -column 0 -sticky we
# grid rowconfigure . 0 -weight 1
# grid columnconfigure . 0 -weight 1
# 
# .canvas create oval 100 100 200 200 -fill blue
# .canvas create rectangle 300 300 400 400 -fill red

################################################################################
### 示例

package require Tk

grid [tk::listbox .l -yscrollcommand ".s set" -height 5] -column 0 -row 0 -sticky nwes
grid [ttk::scrollbar .s -command ".l yview" -orient vertical] -column 1 -row 0 -sticky ns
grid [ttk::label .stat -text "Status message here" -anchor w] -column 0 -columnspan 2 -row 1 -sticky we
grid columnconfigure . 0 -weight 1; grid rowconfigure . 0 -weight 1
for {set i 0} {$i < 100} {incr i} {
   .l insert end "Line $i of 100"
}
