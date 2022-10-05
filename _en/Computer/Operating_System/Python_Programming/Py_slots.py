""" Py_slots.py
Author: bss9395
Update: 2022-10-03T15:00:00+08@China-Guangdong-Zhanjiang+08
Design: Python Language Feature: slot
"""

class Person():
    __slots__ = ("geet", "name", "age")
    def __init__(self, name, age):
        self.name = name
        self.age = age
    def info(self):
        print("name = %s, age = %d" % self.name, self.age)

def greet(self):
    print("hello world")
person = Person("bss9395", 28)
# person.id = "1156"  # note: error
person.geet = greet
