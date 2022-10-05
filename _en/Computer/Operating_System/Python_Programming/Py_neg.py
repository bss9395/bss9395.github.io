""" Py_neg.py
Author: bss9395
Update: 2022-10-T14:17:00+08@China-Guangdong-Zhanjiang+08
Design: Python Language Feature: __neg__
"""

class Complex():
    def __init__(self, real, imag):
        self.real = real
        self.imag = imag

    def __neg__(self):
        return Complex(-self.real, -self.imag)

    def __repr__(self):
        return "(%lf, %lf)" % (self.real, self.imag)


comp = Complex(3.0, 4.0)
print(-comp)
print(comp)
