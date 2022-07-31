"""
Py_while.py
Author: BSS9395
Update: 2022-07-30T23:21:00+08@China-Shanghai+08
Design: Python Language Feature: while-loop
"""

items = [12, 45, 34, 13, 100, 24, 56, 74, 109]
items_0 = []
items_1 = []
items_2 = []
while 0 < len(items):
    item = items.pop()
    if item % 3 == 0:
        items_0.append(item)
    elif item % 3 == 1:
        items_1.append(item)
    else:
        items_2.append(item)
print("items_0 == ", items_0)
print("items_1 == ", items_1)
print("items_2 == ", items_2)
