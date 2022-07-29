"""
Py_Format.py
Author: BSS9395
Update: 2022-07-29T23:55:00+08@China-Shanghai+08
Design: Python Language Feature: Format
"""

name = 'BSS9395'
age  = -28
print("%s is %d old." % (name, age))

print("%+-6i" % age)
print("%+-6d" % age)
print("%+-6o" % age)
print("%+-6X" % age)
print("%+-6E" % age)
print("%+-6F" % age)
print("%+-6G" % age)
print("%+-6c" % name[0])
print("%+-6r" % name)
print("%+-6s" % name)
