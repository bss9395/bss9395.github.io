################################################################################

package require Tk

proc start {} {
	.f.b configure -text "Stop" -command stop
	.f.l configure -text "Working..."
	set ::interrupt 0
	after 1 step
}

proc stop {} {
	set ::interrupt 1
}

proc step {{count 0}} {
	.f.p configure -value $count
	if {$::interrupt} {
		result ""
		return
	}
	after 100
	if {$count == 20} {
		result 42
		return
	}
	after 1 step [incr count]
}

proc result {{answer ""}} {
	.f.p configure -value 0
	.f.b configure -text "Start!" -command start
	.f.l configure -text [expr {$answer != ""? "Answer: $answer" : "No Answer"}]
}

grid [ttk::frame .f]
grid [ttk::label .f.l -text "No Answer"] -column 0 -row 0 -padx 5 -pady 5
grid [ttk::button .f.b -text "Start!" -command start] -column 1 -row 0 -padx 5 -pady 5
grid [ttk::progressbar .f.p -orient horizontal -mode determinate -maximum 20] -column 0 -row 1 -columnspan 2 -padx 5 -pady 5
