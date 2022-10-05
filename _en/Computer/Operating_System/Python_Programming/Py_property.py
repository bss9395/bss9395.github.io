""" Py_property.py
Author: bss9395
Update: 2022-10-03T15:00:00+08@China-Guangdong-Zhanjiang+08
Design: Python Language Feature: property
"""

class Rectangle():
    def __init__(self, width, height):
        self.width = width
        self.height = height
    def setsize(self, size):
        self.width, self.height = size
    def getsize(self):
        return self.width, self.height
    def delsize(self):
        self.width, self.height = 0, 0
    size = property(getsize, setsize, delsize, "用于描述矩形的大小")

print(Rectangle.size.__doc__)

rect = Rectangle(3, 4)
print(rect.size)

rect.size = 6, 8
print(rect.size)

del rect.size
print(rect.width)
print(rect.height)

################################################################################

class Property():
    def __init__(self):
        self._state = ""
    @property
    def state(self):
        return self._state
    @state.setter
    def state(self, value):
        if "alive" in value.lower():
            self._state = "alive"
        else:
            self._state = "dead"
    @property
    def is_dead(self):
        return self._state.lower() != "alive"

prop = Property()
prop.state = "alive"
print(prop.state)
print(prop.is_dead)
