""" Py_bases.py
Author: bss9395
Update: 2022-10-03T15:00:00+08@China-Guangdong-Zhanjiang+08
Design: Python Standard Library: __bases__
"""

class Father():
    pass

class Mother():
    pass

class Child(Father, Mother):
    pass

print(Father.__bases__)
print(Child.__bases__)

print(Father.__subclasses__())
print(Child.__subclasses__())
