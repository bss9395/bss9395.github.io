''' Py_Argument.py
Author: BSS9395
Update: 2022-10-23T17:50:00+08@China-Shanghai+08
Design: Python Language Feature: Argument
'''

def Area(width=3.2, height=2.3):
    print("width == %f, height == %f" % (width, height))
    return (width * height)


print(Area())
print(Area(3.2))
print(Area(3.2, 2.3))
print(Area(height=2.3, width=3.2))
print(Area(3.2, height=2.3))
