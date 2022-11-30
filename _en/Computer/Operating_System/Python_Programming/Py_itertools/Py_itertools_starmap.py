''' Py_itertools_starmap.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Standard Library: itertools.starmap
'''

import itertools

for value in itertools.starmap(pow, [(2, 5), (3, 2), (10, 3)]):
    print(value, end=", ")
    