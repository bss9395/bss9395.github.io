""" Py_file.py
Author: BSS9395
Update: 2022-07-29T00:44:00+08@China-Shanghai+08
Design: Python Built-in Function: open()
"""

file = open("temp.txt", "w")
print("长江后浪推前浪，", file=file)
print("前浪拍在沙滩上。", file=file)
