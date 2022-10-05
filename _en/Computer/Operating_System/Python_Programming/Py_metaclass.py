""" Py_metaclass.py
Author: bss9395
Update: 2022-10-03T15:00:00+08@China-Guangdong-Zhanjiang+08
Design: Python Language Feature: metaclass
"""

class MetaClass(type):
    def __new__(cls, name, bases, attrs):
        def greet(self):
            print("hello %s!" % self.name)
        attrs["greet"] = greet
        return type.__new__(cls, name, bases, attrs)

class Person(metaclass=MetaClass):
    def __init__(self, name):
        self._name = name
    @property
    def name(self):
        return self._name
    @name.setter
    def name(self, name):
        self._name = name

class Child(metaclass=MetaClass):
    def __init__(self, name):
        self._name = name
    @property
    def name(self):
        return self._name
    @name.setter
    def name(self, name):
        self._name = name

person = Person("bss9395")
person.greet()
child = Child("bss9395")
child.name = "child"
child.greet()
