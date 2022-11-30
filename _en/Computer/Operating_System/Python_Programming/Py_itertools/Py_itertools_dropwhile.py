''' Py_itertools_dropwhile.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Standard Library: itertools.dropwhile
'''


import itertools

languages = ["C", "C++", "C#", "Java", "Python"]
for elem in itertools.dropwhile(lambda x: len(x) <= 3, languages):
    print(elem, end=", ")
