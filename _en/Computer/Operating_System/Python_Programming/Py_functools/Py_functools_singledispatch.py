''' Py_functools_singledispatch.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Standard Library: functools.singledispatch
'''

import functools
from decimal import Decimal

@functools.singledispatch
def _Func(arg, verbose):
    if verbose:
        print("default parameter: ", end="")
    print(arg)

@_Func.register(int)
def _Func_int(arg, verbose):
    if verbose:
        print("int parameter: ", end="")
    print(arg)

def _Func_None(arg, verbose=False):
    if verbose:
        print("None type: ", end="")
    print(arg)
_Func.register(type(None), _Func_None)

@_Func.register(float)
@_Func.register(Decimal)
def _Number(arg, verbose=False):
    if verbose:
        print("float or Decimal parameter: ", end="")
    print(arg / 2)

_Func("C", True)
_Func(90, True)
_Func(None, True)
_Func(100.0, True)


print(_Func_int is _Func)
print(_Func_int is _Func.dispatch(int))
print(_Func.registry.keys())
print(_Func.registry[int])
