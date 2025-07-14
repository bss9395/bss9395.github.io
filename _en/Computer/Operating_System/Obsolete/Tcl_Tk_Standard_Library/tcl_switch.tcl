################################################################################
### 简单匹配

# set fruit default
# 
# switch $fruit {
# 	"apple" {
# 		puts "这是苹果"
# 	}
# 	"banana" {
# 		puts "这是香蕉"
# 	}
# 	"default" {
# 		puts "这是default"
# 	}
# 	default {
# 		puts "未知水果"
# 	}
# }

################################################################################
### 多模式匹配，一个分支可以匹配多个模式，用-分隔

# set day "Monday"
# 
# switch $day {
# 	"Monday" - "Tuesday" - "Wednesday" - "Thursday" - "Friday" {
# 		puts "工作日"
# 	}
# 	"Saturday" - "Sunday" {
# 		puts "周末"
# 	}
# 	default {
# 		puts "位置日期"
# 	}
# }

################################################################################
### 使用正则表达式

# set input "123abc"
# 
# switch -regexp -- $input {
# 	"^[0-9]{1,}$" {
# 		puts "纯数字"
# 	}
# 	"^[a-zA-Z]{1,}$" {
# 		puts "纯字母"
# 	}
# 	"^[0-9a-zA-Z]{1,}$" {
# 		puts "数字和字母"
# 	}
# 	default {
# 		puts "未知格式"
# 	}
# }

################################################################################
### 使用-glob模式

# set filename "report.txt"
# 
# switch -glob -- $filename {
# 	"*.txt" {
# 		puts "文本文件"
# 	}
# 	"*.csv" {
# 		puts "CSV文件"
# 	}
# 	default {
# 		puts "未知文件类型"
# 	}
# }

################################################################################
### 使用-exact模式，switch默认使用-exact模式，即精确匹配。

set color "red"

switch -exact -- $color {
	"red" {
		puts "红色"
	}
	"green" {
		puts "绿色"
	}
	default {
		puts "未知颜色"
	}
}
