""" Py_repr.py
Author: BSS9395
Update: 2022-07-29T23:55:00+08@China-Shanghai+08
Design: Python Built-in Function: repr()
"""

string = "value == "
value = 99.8

print(string)
print(str(string))
print(repr(string))

print(value)
print(str(value))
print(repr(value))

print(string + str(value))
print(string + repr(value))

################################################################################

case = "  hello, world!  "
print("%r" % case.title())
print("%r" % case.lower())
print("%r" % case.upper())

################################################################################

print("%r" % case.strip())
print("%r" % case.lstrip())
print("%r" % case.rstrip())

################################################################################

print("%r" % case.strip(" he!"))
print("%r" % case.lstrip(" he!"))
print("%r" % case.rstrip(" he!"))

################################################################################

print(case.startswith("he"))
print(case.endswith("ld!  "))
print(case.find("he"))
print(case.index("he"))
print("%r" % case.replace("he", "we"))

################################################################################

table = str.maketrans("hew", "HEm")
print("%r" % table)
print("%r" % case.translate(table))

################################################################################

print(case.split())
print(case.split(","))

words = case.split(",")
print("%r" % "/".join(words))

################################################################################

class Apple():
    def __init__(self, color):
        self.color = color
    def __repr__(self):
        return "Apple[color=" + self.color + "]"

apple = Apple("青色")
print(apple)
