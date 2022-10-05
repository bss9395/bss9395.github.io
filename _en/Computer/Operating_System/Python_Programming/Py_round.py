""" Py_round.py
Author: bss9395
Update: 2022-10-T14:17:00+08@China-Guangdong-Zhanjiang+08
Design: Python Keyword: round
"""

class Complex():
    def __init__(self, real, imag):
        self.real = real
        self.imag = imag
    def __repr__(self):
        return "(%lf, %lf)" % (self.real, self.imag)
    def __round__(self, ndigits=0):
        return Complex(round(self.real, ndigits), round(self.imag, ndigits))

comp = Complex(3.4, 4.5)
print(round(comp))
