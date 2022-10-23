""" Py_globals.py
Author: BSS9395
Update: 2022-08-01T00:51:00+08@China-Shanghai+08
Design: Python Built-in Function: globals()
"""

def Func(param = "param"):
    vari = "vari"
    globals()["x"] = 1.0
    locals()["x"] = "x"
    print(dict(item for item in globals().items() if not item[0].startswith("__")))
    print(dict(item for item in locals().items() if not item[0].startswith("__")))


param = 3.2
vari = 2.3

print(dict(item for item in globals().items() if not item[0].startswith("__")))
print(dict(item for item in locals().items() if not item[0].startswith("__")))
Func()
