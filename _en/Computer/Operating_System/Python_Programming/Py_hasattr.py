""" Py_hasattr.py
Author: bss9395
Update: 2022-10-T14:17:00+08@China-Guangdong-Zhanjiang+08
Design: Python Language Feature: __hasattr__
"""

class Person():
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def Info(self):
        print("%r: %d" % (self.name, self.age))

person = Person("bs9395", 28)
print(hasattr(person, "age"))
print(hasattr(person, "Info"))

def Func():
    print("'maker': 29")
setattr(person, "age", 29)
setattr(person, "Info", Func)

print(getattr(person, "age"))
getattr(person, "Info")()