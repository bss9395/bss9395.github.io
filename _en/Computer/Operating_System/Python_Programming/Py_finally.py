""" Py_finally.py
Author: bss9395
Update: 2022-10-T14:17:00+08@China-Guangdong-Zhanjiang+08
Design: Python Keyword: finally
"""

def test():
    try:
        return True
    finally:
        return False

print(test())
