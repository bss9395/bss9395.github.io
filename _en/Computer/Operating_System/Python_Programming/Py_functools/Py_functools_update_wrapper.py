''' Py_functools_update_wrapper.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Standard Library: functools.update_wrapper
'''

import functools

def _Decorator(func):
    def _Wrapper(*args, **keywords):
        print("def _Wrapper(*args, **keywords):")
        return func(*args, **keywords)
    functools.update_wrapper(_Wrapper, func)
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
