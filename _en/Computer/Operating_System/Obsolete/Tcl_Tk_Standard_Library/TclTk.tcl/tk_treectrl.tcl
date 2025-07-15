
package require Tk

# 加载 treectrl
package require treectrl

# 创建主窗口
toplevel .top
wm title .top "TreeCtrl 示例"

# 创建 treectrl 控件
treectrl .top.tree -width 400 -height 100

# 定义列
.top.tree column create -text "名称" -tag colName
.top.tree column create -text "大小" -tag colSize

# 定义样式
.top.tree element create elemText text
.top.tree element create elemRect rect -fill [list #e0e0e0 selected]

# 定义行样式
.top.tree style create style1
.top.tree style elements style1 {elemRect elemText}
.top.tree style layout style1 elemText -padx 4 -expand ns
.top.tree style layout style1 elemRect -union {elemText} -iexpand ns

# 添加数据
set root [.top.tree item create]
.top.tree item style set $root colName style1
.top.tree item text $root colName "根节点"

set child1 [.top.tree item create -parent $root]
.top.tree item style set $child1 colName style1
.top.tree item style set $child1 colSize style1
.top.tree item text $child1 colName "子节点 1"
.top.tree item text $child1 colSize "100 KB"

set child2 [.top.tree item create -parent $root]
.top.tree item style set $child2 colName style1
.top.tree item style set $child2 colSize style1
.top.tree item text $child2 colName "子节点 2"
.top.tree item text $child2 colSize "200 KB"

# 布局
pack .top.tree -fill both -expand 1

# 运行主循环
tkwait window .top