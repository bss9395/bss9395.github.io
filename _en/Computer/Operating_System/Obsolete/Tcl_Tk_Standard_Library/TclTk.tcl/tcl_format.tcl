### 将浮点数四舍五入到指定的小数位数。

# 使用expr和pow
proc round_to_decimal {number decimal_places} {
	set factor [expr pow(10, $decimal_places)]
	return [expr round($number * $factor)/$factor]
}

set num 3.14159
set result [round_to_decimal $num 2]
puts "Rounded to 2 decimal places: $result"

################################################################################

# 使用format

proc round_to_decimal {number decimal_places} {
	return [format "%.${decimal_places}f" $number]
}

set num 3.14159
set result [round_to_decimal $num 2]
puts "Rounded to 2 decimal places: $result"

################################################################################

### 基本格式化

set name "Alice"
set age 30
set height 1.75

set result [format "Name: %s, Age: %d, Height: %.2f" $name $age $height]
puts $result


set name "Bob"
set age 25
puts [format "%-10s %5d" $name $age] 
puts [format "%10s %5d" $name $age]

################################################################################

### 在图形界面中使用format

# package require Tk
#
# set name "Charlie"
# set age 35
# set height 1.80
#
# label .lbl -text [format "Name: %s\nAge: %d\nHeight: %.2f" $name $age $height]
# pack .lbl


################################################################################

### 格式化文件输出

set file [open "output.txt" w]
set data {Name Age Height}
set row1 {Alice 30 1.75}
set row2 {Bob 25 1.80}

puts $file [format "%-10s %5s %7s"   {*}$data]
puts $file [format "%-10s %5d %7.2f" {*}$row1]
puts $file [format "%-10s %5d %7.2f" {*}$row2]

close $file
