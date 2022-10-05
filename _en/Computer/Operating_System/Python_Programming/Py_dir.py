""" Py_dir.py
Author: bss9395
Update: 2022-10-T14:17:00+08@China-Guangdong-Zhanjiang+08
Design: Python Language Feature: __dir__
"""


class Item():
    def __init__(self, name):
        self.name = name

    def Info(self):
        print(self.name)


item = Item("Apple")
print(item.__dir__())
print(dir(item))
