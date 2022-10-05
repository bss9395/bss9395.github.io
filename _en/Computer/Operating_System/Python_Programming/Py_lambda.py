""" Py_lambda.py
Author: bss9395
Update: 2022-10-03T15:00:00+08@China-Guangdong-Zhanjiang+08
Design: Python Keyword: lambda
"""

def function(data, chose):
    func = lambda n: n * n
    if chose == "square":
        func = lambda n: n * n
    elif chose == "cube":
        func = lambda n: n * n * n

    result = list()
    for datum in data:
        result.append(func(datum))
    return result


data = [4, 6, 7, 5]
print(function(data, "square"))
print(function(data, "cube"))
