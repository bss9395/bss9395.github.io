################################################################################
###

package require Tk

button .mainButton -text "Open TopLevel" -command {OpenTopLevel}
pack .mainButton

proc OpenTopLevel {} {
	toplevel .top -width 300 -height 200
	wm title .top "TopLevel"

	label .top.label -text "This is a TopLevel window!"
	pack .top.label

	button .top.closeBtn -text "Close" -command {destroy .top}
	pack .top.closeBtn
}
