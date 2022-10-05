""" Py_Decorator.py
Author: bss9395
Update: 2022-10-03T15:00:00+08@China-Guangdong-Zhanjiang+08
Design: Python Language Feature: Decorator
"""


def Decorator(decorated):
    def Func(*args):
        print("before decorated")
        decorated(*args)
        print("after decorated")
    return Func

@Decorator
def Decorated(greet):
    print(greet)

Decorated("Hello, world!")
