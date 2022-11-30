''' Py_itertools_filterfalse.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Standard Library: itertools.filterfalse
'''


import itertools

languages = ["C", "C++", "C#", "Java", "Python"]
for language in itertools.filterfalse(lambda x: len(x) <= 3, languages):
    print(language, end=", ")
    