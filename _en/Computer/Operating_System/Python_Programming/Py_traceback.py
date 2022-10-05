""" Py_traceback.py
Author: bss9395
Update: 2022-10-T14:17:00+08@China-Guangdong-Zhanjiang+08
Design: Python Standard Library: traceback
"""

import traceback

class CustomException(Exception):
    pass

def Third():
    raise CustomException("Custom Exception")

def Second():
    Third()

def First():
    Second()

def Main():
    First()


try:
    Main()
except Exception as ex:
    print(ex)
    traceback.print_exc()
    traceback.print_exc(file=open("log.txt", 'a+'))