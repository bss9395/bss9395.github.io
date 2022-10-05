""" Py_Polymorphism.py
Author: bss9395
Update: 2022-10-03T15:00:00+08@China-Guangdong-Zhanjiang+08
Design: Python Language Feature: Polymorphism
"""

class Shape():
    def draw(self):
        print("Canvas")

class Retangle(Shape):
    def draw(self):
        print("Retangle")

class Triangle(Shape):
    def draw(self):
        print("Triangle")

class Circle(Shape):
    def draw(self):
        print("Circle")

shape = Triangle()
shape = Retangle()
shape.draw()
print(hasattr(shape, "draw"))
print(hasattr(shape.draw, "__call__"))
