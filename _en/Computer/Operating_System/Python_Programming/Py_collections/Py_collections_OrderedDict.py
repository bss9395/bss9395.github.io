''' Py_collections_OrderedDict.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Standard Library: OrderedDict
'''

import collections as collections

_dict = collections.OrderedDict()
_dict["C"] = 90
_dict["C++"] = 80
_dict["C#"] = 50
_dict["Java"] = 90
print(_dict)
_dict1 = collections.OrderedDict(sorted(_dict.keys(), key=lambda t: t[0]))
_dict2 = collections.OrderedDict(sorted(_dict.items(), key=lambda t: t[1]))
print(_dict1)
print(_dict2)
print(_dict1 == _dict2)
