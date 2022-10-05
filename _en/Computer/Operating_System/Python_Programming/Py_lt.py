""" Py_it.py
Author: bss9395
Update: 2022-10-T14:17:00+08@China-Guangdong-Zhanjiang+08
Design: Python Language Feature: __lt__
"""

class Rectangle():
    def __init__(self, width, height):
        self.width = width
        self.height = height

    def __lt__(self, other):
        if not isinstance(other, Rectangle):
            raise TypeError("operand is not Rectangle")
        if self.width * self.height < other.width * other.height:
            return True
        else:
            return False

    def __eq__(self, other):
        if not isinstance(other, Rectangle):
            raise TypeError("operand is not Rectangle")
        if self.width * self.height == other.width * other.height:
            return True
        else:
            return False

    def __le__(self, other):
        if not isinstance(other, Rectangle):
            raise TypeError("operand is not Rectangle")
        if self.width * self.height <= other.width * other.height:
            return True
        else:
            return False


lhs = Rectangle(3.0, 4.0)
rhs = Rectangle(6.0, 8.0)
print(lhs < rhs)
print(lhs > rhs)
print(lhs == rhs)
print(lhs != rhs)
print(lhs <= rhs)
print(lhs >= rhs)