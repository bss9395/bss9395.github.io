
################################################################################

# ### catch基本用法
# 
# set result [catch {
# 	expr 1/ 0
# }]
# puts "Status: $result"

################################################################################

### 捕获错误信息

# set result [catch {
# 	expr 1 / 0
# } errorMsg]
# puts "Status: $result"
# puts "Error message: $errorMsg"

################################################################################

### 处理异常

# set status [catch {
# 	expr 1 / 0
# } errorMsg]
# if {$status == 1} {
# 	puts "Error occured: $errorMsg"
# } else {
# 	puts "Result: $errorMsg"
# }

################################################################################

### 获取详细错误信息

# set status [catch {
# 	expr 1 / 0
# } errorMsg errorDetails]
# puts "Status: $status"
# puts "Error message: $errorMsg"
# puts "Error details: $errorDetails"

################################################################################

### 结合global使用

set errorInfo ""
proc risky_operation {} {
	global errorInfo
	catch { 
		expr 1 / 0
	} errorMsg errorDetails
	set errorInfo $errorDetails
}
risky_operation
puts "Error info: $errorInfo"
