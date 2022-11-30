''' Py_Decorator.py
Author: BSS9395
Update: 2022-11-06T21:18:00+08@China-Shanghai+08
Design: Python Language Feature: Decorator
'''

import time

class Decorator:
    def _Decorate(self, arg):
        print("format={}".format(arg))
        def _Decorator(func):
            def _Wrapper(*args, **keywords):
                call_time = ""
                if arg == "y":
                    call_time = time.strftime("%y-%m-%d", time.localtime())
                elif arg == "Y":
                    call_time = time.strftime("%Y-%m-%d", time.localtime())
                print("call_time={}, func_name={}, args={}, keywords={}".format(call_time, func.__name__, args, keywords))
                func(*args, **keywords)
            return _Wrapper
        return _Decorator

decorate = Decorator()
@decorate._Decorate("y")
def _Func1(a, b):
    print("def _Func1(a, b):")

@decorate._Decorate("Y")
def _Func2(a, b):
    print("def _Func2(a, b):")

_Func1(1, 2)
_Func2(3, 4)

