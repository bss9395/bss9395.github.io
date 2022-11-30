''' Py_collections_Counter.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Standard Library: Counter
'''

import collections as collections

counter = collections.Counter(["C", "C++", "C#", "Java", "C++", "C"])
print(counter)
counter = collections.Counter({"name": "bss9395", "age": 29})
print(counter["name"])
print(counter["age"])
