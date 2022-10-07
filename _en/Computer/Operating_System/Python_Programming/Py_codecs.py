""" Py_codecs.py
Author: bss9395
Update: 2022-10-07T08:57:00+08@China-Guangdong-Zhanjiang+08
Design: Python Standard Library: codecs
"""

import codecs

file = None
try:
    file = codecs.open("Py_codecs.py", "r", encoding="utf-8")
    print(file.read())
finally:
    file.close()
