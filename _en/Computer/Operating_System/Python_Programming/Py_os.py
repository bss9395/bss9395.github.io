""" Py_os.py
Author: bss9395
Update: 2022-10-05T22:27:00+08@China-Guangdong-Zhanjiang+08
Design: Python Standard Library: os
"""

import os

print(sorted(os.__all__))

################################################################################

print(os.cpu_count())
print(os.name)
print(os.getenv("PYTHONPATH"))
print(os.getlogin())
print(os.getpid())
print(os.getppid())
print([ch for ch in os.linesep])
print(os.sep)
print(os.pathsep)
print(os.urandom(4))

################################################################################

# os.system("cmd")
os.system("dir")
os.startfile("Main.txt")
os.spawnl(os.P_NOWAIT, "D:/npp.8.3.3.portable.x64/notepad++.exe", " ")
# os.execl("D:/Python/Python38/python.exe", " ", 'Main.txt', 'i')
