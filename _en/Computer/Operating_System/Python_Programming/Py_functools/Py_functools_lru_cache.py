''' Py_functools_lru_cache.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Standard Library: functools.lru_cache
'''

import functools

@functools.lru_cache(maxsize=32)
def factorial(n):
    print("def factorial(%s):" % n)
    if n == 1:
        return 1
    else:
        return n * factorial(n - 1)


print(factorial(5))
print(factorial(3))
print(factorial(5))
