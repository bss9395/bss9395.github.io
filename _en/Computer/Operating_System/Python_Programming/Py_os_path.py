""" Py_os_path.py
Author: bss9395
Update: 2022-10-07T08:57:00+08@China-Guangdong-Zhanjiang+08
Design: Python Standard Library: os.path()
"""

import os

print(os.path.exists("temp.txt"))
print(os.path.abspath("temp.txt"))
print(os.path.dirname("/folder/temp.txt"))
print(os.path.getatime("Py_os_path.py"))
print(os.path.getmtime("Py_os_path.py"))
print(os.path.getctime("Py_os_path.py"))
print(os.path.getsize("Py_os_path.py"))
print(os.path.isfile("Py_os_path.py"))
print(os.path.isdir("Py_os_path.py"))

################################################################################

print(os.path.commonprefix(["/usr/lib", "/usr/local/lib"]))
print(os.path.commonpath(["/usr/lib", "/usr/local/lib"]))
