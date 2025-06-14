################################################################################
### 一个简单的画板

# package require Tk
# 
# grid [tk::canvas .canvas] -sticky news -column 0 -row 0
# grid columnconfigure . 0 -weight 1
# grid rowconfigure . 0 -weight 1
# 
# set ::lastx 0
# set ::lasty 0
# bind .canvas <Button-1> {
# 	set ::lastx %x
# 	set ::lasty %y
# }
# bind .canvas <Button1-Motion> {
#     .canvas create line $::lastx $::lasty %x %y
#     set ::lastx %x 
#     set ::lasty %y
# }

################################################################################
### 基本绘图

# source "tk_ScaleImage.tcl"
# package require Tk
# 
# wm title . "Canvas示例"
# canvas .canvas -width 800 -height 600 -background white
# pack .canvas -fill both -expand 1
# 
# # 绘制线条
# .canvas create line 10 10 200 50 90 150 50 80 -fill red -width 2
# # 绘制矩形
# .canvas create rectangle 200 50 300 100 -fill red -outline blue
# # 绘制椭圆
# .canvas create oval 200 100 300 200 -fill green -outline black
# # 绘制多边形
# .canvas create polygon 90 150 50 80 120 55 -fill red -outline blue
# # 绘制弧
# .canvas create arc 10 10 200 50 -fill yellow -outline black -start 0 -extent 225 -width 0
# # 绘制图像
# set img [scaleImage "images/Luffy.png" 50 50]
# .canvas create image 100 100 -image $img -anchor nw
# # 绘制文本
# .canvas create text 200 250 -text "Hello, Canvas!" -anchor sw -font {Arial 14} -fill black
# # 放置小部件
# ttk::button .canvas.btn -text "Implode"
# .canvas create window 300 300 -anchor nw -window .canvas.btn
# 
# tkwait window .

################################################################################
### 交互式绘图

# package require Tk
# 
# wm title . "交互式Canvas"
# canvas .canvas -width 400 -height 300 -background white
# pack .canvas -fill both -expand 1
# 
# set ::startX 0
# set ::startY 0
# set ::currentLine {}
# bind .canvas <Button-1> {
# 	set ::startX %x
# 	set ::startY %y
# 	set ::currentLine [.canvas create line %x %y %x %y]
# }
# bind .canvas <Button1-Motion> {
# 	.canvas coords $::currentLine $::startX $::startY %x %y
# 	.canvas itemconfigure $::currentLine -fill [expr {%x %% 2 == 0? "red" : "green"}]
# }
# 
# tkwait window .

################################################################################
### 滚动 Canvas

# package require Tk
# 
# wm title . "滚动Canvas"
# canvas .canvas -width 400 -height 300 -scrollregion {0 0 800 600} -xscrollcommand ".hscroll set" -yscrollcommand ".vscroll set"
# scrollbar .hscroll -orient horizontal -command ".canvas xview"
# scrollbar .vscroll -orient vertical -command ".canvas yview"
# 
# grid .canvas -row 0 -column 0 -sticky news
# grid .hscroll -row 1 -column 0 -sticky nsew
# grid .vscroll -row 0 -column 1 -sticky nsew
# grid rowconfigure . 0 -weight 1
# grid columnconfigure . 0 -weight 1
# 
# for {set i 0} {$i < 10} {incr i} {
# 	.canvas create text [expr {100 + $i * 50}] [expr {100 + $i * 50}] -text "Item $i" -font {Arial 12} -fill black
# }
# 
# tkwait window .

################################################################################
### 事件绑定

# package require Tk
# 
# grid [tk::canvas .canvas] -sticky news -column 0 -row 0
# grid columnconfigure . 0 -weight 1
# grid rowconfigure . 0 -weight 1
# 
# set ::lastx 0
# set ::lasty 0
# set ::color "black"
# bind .canvas <Button-1> {
# 	set ::lastx %x
# 	set ::lasty %y
# }
# bind .canvas <Button1-Motion> {
#     .canvas create line $::lastx $::lasty %x %y -fill $::color
#     set ::lastx %x 
#     set ::lasty %y
# }
# 
# set id [.canvas create rectangle 10 10 30 30 -fill "red"]
# .canvas bind $id <Button-1> {
# 	set ::color "red"
# }
# 
# set id [.canvas create rectangle 10 35 30 55 -fill "blue"]
# .canvas bind $id <Button-1> {
# 	set ::color "blue"
# }
# 
# set id [.canvas create rectangle 10 60 30 80 -fill "black"]
# .canvas bind $id <Button-1> {
# 	set ::color "black"
# }

################################################################################
### 完整示例

package require Tk

grid [tk::canvas .canvas -scrollregion {0 0 1000 1000} -yscrollcommand ".v set" -xscrollcommand ".h set"] -sticky news -column 0 -row 0
grid columnconfigure . 0 -weight 1
grid rowconfigure . 0 -weight 1
grid [ttk::scrollbar .h -orient horizontal -command ".canvas xview"] -column 0 -row 1 -sticky we
grid [ttk::scrollbar .v -orient vertical   -command ".canvas yview"] -column 1 -row 0 -sticky ns

