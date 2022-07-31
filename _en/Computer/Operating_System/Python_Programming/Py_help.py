"""
Py_help.py
Author: BSS9395
Update: 2022-07-30T23:21:00+08@China-Shanghai+08
Design: Python Built-in Function: help()
"""

def Max(lhs, rhs):
    """
    return the max value of lhs and rhs.
    """
    return (lhs if lhs > rhs else rhs)

help(Max)
print(Max.__doc__)
