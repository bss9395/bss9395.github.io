################################################################################
### 基本输入框

# package require Tk
# 
# entry .entry -width 20
# pack .entry

################################################################################
### 绑定变量

# package require Tk
# 
# set inputText ""
# entry .entry -textvariable inputText -width 20
# pack .entry
# 
# button .btn -text "Submit" -command {
# 	puts "Input: $inputText"
# }
# pack .btn

################################################################################
### 密码输入框

# package require Tk
# 
# entry .entry -show "*" -width 20
# pack .entry

################################################################################
### 禁用输入框

# package require Tk
# 
# entry .entry -state disabled -width 20
# pack .entry

################################################################################
### 输入验证

package require Tk

proc validateInput {value} {
	if {$value == ""} {
		return true
	} elseif {[string is integer -strict $value]} {
		return true
	} 
	return false
}

entry .entry -width 20 -textvariable entryText -validate key -validatecommand {
	validateInput %P;    # %P，The value of the entry if the edit is allowed.
}
pack .entry

# 
# after 2000 {
# 	set entryText "123qwe"
# 	puts [.entry get]
# 	.entry delete 0 end
# 	.entry insert 2 "123qwe"
# }

################################################################################
### 设置样式

# package require Tk
# 
# entry .entry -width 20 -font {Arial 12 bold} -fg white -bg blue -relief sunken
# pack .entry

#################################################################################
### 光标颜色

# package require Tk
# 
# entry .entry -width 20 -insertbackground red
# pack .entry

################################################################################
### 复杂示例

# package require Tk
# 
# set ::formatmsg "Zip should be ##### or #####-####"
# proc check_zip {newval op} {
# 	set ::errmsg ""
# 	set valid [expr {[regexp {^[0-9]{5}(\-[0-9]{4}){0,1}$} $newval]}]
# 	.f.btn configure -state [expr {$valid ? "normal" : "disabled"}]
# 	if {$op == "key"} {
# 		set ok_so_far [expr {[regexp {^[0-9\-]{0,}$} $newval] && [string length $newval] <= 10}]
# 		if {!$ok_so_far} {
# 			set ::errmsg $::formatmsg
# 		}
# 		return $ok_so_far
# 	} elseif {$op == "focusout"} {
# 		if {!$valid} {
# 			set ::errmsg $::formatmsg
# 		}
# 	}
# 	return $valid
# }
# 
# grid [ttk::frame .f] -column 0 -row 0
# grid [ttk::label .f.l1 -text "Name: "] -column 0 -row 0 -padx 5 -pady 5
# grid [ttk::entry .f.el] -column 1 -row 0 -padx 5 -pady 5
# grid [ttk::label .f.l -text "Zip: "] -column 0 -row 1 -padx 5 -pady 5
# grid [ttk::entry .f.e -textvariable zip -validate all -validatecommand {check_zip %P %V}] -column 1 -row 1 -padx 5 -pady 5;    # %P: The value of the entry if the edit is allowed.    # %V: The type of validation that triggered the callback (key, focusin, focusout, forced).
# grid [ttk::button .f.btn -text "Process"] -column 2 -row 1 -padx 5 -pady 5
# grid [ttk::label .f.msg -font TkSmallCaptionFont -foreground red -textvariable errmsg] -column 0 -row 2 -columnspan 3 -padx 5 -pady 5 -sticky w
# .f.btn state disabled
