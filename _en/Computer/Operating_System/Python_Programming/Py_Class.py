""" Py_Class.py
Author: bss9395
Update: 2022-10-03T15:00:00+08@China-Guangdong-Zhanjiang+08
Design: Python Language Feature: Class
"""

class Person:
    """
    This is class Person.
    """
    hair = "black"
    def __init__(self, name):
        self.name = name

    def greet(self, message):
        print(message, self.name)
        self.welcome()

    def welcome(self):
        print("welcome you")


person = Person("bss9395")
person.greet("hello")

def func(self, message):
    print(message, self.name)
person.func = func
person.func(person, "hi")
