""" Py_fnmatch.py
Author: bss9395
Update: 2022-10-07T08:57:00+08@China-Guangdong-Zhanjiang+08
Design: Python Standard Library: fnmatch
"""

import pathlib
import fnmatch

for file in pathlib.Path().iterdir():
    if fnmatch.fnmatch(file, "*match*"):
        print(file)

################################################################################

files = ["a.py", "b.py", "c.py", "d.py"]
file = fnmatch.filter(files, "[ac].py")
print(file)

