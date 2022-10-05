""" Py_Generator.py
Author: bss9395
Update: 2022-10-T14:17:00+08@China-Guangdong-Zhanjiang+08
Design: Python Language Feature: Generator
"""

def Generator():
    value = yield 1
    yield value
    return None

generator = Generator()
print(next(generator))
print(generator.send("I am Value"))
