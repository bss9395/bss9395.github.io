################################################################################
### 简单替换

# set str "Hello, World!"
# regsub "World" $str "Tcl" newStr
# puts $newStr

################################################################################
### 替换所有匹配项

# set str "apple apple apple"
# regsub -all "apple" $str "orange" newStr
# puts $newStr

################################################################################
### 使用捕获组

# set str "Date: 2023-10-05"
# regsub {(\d{4})-(\d{2})-(\d{2})} $str {\3/\2/\1} newStr
# puts $newStr

################################################################################
### 忽略大小写

# set str "Hello, world!"
# regsub -nocase "hello" $str "Hi" newStr
# puts $newStr

################################################################################
### 

set fileexten "Hello, {World}!"
set clearfileexten [regsub -all {\}} $fileexten ""]
puts $clearfileexten


