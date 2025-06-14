################################################################################
### 创建命名空间

# namespace eval myNamespace {
#     variable myVar "这是一个命名空间变量"
# }
# 
# puts $myNamespace::myVar

################################################################################
### 当前命名空间

# namespace eval myNamespace {
#     puts [namespace current]
# }

################################################################################
### 导出命名空间

# namespace eval myNamespace {
#     proc myProc {} {
#         puts "这是一个命名空间过程"
#     }
#     # namespace export myProc
# }
# 
# myNamespace::myProc

################################################################################
### 导入命名空间

# namespace eval myNamespace {
# 	proc myProc {} {
# 		puts "这是一个命名空间过程"
# 	}
#     namespace export myProc
# }
# 
# namespace import myNamespace::myProc
# myProc

################################################################################
### 删除命名空间

# namespace eval myNamespace {
#     variable myVar "这是一个命名空间变量"
# }
# puts $myNamespace::myVar
# 
# # 删除命名空间
# namespace delete myNamespace
# 
# # 尝试访问已删除的命名空间变量
# catch {
# 	puts $myNamespace::myVar
# } result
# puts $result

################################################################################
### 使用命名空间组织代码

# 创建命名空间
namespace eval myApp {
    # 定义变量
    set version "1.0"

    # 定义过程
    proc start {} {
        puts "应用程序启动，版本: $myApp::version"
    }

    # 导出过程
    # namespace export start
}

# 使用命名空间中的过程
myApp::start
