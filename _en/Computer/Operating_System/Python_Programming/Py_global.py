"""
Py_global.py
Author: BSS9395
Update: 2022-08-01T00:51:00+08@China-Shanghai+08
Design: Python Keyword: global
"""

param = "global"
def Func():
    global param
    print(param)
    param = "local"

Func()
print(param)

################################################################################

param = "global"
def Funcs():
    print(globals()["param"])
    param = "local"

Funcs()
print(param)