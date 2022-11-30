''' Py_functools_cmp_to_key.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Standard Library: functools.cmp_to_key
'''

import functools

class Language:
    def __init__(self, name):
        self._name = name

    def __repr__(self):
        return 'User[_name=%s]' % self._name


def old_cmp(value1, value2):
    print(value1, value2)
    return len(value1._name) - len(value2._name)


languages = [Language("C++"), Language("C"), Language("C#"), Language("Java")]
languages.sort(key=functools.cmp_to_key(old_cmp))
print(languages)
