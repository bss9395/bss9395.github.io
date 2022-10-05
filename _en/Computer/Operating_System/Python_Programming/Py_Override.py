""" Py_Override.py
Author: bss9395
Update: 2022-10-03T15:00:00+08@China-Guangdong-Zhanjiang+08
Design: Python Language Feature: Override
"""

class Base(object):
    def info(self):
        print("Base.info")

class Derived(Base):
    def info(self):
        print("Derived.info")
    def func(self):
        print(Derived.func.__name__)
        self.info()
        Base.info(self)

derived = Derived()
derived.func()