bind .canvas <Button-1> {
	set ::lastx [.canvas canvasx %x]
	set ::lasty [.canvas canvasy %y]
}
bind .canvas <Button1-Motion> {
 	set x [.canvas canvasx %x]
 	set y [.canvas canvasy %y]
    .canvas create line $::lastx $::lasty $x $y -fill $::color -width 5 -tags "currentline"
    set ::lastx $x 
    set ::lasty $y
}
bind .canvas <Button1-ButtonRelease> {
	.canvas itemconfigure "currentline" -width 1
	.canvas dtag all "currentline"
}

set id [.canvas create rectangle 10 10 50 50 -fill red -tags {"palette" "palettered"}]
.canvas bind $id <Button-1> {
	setColor "red"
}

set id [.canvas create rectangle 10 70 50 110 -fill blue -tags {"palette" "paletteblue"}]
.canvas bind $id <Button-1> {
	setColor "blue"
}

set id [.canvas create rectangle 10 130 50 170 -fill black -tags {"palette" "paletteblack" "paletteSelected"}]
.canvas bind $id <Button-1> {
	setColor "black"
}

proc setColor {color} {
	set ::color $color
	.canvas dtag all "paletteSelected"
	.canvas itemconfigure "palette" -outline "white"
	.canvas addtag "paletteSelected" withtag "palette$color"
	.canvas itemconfigure "paletteSelected" -outline "yellow"
}

set ::lastx 0
set ::lasty 0
set ::color "black"
.canvas itemconfigure palette -width 5 -outline "white"

################################################################################
### 为图形项添加标签

# package require Tk
# 
# wm title . "Canvas addtag 示例"
# 
# canvas .canvas -width 400 -height 300 -background white
# pack .canvas -fill both -expand 1
# 
# .canvas create rectangle 50 50 150 150 -fill blue -tags "rect"
# .canvas addtag "newTag" withtag "rect"
# 
# set tags [.canvas gettags "rect"]
# puts "矩形标签: $tags"  
# 
# tkwait window .

################################################################################
### 为多个图形项添加标签

# package require Tk
# 
# wm title . "Canvas addtag 示例"
# 
# canvas .canvas -width 400 -height 300 -background white
# pack .canvas -fill both -expand 1
# 
# .canvas create rectangle 50 50 150 150 -fill blue
# .canvas create oval 200 100 300 200 -fill green
# 
# .canvas addtag "groupTag" all
# set items [.canvas find withtag "groupTag"]
# foreach item $items {
#     set tags [.canvas gettags $item]
#     puts "图形项 $item 的标签: $tags"
# }
# 
# tkwait window .

################################################################################
### 为指定区域内的图形项添加标签

# package require Tk
# 
# wm title . "Canvas addtag 示例"
# 
# canvas .canvas -width 400 -height 300 -background white
# pack .canvas -fill both -expand 1
# 
# .canvas create rectangle 50 50 150 150 -fill blue
# .canvas create oval 200 100 300 200 -fill green
# 
# .canvas addtag "areaTag" enclosed 40 40 160 160
# 
# set items [.canvas find withtag "areaTag"]
# puts "区域内的图形项: $items"
# 
# tkwait window .

################################################################################
### 从多个图形项中移除标签

# package require Tk
# 
# wm title . "Canvas dtag 示例"
# 
# canvas .canvas -width 400 -height 300 -background white
# pack .canvas -fill both -expand 1
# 
# .canvas create rectangle 50 50 150 150 -fill blue -tags {"groupTag" "rect1"}
# .canvas create oval 200 100 300 200 -fill green -tags {"groupTag" "rect2"}
# 
# set items [.canvas find withtag "groupTag"]
# foreach item $items {
#     set tags [.canvas gettags $item]
#     puts "移除前图形项 $item 的标签: $tags"
# }
# 
# .canvas dtag "groupTag" "groupTag"
# 
# set items [.canvas find withtag "groupTag"]
# foreach item $items {
#     set tags [.canvas gettags $item]
#     puts "移除后图形项 $item 的标签: $tags"
# }
#
# tkwait window .

################################################################################
### 查找所有图形项

# package require Tk
# 
# wm title . "Canvas find 示例"
# 
# canvas .canvas -width 400 -height 300 -background white
# pack .canvas -fill both -expand 1
# 
# .canvas create rectangle 50 50 150 150 -fill blue
# .canvas create oval 200 100 300 200 -fill green
# 
# set items [.canvas find all]
# puts "所有图形项: $items"  ; # 输出: 1 2
# 
# tkwait window .

################################################################################
### 查找具有指定标签的图形项

# package require Tk
# 
# wm title . "Canvas find 示例"
# 
# canvas .canvas -width 400 -height 300 -background white
# pack .canvas -fill both -expand 1
# 
# .canvas create rectangle 50 50 150 150 -fill blue -tags "groupTag"
# .canvas create oval 200 100 300 200 -fill green -tags "groupTag"
# 
# set items [.canvas find withtag "groupTag"]
# puts "具有 groupTag 的图形项: $items"
# 
# tkwait window .

################################################################################
### 查找指定区域内的图形项

# package require Tk
# 
# wm title . "Canvas find 示例"
# 
# canvas .canvas -width 400 -height 300 -background white
# pack .canvas -fill both -expand 1
# 
# .canvas create rectangle 50 50 150 150 -fill blue
# .canvas create oval 200 100 300 200 -fill green
# 
# set items [.canvas find enclosed 40 40 160 160]
# puts "指定区域内的图形项: $items"
# 
# tkwait window .
