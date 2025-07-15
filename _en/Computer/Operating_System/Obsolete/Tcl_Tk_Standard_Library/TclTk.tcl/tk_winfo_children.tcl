proc get_all_children {window} {
    set children [winfo children $window]
	set result ""
    foreach child $children {
        lappend result $child
        set result [concat $result [get_all_children $child]]
    }
    return $result
}

package require Tk

frame .frame
button .frame.btn -text "Button"
label .frame.lbl -text "Label"

pack .frame.btn .frame.lbl
pack .frame

# 获取所有后代小部件
set all_children [get_all_children .]
puts $all_children