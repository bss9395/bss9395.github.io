""" Py_fileinput.py
Author: bss9395
Update: 2022-10-07T08:57:00+08@China-Guangdong-Zhanjiang+08
Design: Python Standard Library: fileinput
"""

import fileinput

try:
    for line in fileinput.input(["Py_fileinput.py", "Py_codecs.py"]):
        print("[%s: %d] %s" % (fileinput.filename(), fileinput.filelineno(), line), end="")
finally:
    fileinput.close()
