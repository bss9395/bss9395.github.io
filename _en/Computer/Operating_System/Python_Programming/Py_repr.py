"""
Py_repr.py
Author: BSS9395
Update: 2022-07-29T23:55:00+08@China-Shanghai+08
Design: Python Built-in Function: repr()
"""

string = "value == "
value = 99.8

print(string)
print(str(string))
print(repr(string))

print(value)
print(str(value))
print(repr(value))

print(string + str(value))
print(string + repr(value))
