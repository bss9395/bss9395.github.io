""" Py_setattr.py
Author: bss9395
Update: 2022-10-T14:17:00+08@China-Guangdong-Zhanjiang+08
Design: Python Language Feature: __setattr__
"""

class Rectangle():
    def __init__(self, width, height):
        print("def __init__(self, width, height):")
        self.width = width
        self.height = height

    def __getattr__(self, key):
        print("__getattr__: %r" % key)
        if key == "size":
            return (self.width, self.height)
        else:
            raise AttributeError

    def __setattr__(self, key, value):
        print("__setattr__: %r" % key)
        if key == "size":
            self.width, self.height = value
        else:
            self.__dict__[key] = value

    def __delattr__(self, key):
        print("__delattr__: %r" % key)
        if key == "size":
            self.width = 0.0
            self.height = 0.0

rectangle = Rectangle(3.0, 4.0)
print(rectangle.size)
rectangle.size = (6.0, 8.0)
rectangle.width = 4.5
del rectangle.size
print(rectangle.size)

################################################################################

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
