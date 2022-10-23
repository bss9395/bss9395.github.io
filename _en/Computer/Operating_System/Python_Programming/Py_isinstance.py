""" Py_isinstance.py
Author: BSS9395
Update: 2022-07-30T23:21:00+08@China-Shanghai+08
Design: Python Built-in Function: isinstance()
"""

items = [12, 45, 3.4, 13, "a", 4, 56, "BSS9395", 109.5]
sum = 0
numb = 0
for item in items:
    if isinstance(item, int) or isinstance(item, float):
        print(item)
        sum += item
        numb += 1
print("sum == ", sum, sep="")
print("avg == ", sum / numb, sep="")
