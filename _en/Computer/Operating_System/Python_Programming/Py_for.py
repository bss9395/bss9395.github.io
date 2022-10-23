""" Py_for.py
Author: BSS9395
Update: 2022-07-30T23:21:00+08@China-Shanghai+08
Design: Python Language Feature: for expression
"""

factorial = 1
for inte in range(1, 11):
    factorial *= inte
print(factorial)

################################################################################

square = [x * x for x in range(1, 11) if x % 2 == 0]
print(square)

coordinate = ((x, y) for x in range(1, 4) for y in range(1, 5))
print(coordinate)

