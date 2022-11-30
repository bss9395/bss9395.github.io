''' Py_functools_total_ordering.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Standard Library: functools.total_ordering
'''

import functools

@functools.total_ordering
class Language(object):
    def __init__(self, name):
        self._name = name
    def __repr__(self):
        return "Language[_name=%s]" % self._name
    def _Is_Valid_Operand(self, rhs):
        return hasattr(rhs, "_name")
    def __eq__(self, rhs):
        if not self._Is_Valid_Operand(rhs):
            return NotImplemented
        return self._name.lower() == rhs._name.lower()
    def __lt__(self, rhs):
        if not self._Is_Valid_Operand(rhs):
            return NotImplemented
        return self._name.lower() < rhs._name.lower()

_cplusplus = Language("C++")
_csharp = Language("C#")
print(_cplusplus > _csharp)
