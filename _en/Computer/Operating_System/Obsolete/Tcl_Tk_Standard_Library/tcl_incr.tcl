################################################################################

### 基本用法

set count 0
incr count 
puts "Count: $count"

################################################################################

### 指定增量

set count 0
incr count 5
puts "Count: $count"

################################################################################

### 减少变量值

set count 10
incr count -3
puts "Count: $count"

################################################################################

### 在循环中使用

set count 0
while {$count < 5} {
	puts "Count: $count"
	incr count
}

################################################################################

### 结合global使用

proc increment {} {
	global count
	incr count
	puts "Count: $count"
}
increment
increment

################################################################################

### 结合upvar使用

proc increment {varName} {
	upvar $varName count
	incr count
	puts "Count: $count"
}
set count 3
increment count
increment count

