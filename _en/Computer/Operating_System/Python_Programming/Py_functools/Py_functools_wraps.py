''' Py_functools_wraps.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Standard Libray: functools.wraps
'''

import functools

def _Decorator(func):
    @functools.wraps(func)
    def _Wrapper(*args, **keywords):
        print("def _Wrapper(*args, **keywords):")
        return func(*args, **keywords)
    return _Wrapper

@_Decorator
def _Func():
    '''
    Documentation of _Func().
    '''
    print("def _Func():")

_Func()
print(_Func.__name__)
print(_Func.__doc__)
