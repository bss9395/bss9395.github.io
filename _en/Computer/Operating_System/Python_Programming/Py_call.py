""" Py_call.py
Author: bss9395
Update: 2022-10-T14:17:00+08@China-Guangdong-Zhanjiang+08
Design: Python Language Feature: __call__
"""

class Person():
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def __call__(self):
        print("def __call__(self):")

    def Info(self):
        print("%s: %d" % (self.name, self.age))


person = Person("bss9395", 28)
print(hasattr(person.name, "__call__"))
print(hasattr(person.Info, "__call__"))

print(hasattr(person, "__call__"))
person()
person.__call__()
