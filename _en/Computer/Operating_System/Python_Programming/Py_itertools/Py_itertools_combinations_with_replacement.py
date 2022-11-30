''' Py_itertools_combinations_with_replacement.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Standard Library: itertools.combination_with_replacement
'''

import itertools

for elem in itertools.combinations_with_replacement("ABCD", 2):
    print("".join(elem), end=", ")
