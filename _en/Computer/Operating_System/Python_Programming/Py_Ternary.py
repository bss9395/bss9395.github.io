"""
Py_Ternary.py
Author: BSS9395
Update: 2022-07-29T23:55:00+08@China-Shanghai+08
Design: Python Language Feature: Ternary operator
"""

lhs = 2.3
rhs = 3.2

result = "lhs < rhs" if (lhs < rhs) else "lhs >= rhs"
print(result)


result = "lhs < rhs" if (lhs < rhs) else "lhs == rhs" if (lhs == rhs) else "lhs > rhs"
print(result)
