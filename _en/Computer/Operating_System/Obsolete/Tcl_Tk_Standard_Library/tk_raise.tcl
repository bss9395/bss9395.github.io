################################################################################
###

package require Tk

grid [ttk::label .back -text "Back1111"] -row 0 -column 0  
grid [ttk::label .midd -text "Middle"  ] -row 0 -column 0  
grid [ttk::label .fore -text "Fore"    ] -row 0 -column 0  
after 2000 {
	raise .back .midd

	after 2000 {
		raise .back 
	}
}

wm attributes . -topmost 1

vwait forever
