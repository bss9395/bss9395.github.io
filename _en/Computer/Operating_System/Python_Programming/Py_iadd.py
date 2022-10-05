""" Py_iadd.py
Author: bss9395
Update: 2022-10-T14:17:00+08@China-Guangdong-Zhanjiang+08
Design: Python Language Feature: __iadd__
"""

class Complex():
    def __init__(self, real, imag):
        self.real = real
        self.imag = imag

    def __iadd__(self, other):
        if not isinstance(other, Complex):
            raise TypeError("right hand side is not Complex")
        # self.real += other.real
        # self.imag += other.imag
        # return self
        return Complex(self.real + other.real, self.imag + other.imag)

    def __repr__(self):
        return "(%lf, %lf)" % (self.real, self.imag)


comp1 = Complex(3.0, 4.0)
comp2 = Complex(6.0, 8.0)
comp1 += comp2
print(comp1)
