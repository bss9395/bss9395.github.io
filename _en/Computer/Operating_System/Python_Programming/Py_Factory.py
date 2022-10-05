""" Py_Factor.py
Author: bss9395
Update: 2022-10-03T15:00:00+08@China-Guangdong-Zhanjiang+08
Design: Python Language Feature: Factory
"""

def function(data, chose):
    def square(numb):
        return numb * numb

    def factorial(numb):
        result = 1
        for i in range(2, numb + 1):
            result *= i
        return result

    func = square
    if chose == "square":
        func = square
    elif chose == "factorial":
        func = factorial

    result = list()
    for datum in data:
        result.append(func(datum))
    return result

data = [4, 6, 7, 5]
print(function(data, "square"))
print(function(data, "factorial"))
