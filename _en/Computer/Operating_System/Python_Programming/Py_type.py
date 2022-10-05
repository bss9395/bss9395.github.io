""" Py_type.py
Author: bss9395
Update: 2022-10-03T15:00:00+08@China-Guangdong-Zhanjiang+08
Design: Python Built-in Function: type()
"""

class Person():
    pass

person = Person()
print(type(person))
print(type(Person))

################################################################################

def func(self):
    print("hello, world!")

Child = type("Child", (object, ), dict(greet=func, name="bss9395"))
child = Child()
print(type(child))
print(type(Child))
child.greet()
