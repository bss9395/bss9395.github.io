''' Py_functools_reduce.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Standard Library: functools.reduce
'''

import functools

print(functools.reduce(lambda x, y: x + y, range(6)))
print(functools.reduce(lambda x, y: x + y, range(6), 10))
