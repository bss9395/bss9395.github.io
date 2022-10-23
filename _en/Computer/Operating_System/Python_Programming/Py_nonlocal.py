""" Py_nonlocal.py
Author: BSS9395
Update: 2022-08-01T00:51:00+08@China-Shanghai+08
Design: Python Keyword: nonlocal
"""

def Encapsulate():
    print(Encapsulate.__name__)
    param = "local"
    def Nested():
        print(Nested.__name__)
        nonlocal param
        print(param)
        param = "nested"
    Nested()
    print(param)
Encapsulate()
