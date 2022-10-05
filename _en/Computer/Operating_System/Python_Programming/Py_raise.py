""" Py_raise.py
Author: bss9395
Update: 2022-10-T14:17:00+08@China-Guangdong-Zhanjiang+08
Design: Python Keyword: raise
"""

class CustomException(Exception):
    pass

def Arithmetic():
    try:
        lhs = 12
        # rhs = 4
        rhs = "abc"
        rhs = float(rhs)
    except Exception as ex:
        print(ex)
        # raise CustomException("can not convert rhs to number.")
        # raise CustomException(ex)
        raise

class Main():
    try:
        Arithmetic()
    except CustomException as ex:
        print(ex)
    except Exception as ex:
        print(ex)

Main()
