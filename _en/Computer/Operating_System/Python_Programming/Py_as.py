""" Py_as.py
Author: bss9395
Update: 2022-10-T14:17:00+08@China-Guangdong-Zhanjiang+08
Design: Python Keyword: as
"""

try:
    lhs = 12
    rhs = 0
    res = lhs / rhs
except Exception as ex:
    print(ex)
    print(ex.args)
except:
    print("print:")
else:
    print("else:")