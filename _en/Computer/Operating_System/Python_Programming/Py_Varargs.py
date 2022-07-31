"""
Py_Varargs.py
Author: BSS9395
Update: 2022-08-01T00:51:00+08@China-Shanghai+08
Design: Python Language Feature: Varargs
"""

def Varargs_tuple(numb, *items):
    print(numb)
    print(items)


Varargs_tuple(5, "C", "C++", "Java", "Python", "C#")
Varargs_tuple(5, ("C", "C++", "Java", "Python", "C#"))
Varargs_tuple(5, ["C", "C++", "Java", "Python", "C#"])
Varargs_tuple(5, *("C", "C++", "Java", "Python", "C#"))
Varargs_tuple(5, *["C", "C++", "Java", "Python", "C#"])

################################################################################

def Varargs_dict(numb, *items, **words):
    print(numb)
    print(items)
    print(words)


Varargs_dict(6, "C", "C++", "Java", "C#", python="Python", matlab="Matlab")

################################################################################

arguments = [1, "argu"]
words = { "numb": 1, "item": "argu" }

def Inverse_Varargs(numb, item):
    print(numb)
    print(item)

Inverse_Varargs(*arguments)
Inverse_Varargs(**words)

################################################################################

def Inverse_Varargs_tuple(numb, *items):
    print(numb)
    print(items)

Inverse_Varargs_tuple(2, *arguments)

