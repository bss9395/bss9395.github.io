''' Py_itertools_zip_longest.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Standard Library: itertools.zip_longest
'''


import itertools

for elem in itertools.zip_longest("xy", "ABCD", fillvalue="-"):
    print(elem, end=", ")
