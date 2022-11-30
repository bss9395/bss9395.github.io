''' Py_collections_defaultdict.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Standard Library: defaultdict
'''

import collections as collections

def _Func():
    return "value"

_default = collections.defaultdict(_Func)
_dict = {}
print(_default["key"])
try:
    print(_dict["key"])
except KeyError:
    pass

################################################################################

_items = [("C", 1), ("C++", 2), ("C#", 3), ("Java", 4), ("C", 5), ("Java", 6)]
_dict = {}
for (key, value) in _items:
    _dict.setdefault(key, []).append(value)
print(_dict)

_dict = collections.defaultdict(list)
for (key, value) in _items:
    _dict[key].append(value)
print(_dict)
