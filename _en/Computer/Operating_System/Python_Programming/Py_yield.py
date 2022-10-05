""" Py_yield.py
Author: bss9395
Update: 2022-10-T14:17:00+08@China-Guangdong-Zhanjiang+08
Design: Python Keyword: yield
"""

def Fibonacci(numb):
    first = 0
    second = 1
    i = 0
    while i < numb:
        yield first
        first, second = second, first + second
        i += 1

print(list(Fibonacci(10)))