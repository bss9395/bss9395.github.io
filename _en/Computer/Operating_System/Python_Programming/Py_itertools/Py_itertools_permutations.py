''' Py_itertools_permutations.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Standard Library: itertools.permutations
'''


import itertools

for elem in itertools.permutations("ABCD", 2):
    print("".join(elem), end=", ")
    