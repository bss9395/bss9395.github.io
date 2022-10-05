""" Py_help.py
Author: bss9395
Update: 2022-10-03T15:00:00+08@China-Guangdong-Zhanjiang+08
Design: Python Builtin Function: help
"""

class Person:
    """
    This is class Person.
    """
    hair = "black"
    def __init__(self, name, age):
        self.name = name
        self.age = age
    def greet(self, message):
        print(message)

help(Person)
person = Person("bss9395", 28)
