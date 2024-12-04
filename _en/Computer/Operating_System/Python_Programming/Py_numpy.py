## Py_numpy.py
# Author: BSS9395
# Update: 2024-11-07T12:42:00+08@China-Guangdong-Zhanjiang+08

# python外置数学类函数库numpy，numpy库不支持复数类型。
import numpy

def function_0():
    try:
        array_numerator   = numpy.array([+0, 1, 0, 0, -1, -1, -1])
        array_denominator = numpy.array([-0, 0, 1, 0, +0, -0, -1])

        array_quotient    = array_numerator / array_denominator
        print('array_numerator   = ', array_numerator)
        print('array_denominator = ', array_denominator)
        print('array_quotient    = ', array_quotient)
    except Exception as err:
        print(err)

def function_1():
    try:
        array_numerator = numpy.array([+0, -0, +1, -1])
        array_nan       = numpy.array([numpy.nan, numpy.nan, numpy.nan, numpy.nan])
        array_inf       = numpy.array([+numpy.inf, +numpy.inf, +numpy.inf, +numpy.inf])
        array_ninf      = numpy.array([-numpy.inf, -numpy.inf, -numpy.inf, -numpy.inf])
        print('array_numerator      = ', array_numerator)
        print('array_nan            = ', array_nan)
        print('array_inf            = ', array_inf)
        print('array_ninf           = ', array_ninf)

        array_addition       = numpy.add(array_numerator, array_nan)
        array_subtraction    = numpy.subtract(array_numerator, array_nan)
        array_multiplication = numpy.multiply(array_numerator, array_nan)
        array_division       = numpy.divide(array_numerator, array_nan)
        print('array_addition       = ', array_addition)
        print('array_subtraction    = ', array_subtraction)
        print('array_multiplication = ', array_multiplication)
        print('array_division       = ', array_division)

        array_addition       = numpy.add(array_numerator, array_inf)
        array_subtraction    = numpy.subtract(array_numerator, array_inf)
        array_multiplication = numpy.multiply(array_numerator, array_inf)
        array_division       = numpy.divide(array_numerator, array_inf)
        print('array_addition       = ', array_addition)
        print('array_subtraction    = ', array_subtraction)
        print('array_multiplication = ', array_multiplication)
        print('array_division       = ', array_division)

        array_addition       = numpy.add(array_numerator, array_ninf)
        array_subtraction    = numpy.subtract(array_numerator, array_ninf)
        array_multiplication = numpy.multiply(array_numerator, array_ninf)
        array_division       = numpy.divide(array_numerator, array_ninf)
        print('array_addition       = ', array_addition)
        print('array_subtraction    = ', array_subtraction)
        print('array_multiplication = ', array_multiplication)
        print('array_division       = ', array_division)
    except Exception as err:
        print(err)

def function_2():
    try:
        array_numerator   = numpy.array([numpy.nan, +numpy.inf, -numpy.inf, numpy.inf,  numpy.inf, -numpy.inf])
        array_denominator = numpy.array([numpy.nan,  numpy.nan,  numpy.nan, numpy.inf, -numpy.inf, -numpy.inf])
        print('array_numerator   = ', array_numerator)
        print('array_denominator = ', array_denominator)

        array_summation = array_numerator + array_denominator
        array_quotient  = array_numerator / array_denominator
        array_equal     = array_numerator == array_denominator
        array_notequal  = array_numerator != array_denominator
        print('array_summation = ', array_summation)
        print('array_quotient  = ', array_quotient)
        print('array_equal     = ', array_equal)
        print('array_notequal  = ', array_notequal)
    except Exception as err:
        print(err)

def function_3():
    try:
        array_numerator = numpy.array([+1, 0, -1, numpy.nan, numpy.inf, -numpy.inf])
        print('array_numerator = ', array_numerator)

        array_result    = numpy.sqrt(array_numerator)
        print('array_result    = ', array_result)
    except Exception as err:
        print(err)

if __name__ == '__main__':
    # function_0()
    # function_1()
    # function_2()
    function_3()
