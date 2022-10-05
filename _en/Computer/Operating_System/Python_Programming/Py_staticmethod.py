""" Py_staticmethod.py
Author: bss9395
Update: 2022-10-03T15:00:00+08@China-Guangdong-Zhanjiang+08
Design: Python Language Feature: staticmethod
"""

class Person():
    @classmethod
    def Walk(cls):
        print("classmethod")
    @staticmethod
    def Run():
        print("staticmethod")

Person.Walk()
Person.Run()
