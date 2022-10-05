""" Py_Extends.py
Author: bss9395
Update: 2022-10-03T15:00:00+08@China-Guangdong-Zhanjiang+08
Design: Python Language Feature: Extends
"""

class Fruit():
    def info(self):
        print("Fruit.info")

class Food():
    def info(self):
        print("Food.info")

class Apple1(Fruit, Food):
    pass

class Apple2(Food, Fruit):
    pass

apple1 = Apple1()
apple1.info()

apple2 = Apple2()
apple2.info()
