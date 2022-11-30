''' Py_itertools_compress.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Standard Library: itertools.compress
'''

import itertools

languages = ["C", "C++", "C#", "Java", "Python"]
rates = [1, 1, 0, 1, 0]
for language in itertools.compress(languages, rates):
    print(language, end=", ")
       