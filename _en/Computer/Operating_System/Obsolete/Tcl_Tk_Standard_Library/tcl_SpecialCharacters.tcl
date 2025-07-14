################################################################################
### 使用反斜杠转义特殊字符

set str "This is a \$dollar sign and a \[bracket\]."
puts $str

set str {This is a $dollar sign and a [bracket].}
puts $str

################################################################################
### {和}

package require Tk

set str {This {is a} $dollar sign and a [bracket].}
puts $str

label .label -text $str
pack .label
