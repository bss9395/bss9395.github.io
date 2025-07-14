
pkg_mkIndex "./CustomPackage/" "*.tcl"
lappend auto_path "./CustomPackage/"

package require HelloWorld 1.0

puts [HelloWorld::MyProcedure]
