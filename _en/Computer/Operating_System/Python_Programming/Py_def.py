"""
Py_def.py
Author: BSS9395
Update: 2022-07-30T23:21:00+08@China-Shanghai+08
Design: Python Language Feature: multiple return values
"""

def Sum_with_Avarage(items):
    sum = 0
    numb = 0
    for item in items:
        if isinstance(item, int) or isinstance(item, float):
            sum += item
            numb += 1
    return (sum, sum / numb)


items = [20, 15, 2.8, 'a', 35, 5.9, -1.8]
sum, avg = Sum_with_Avarage(items)
print("sum == %f, avg == %f" % (sum, avg))
result = Sum_with_Avarage(items)
print(result)
print("sum == %f, avg == %f" % (result[0], result[1]))