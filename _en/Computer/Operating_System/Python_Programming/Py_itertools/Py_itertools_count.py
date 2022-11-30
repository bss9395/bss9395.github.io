''' Py_itertools_count.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Standard Library: itertools.count
'''


import itertools

for value in itertools.count(10, 2):
    print(value)
    if value >= 20:
        break
