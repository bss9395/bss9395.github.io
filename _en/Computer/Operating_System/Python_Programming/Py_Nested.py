""" Py_Nested.py
Author: BSS9395
Update: 2022-08-01T00:51:00+08@China-Shanghai+08
Design: Python Language Feature: Nested Function
"""

def Encapsulate(**params):
    def Square(side):
        return (side * side)
    def Cube(side):
        return (side * side * side)
    def Factorial(inte):
        result = 1
        for i in range(1, inte + 1):
            result *= i
        return result

    if "Square" in params:
        return Square(params["Square"])
    elif "Cube" in params:
        return Cube(params["Cube"])
    elif "Factorial" in params:
        return Factorial(params["Factorial"])

print(Encapsulate(Cube=3.0))
