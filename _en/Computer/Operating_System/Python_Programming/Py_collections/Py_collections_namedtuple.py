''' Py_collections_namedtuple.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Standard Library: namedtuple
'''

import collections as collections

Point1 = collections.namedtuple('Point1', ['x', 'y'])
_point1 = Point1(11, 22)
print(_point1)
print(_point1[0] + _point1[1])
print(_point1.x + _point1.y)
(x, y) = _point1
print(x + y)

################################################################################

Point2 = collections.namedtuple('Point2', ['p', 'q'])
_point2 = Point2._make([11, 22])
print(_point2)
print(_point2._asdict())
print(_point2._fields)
Point3 = collections.namedtuple("Point3", Point1._fields + Point2._fields)
_point3 = Point3(11, 22, 33, 44)
print(_point3)

################################################################################

_point4 = Point3([], [], [], [])
_point4.x.append(11)
_point4[1].append(22)
print(_point4)
