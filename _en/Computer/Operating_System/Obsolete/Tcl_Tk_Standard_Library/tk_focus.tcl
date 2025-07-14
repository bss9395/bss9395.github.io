package require Tk

entry .entry1
entry .entry2

pack .entry1 .entry2

# 设置焦点到 .entry2
focus .entry2

# 获取当前焦点的小部件
set focused_widget [focus]
puts "Focused widget: $focused_widget"
