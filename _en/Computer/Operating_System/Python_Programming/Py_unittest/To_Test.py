''' To_Test.py
Author: BSS9395
Update: 2022-10-23T17:30:00+08@China-Shanghai+08
Design: Python Standard Library: unittest
'''

__all__ = ["_Linear_Equation", "_Quadratic_Equation"]

def _Linear_Equation(a, b):
    '''
    a * x + b = 0
    '''
    if a == 0:
        raise ValueError("参数错误")
    else:
        return (-b / a)

def _Quadratic_Equation(a, b, c):
    '''
    a * x * x + b * x + c = 0
    '''
    if a == 0:
        raise ValueError("参数错误")
    elif b * b - 4 * a * c < 0:
        raise ValueError("方程在有理数范围内无解")
    elif b * b - 4 * a * c == 0:
        return -b / (2 * a)
    else:
        r1 = (-b + (b * b - 4 * a * c) ** 0.5) / (2 * a)
        r2 = (-b - (b * b - 4 * a * c) ** 0.5) / (2 * a)
        return (r1, r2)
