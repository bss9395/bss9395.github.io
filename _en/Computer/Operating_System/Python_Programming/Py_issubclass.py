""" Py_issubclass.py
Author: bss9395
Update: 2022-10-03T15:00:00+08@China-Guangdong-Zhanjiang+08
Design: Python Built-in Function: issubclass
"""

data = ["bss9395", 28]
print("data is instance of list: %s" % isinstance(data, list))
print("data is instance of object: %s", isinstance(data, object))
print("data is subclass of list: %s" % issubclass(list, list))
print("data is subclass of object: %s" % issubclass(list, object))
