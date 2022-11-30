''' Py_functools_partial.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Standard Library: functools.partial
'''

import functools

_Base_Two = functools.partial(int, base=2)
_Base_Two.__doc__ = 'Convert a binary string to an integer.'
print(_Base_Two("1010"))
print(int("1010", base=2))
