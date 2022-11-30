''' Py_itertools_cycle.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Standard Library: itertools.cycle
'''


import itertools

count = 0
for elem in itertools.cycle(["C", "C++", "C#", "Java", "Python"]):
    print(elem, end=" ")
    count += 1
    if count >= 10:
        break
