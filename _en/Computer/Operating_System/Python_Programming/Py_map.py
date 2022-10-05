""" Py_map.py
Author: bss9395
Update: 2022-10-03T15:00:00+08@China-Guangdong-Zhanjiang+08
Design: Python Standard Library: map
"""

result = map(lambda x: x * x if x % 2 == 1 else 0, range(8))
print(type(result))
print([e for e in result])
