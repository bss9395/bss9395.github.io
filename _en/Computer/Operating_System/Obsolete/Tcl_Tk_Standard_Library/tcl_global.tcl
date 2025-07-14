################################################################################

# set count 0
# proc increment {} {
# 	global count
# 	incr count
# 	puts "Count: $count"
# }
# increment
# increment

################################################################################

### 多个全局变量

# set name "Alice"
# set age 30
# proc print_info {} {
# 	global name age 
# 	puts "Name: $name, Age: $age"
# }
# print_info

################################################################################

### 跨过程共享数据

set counter 0
proc increment {} {
	global counter
	incr counter
	puts "Counter: $counter"
}
proc reset {} {
	global counter
	set counter 0
	puts "Counter reset to 0"
}
increment
increment 
reset
increment

################################################################################

vwait forever
