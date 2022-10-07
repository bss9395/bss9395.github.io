""" Py_sys.py
Author: bss9395
Update: 2022-10-T14:17:00+08@China-Guangdong-Zhanjiang+08
Design: Python Standard Library: sys
"""

import sys

print(sorted([item for item in dir(sys) if not item.startswith("_") ]))

print(sys.argv[0])
print(sys.byteorder)
print(sys.executable)
print(sys.getfilesystemencoding())
print(sys.maxsize)                  # note: max integer
print(sys.platform)
print(sys.version)
print(sys.winver)

sys.path.append("E:/")
