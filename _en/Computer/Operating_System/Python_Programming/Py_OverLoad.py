""" Py_OverLoad.py
Author: BSS9395
Update: 2022-08-01T00:51:00+08@China-Shanghai+08
Design: Python Language Feature: OverLoad
"""

def OverLoad(param, **params):
    print(OverLoad.__name__)
    if isinstance(param, int):
        print("int")
    elif isinstance(param, str):
        print("str")
    if "name" in params:
        print(params["name"])


OverLoad(123, name="abc")
