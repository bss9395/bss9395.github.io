################################################################################
### 手动解析带-参数

# proc myProc {args} {
# 	set option1 ""
# 	set option2 ""
# 
# 	for {set i 0} {$i < [llength $args]} {incr i} {
# 		set arg [lindex $args $i]
# 		switch $arg {
# 			"-option1" {
# 				set option1 [lindex $args [incr i]]
# 			}
# 			"-option2" {
# 				set option2 [lindex $args [incr i]]
# 			}
# 			default {
# 				puts "未知选项: $arg"
# 			}
# 		}
# 	}
# 
# 	puts "option1 = $option1"
# 	puts "option2 = $option2"
# }
# 
# myProc -option1 value1 -option2 value2

################################################################################
### 处理混合参数，带-的参数和普通参数

proc myProc {args} {
	set option1 ""
	set option2 ""
	set positionalArgs {}

	for {set i 0} {$i < [llength $args]} {incr i} {
		set arg [lindex $args $i]
		if {[string index $arg 0] == "-"} {
			switch -- $arg {
				"-option1" {
					set option1 [lindex $args [incr i]]
				}
				"-option2" {
					set option2 [lindex $args [incr i]]
				}
				default {
					puts "未知选项: $arg"
				}
			}
		} else {
			lappend positionalArgs $arg
		}
	}

	puts "option1 = $option1"
	puts "option2 = $option2"
	puts "位置参数 = $positionalArgs"
}

myProc -option1 value1 arg1 -option2 value2 arg2
