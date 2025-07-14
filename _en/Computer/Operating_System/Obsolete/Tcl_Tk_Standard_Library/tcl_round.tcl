
set num1 3.14
set num2 2.718
set result1 [expr round($num1)]
set result2 [expr round($num2)]
puts "round($num1) = $result1"
puts "round($num2) = $result2"

set num3 -1.49
set num4 -1.51
set result3 [expr round($num3)]
set result4 [expr round($num4)]
puts "round($num3) = $result3"
puts "round($num4) = $result4"




package require Tk

entry .entry
button .btn -text "Round" -command {
	set input [.entry get]
	set rounded [expr round($input)]
	puts "Rounded value: $rounded"
}
pack .entry .btn

