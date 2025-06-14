################################################################################
### 声明和引用全局变量

# set ::globalVar "这是一个全局变量"
# 
# proc myProc {} {
#     variable ::globalVar
#     set ::globalVar "在过程中修改了全局变量"
# }
# 
# myProc
# puts $::globalVar

################################################################################
### 声明并初始化变量

# proc myProc {} {
#     variable localVar "这是一个局部变量"
#     puts $localVar
# }
# 
# myProc

################################################################################
### 与 global 的对比

set ::globalVar "这是一个全局变量"

proc myProc1 {} {
    global ::globalVar
    puts $::globalVar
}

proc myProc2 {} {
    variable ::globalVar
    puts $::globalVar
}

myProc1
myProc2
