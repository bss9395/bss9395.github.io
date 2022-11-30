''' Py_itertools_combinations.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Standard Library: itertools.combinations
'''

import itertools

for elem in itertools.combinations("ABCD", 2):
    print("".join(elem), end=", ")
