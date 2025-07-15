################################################################################
###

package require Tk

button .btn -text "Button"
pack .btn

puts "btn_height = [winfo reqheight .btn]"
