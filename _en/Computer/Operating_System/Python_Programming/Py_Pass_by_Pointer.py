""" Py_Pass_by_Pointer.py
Author: BSS9395
Update: 2022-08-01T00:51:00+08@China-Shanghai+08
Design: Python Language Feature: Pass by Pointer
"""

def Swap(lhs, rhs):
    print(Swap.__name__)
    lhs, rhs = rhs, lhs
    print("lhs == %f, rhs == %f" % (lhs, rhs))

lhs = 3.2
rhs = 2.3
Swap(lhs, rhs)
print("lhs == %f, rhs == %f" % (lhs, rhs))

################################################################################

def Swap(pointer):
    print(Swap.__name__)

    pointer[0] = "abc"
    pointer[1] = "def"
    print(pointer)
    del pointer

pointer = ["0", "1"]
Swap(pointer)
print(pointer)
