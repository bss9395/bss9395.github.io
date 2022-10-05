""" Py_Enum.py
Author: bss9395
Update: 2022-10-03T15:00:00+08@China-Guangdong-Zhanjiang+08
Design: Python Standard Library: Enum
"""

import enum

Season = enum.Enum("Season", (
    "Spring", "Summer", "Fall", "Winter"
))

print(Season.Spring)
print(Season.Spring.name)
print(Season.Spring.value)
print(Season["Summer"])
for name, member in Season.__members__.items():
    print("%6s: %13s, %s" % (name, member, member.value))

################################################################################

class Orientation(enum.Enum):
    East = "east", 1
    South = "South", 2
    West = "West", 3
    North = "North", 4

    def greet(self):
        print("Hello, world!")

print(Orientation.South)
print(Orientation.South.name)
print(Orientation.South.value)
print(Orientation["South"])
for name, member in Orientation.__members__.items():
    print("%6s: %17s, %s" % (name, member, member.value))

print(type(Orientation.South))
Orientation.South.greet()
