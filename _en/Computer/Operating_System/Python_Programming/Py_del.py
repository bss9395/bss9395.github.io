"""
Py_del.py
Author: BSS9395
Update: 2022-07-30T18:02:+08@China-Shanghai+08
Design: Python Keyword: del
"""

items = [2, 3.4, "5678", (2, 3.4, "5678"), [2, 3.4, "5678"]]
items.extend(range(0, 10))

del items[2]
print(items)

del items[1:3]
print(items)

items.remove(2)
print(items)

items.clear()
print(items)

del items
