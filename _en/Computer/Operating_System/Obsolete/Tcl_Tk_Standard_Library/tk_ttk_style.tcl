################################################################################

package require Tk

ttk::style configure Danger.TFrame -background red -borderwidth 5 -relief raised
grid [ttk::frame .f -width 200 -height 200 -style Danger.TFrame]

