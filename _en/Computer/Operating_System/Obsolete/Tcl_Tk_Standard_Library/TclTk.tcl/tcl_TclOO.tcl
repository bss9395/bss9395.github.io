################################################################################
### 使用namespace和proc

# # 定义类
# namespace eval MyClass {
#     # 构造函数
#     proc new {name} {
#         set self [namespace current]::[namespace tail $name]
# 		  puts "self = $self"
#         namespace eval $self {
#             variable name
#             variable count 0
#         }
#         set ${self}::name $name
#         return $self
#     }
# 
#     # 方法：增加计数
#     proc increment {self} {
# 		  puts "selftcount = ${self}::count"
#         upvar ${self}::count count
#         incr count
#     }
# 
#     # 方法：获取计数
#     proc getCount {self} {
#         upvar ${self}::count count
#         return $count
#     }
# 
#     # 方法：获取名称
#     proc getName {self} {
#         upvar ${self}::name name
#         return $name
#     }
# }
# 
# # 创建对象
# set obj1 [MyClass::new "对象1"]
# set obj2 [MyClass::new "对象2"]
# 
# # 调用方法
# MyClass::increment $obj1
# MyClass::increment $obj1
# MyClass::increment $obj2
# 
# # 输出结果
# puts "对象1的名称: [MyClass::getName $obj1], 计数: [MyClass::getCount $obj1]"
# puts "对象2的名称: [MyClass::getName $obj2], 计数: [MyClass::getCount $obj2]"

################################################################################
### 使用 TclOO 实现 OOP

# # 定义类
# oo::class create MyClass {
#     variable name
# 	  variable count
# 
#     # 构造函数
#     constructor {n} {
#         set name $n
#         set count 0
#     }
# 
#     # 方法：增加计数
#     method increment {} {
#         incr count
#     }
# 
#     # 方法：获取计数
#     method getCount {} {
#         return $count
#     }
# 
#     # 方法：获取名称
#     method getName {} {
#         return $name
#     }
# }
# 
# # 创建对象
# set obj1 [MyClass new "对象1"]
# set obj2 [MyClass new "对象2"]
# 
# # 调用方法
# $obj1 increment
# $obj1 increment
# $obj2 increment
# 
# # 输出结果
# puts "对象1的名称: [$obj1 getName], 计数: [$obj1 getCount]"
# puts "对象2的名称: [$obj2 getName], 计数: [$obj2 getCount]"
