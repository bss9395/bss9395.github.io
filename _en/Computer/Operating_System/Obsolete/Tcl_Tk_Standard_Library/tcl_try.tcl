################################################################################
### 捕获异常

# try {
# 	expr 1 / 0
# } trap {ARITH DIVZERO} errorMsg {
# 	puts "Caught division by zero: $errorMsg"
# }

################################################################################
### 捕获特定结果

# try {
# 	set result [expr {1 + 1}]
# } on ok res {
# 	puts "Result is: $res"
# }

################################################################################
### 使用finally清理资源

# set file [open "output.txt" w]
# try {
# 	chan puts $file "Hello, World!"
# } finally {
# 	chan close $file
# }

################################################################################
### 捕获多种异常

# try {
# 	set x [expr {1 / 0}]
# } trap {ARITH DIVZERO} err {
# 	puts "Caught a division by zero: $err"
# } trap {ARITH DOMAIN} err {
# 	puts "Caught a domain error: $err"
# }

################################################################################
### 捕获所有异常

try {
	set x [expr {1 / 0}]
} trap {} err {
	puts "Caught an exception: $err"
}
