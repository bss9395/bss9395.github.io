package require Tk

proc scaleImage {file width height} {
	image create photo originImage -file $file
	set originWidth  [image width  originImage]
	set originHeight [image height originImage]

	image create photo scaledImage -width $width -height $height
	set scaleWidth  [expr {double($width)  / $originWidth}]
	set scaleHeight [expr {double($height) / $originHeight}]

	for {set y 0} {$y < $height} {incr y} {
		for {set x 0} {$x < $width} {incr x} {
			set srcX [expr {int($x / $scaleWidth)}]
			set srcY [expr {int($y / $scaleHeight)}]
			scaledImage copy originImage -from $srcX $srcY [expr {$srcX+1}] [expr {$srcY+1}] -to $x $y [expr {$x+1}] [expr {$y+1}]
		}
	}

	return scaledImage
}

proc test {} {
	set img [scaleImage "images/Luffy.png" 100 100]
	label .imgLabel -image $img
	pack .imgLabel
}
