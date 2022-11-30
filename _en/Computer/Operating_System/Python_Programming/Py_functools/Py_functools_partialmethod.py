''' Py_functools_partialmethod.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Standard Library: functools.partialmethod
'''

import functools

class Cell(object):
    def __init__(self):
        self._alive = False
    def _Set_State(self, state):
        self._alive = bool(state)
    _Set_Alive = functools.partialmethod(_Set_State, True)
    _Set_Dead = functools.partialmethod(_Set_State, False)
    _Abc = functools.partial(_Set_State, state=True)

_cell = Cell()
print(_cell._alive)
_cell._Set_Alive()
print(_cell._Set_Alive)
print(_cell._alive)
