################################################################################
### 创建简单的 Treeview

# package require Tk
# 
# wm title . "Treeview 示例"
# 
# ttk::treeview .tree -show headings -columns {"name" "age"}
# pack .tree -fill both -expand 1
# 
# .tree heading "name" -text "姓名"
# .tree heading "age"  -text "年龄"
# 
# .tree insert {} end -values {"张三" 25}
# .tree insert {} end -values {"李四" 30}
# 
# tkwait window .

################################################################################
### 创建层次结构的 Treeview

# package require Tk
# 
# wm title . "Treeview 示例"
# 
# ttk::treeview .tree -columns {"name" "age"} -show headings
# pack .tree -fill both -expand 1
# 
# .tree heading "name" -text "姓名"
# .tree heading "age" -text "年龄"
# 
# set parent [.tree insert {} end -values {"部门A"}]
# 
# .tree insert $parent end -values {"张三" 25}
# .tree insert $parent end -values {"李四" 30}
# 
# tkwait window .

################################################################################
### 获取选中项

# package require Tk
# 
# wm title . "Treeview 示例"
# 
# ttk::treeview .tree -columns {"name" "age"} -show headings
# pack .tree -fill both -expand 1
# 
# .tree heading "name" -text "姓名"
# .tree heading "age"  -text "年龄"
# 
# .tree insert {} end -values {"张三" 25} -text "A"
# .tree insert {} end -values {"李四" 30} -text "B"
# 
# button .button -text "获取选中项" -command {
#     set selecteds [.tree selection]
# 	foreach selected $selecteds {
# 		set values [.tree item $selected -values]
# 		puts "选中项的值: $values"
# 	}
# }
# pack .button -pady 10
# 
# tkwait window .

################################################################################
### 显示为树形结构

# package require Tk
# 
# wm title . "Treeview -text 示例"
# 
# ttk::treeview .tree -show tree
# pack .tree -fill both -expand 1
# 
# set parent [.tree insert {} end -text "父节点"]
# 
# .tree insert $parent end -text "子节点1"
# .tree insert $parent end -text "子节点2"
# 
# tkwait window .

################################################################################
### -text与-values

# package require Tk
# 
# wm title . "Treeview -text 示例"
# 
# ttk::treeview .tree -columns {col1 col2} -show {tree headings}
# pack .tree -fill both -expand 1
# 
# .tree heading #0 -text "主列"
# .tree heading col1 -text "列1"
# .tree heading col2 -text "列2"
# 
# set parent [.tree insert {} end -text "主列文本" -values {"a" "b"}]
# .tree insert $parent end -text "子节点1" -values {"c" "d"}
# .tree insert $parent end -text "子节点2" -values {"e" "f"}
# 
# tkwait window .

################################################################################
### id

# package require Tk
# 
# wm title . "TreeView -text 示例"
# 
# ttk::treeview .tree -show {tree}
# pack .tree -fill both -expand 1
# 
# .tree insert {} end -id widgets -text "Widget Tour"
# .tree insert {} 0   -id gallery -text "Applications"
# set id [.tree insert {} end -text "Tutorial"]       
# 
# .tree insert widgets end -text "Canvas"     
# .tree insert $id end -text "Tree"
# 
# # .tree move widgets gallery end
# # .tree detach widgets
# # .tree delete widgets
# 
# .tree item widgets -open true
# 
# tkwait window .

################################################################################
### 使用 ttk::style 设置行高

# package require Tk
# 
# wm title . "Treeview 行高示例"
# 
# ttk::style configure Treeview -rowheight 20
# ttk::treeview .tree -columns {name age} -show {tree headings}
# pack .tree -fill both -expand 1
# 
# .tree heading #0 -text "主列"
# .tree heading name -text "姓名"
# .tree heading age -text "年龄"
# 
# .tree insert {} end -text "张三" -values {"张三" 25}
# .tree insert {} end -text "李四" -values {"李四" 30}
# 
# ttk::style layout Custom.Treeview [ttk::style layout Treeview]
# ttk::style configure Custom.Treeview -rowheight 40
# ttk::treeview .other -show {tree} -style Custom.Treeview
# pack .other -fill both -expand 1
# .other heading #0 -text "主列"
# .other insert {} end -text "王五"
# .other insert {} end -text "张六"
# 
# tkwait window .

################################################################################
### 

package require Tk

wm title . "TreeView -text 示例"

ttk::treeview .tree -columns {"size" "modified"} -show {headings}
pack .tree -fill both -expand 1

.tree heading "size" -text "size"
.tree heading "modified" -text "modified"

.tree insert {} end -id widgets -values {"12KB" "true"} 
.tree insert {} end             -values {"24KB" "false"}

.tree configure -columns {"size" "modified" "owner"}
.tree heading "size" -text "size"
.tree heading "modified" -text "modified"
.tree heading "owner" -text "owner"

.tree column "size" -width 100 -anchor center
.tree heading "size" -text "Size"

.tree set widgets "size" "18KB"
.tree insert {} end -text "Listbox" -values [list "15KB" "Yesterday" "mark"]

.tree insert {} end -text "button" -values {"36KB" "Monday"} -tags {"ttk" "simple"}
.tree tag configure "ttk" -background "yellow"
.tree tag bind "ttk" <Button-1> {
	puts "item clicked"
}

tkwait window .
