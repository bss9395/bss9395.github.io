################################################################################
### 基本用法

# proc increment {} {
# 	upvar count count;
# 	incr count
# 	puts "Count: $count"
# }
# set count 0
# increment
# increment

################################################################################
###

# proc print_global {} {
# 	upvar #0 globalVar localVar
# 	puts "Global variable: $localVar"
# }
# set globalVar "Hello, World!"
# print_global

################################################################################
### 访问多级作用域中的变量

# proc outer {} {
# 	set outerVar "Outer variable"
# 	inner
# }
# 
# proc inner {} {
# 	upvar 1 outerVar localVar
# 	puts "Outer variable from inner: $localVar"
# }
# 
# outer

################################################################################
### 修改上级作用域中的变量

# proc modify {} {
# 	upvar value value;
# 	set value "Modified value"
# }
# 
# set value "Original value"
# modify
# puts "Value after modification: $value"

################################################################################
### 结合 namespace 和 upvar 实现封装

# 定义命名空间
namespace eval MyClass {
    variable count 0

    # 定义方法：增加计数
    proc increment {} {
        upvar #0 MyClass::count count
        incr count
    }

    # 定义方法：获取计数
    proc getCount {} {
        upvar #0 MyClass::count count
        return $count
    }
}

# 调用方法
MyClass::increment
MyClass::increment

# 输出计数
puts [MyClass::getCount]
