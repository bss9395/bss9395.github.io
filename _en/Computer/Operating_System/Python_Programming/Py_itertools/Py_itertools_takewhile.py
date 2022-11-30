''' Py_itertools_takewhile.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Standard Library: itertools.takewhile
'''


import itertools

languages = ["C", "C++", "C#", "Java", "Python"]
for elem in itertools.takewhile(lambda x: len(x) <= 3, languages):
    print(elem, end=", ")
