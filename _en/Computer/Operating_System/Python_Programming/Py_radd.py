""" Py_radd.py
Author: bss9395
Update: 2022-10-T14:17:00+08@China-Guangdong-Zhanjiang+08
Design: Python Language Feature: __radd__
"""

class Complex():
    def __init__(self, real, imag):
        self.real = real
        self.imag = imag

    def __radd__(self, other):
        if not (isinstance(other, int) or isinstance(other, float)):
            raise TypeError("left hand side is not fload")
        return Complex(self.real + other, self.imag)

    def __repr__(self):
        return "(%lf, %lf)" % (self.real, self.imag)

comp1 = Complex(3.0, 4.0)
comp = 6 + comp1
print(comp)
