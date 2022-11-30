''' Py_itertools_accumulate.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Standard Library: itertools.accumulate
'''

import itertools

for elem in itertools.accumulate(range(6)):
    print(elem, end=', ')
print()


for elem in itertools.accumulate(range(1, 6), lambda x, y: x * y):
    print(elem, end=', ')
