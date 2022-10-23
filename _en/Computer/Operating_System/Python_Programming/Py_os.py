""" Py_os.py
Author: bss9395
Update: 2022-10-05T22:27:00+08@China-Guangdong-Zhanjiang+08
Design: Python Standard Library: os
"""

import os
import stat

# print(sorted(os.__all__))
#
# ################################################################################
#
# print(os.cpu_count())
# print(os.name)
# print(os.getenv("PYTHONPATH"))
# print(os.getlogin())
# print(os.getpid())
# print(os.getppid())
# print([ch for ch in os.linesep])
# print(os.sep)
# print(os.pathsep)
# print(os.urandom(4))
#
# ################################################################################
#
# # os.system("cmd")
# os.system("dir")
# os.startfile("Main.txt")
# os.spawnl(os.P_NOWAIT, "D:/npp.8.3.3.portable.x64/notepad++.exe", " ")
# # os.execl("D:/Python/Python38/python.exe", " ", 'Main.txt', 'i')
#
# ################################################################################
#
# print(os.getcwd())
# os.chdir("../")
# print(os.getcwd())
#
# ################################################################################
#
# path = "abc/xyz"
# os.makedirs(path)
# change = "xyz/abc"
# os.renames(path, change)
# os.removedirs(change)
#
# ################################################################################
#
# ret = os.access(".", os.F_OK | os.R_OK | os.W_OK | os.X_OK)
# print('os.access(".", os.F_OK | os.R_OK | os.W_OK | os.X_OK) =', ret)
# ret = os.access("Py_os.py", os.F_OK | os.R_OK | os.W_OK)
# print('os.access("Py_os.py", os.F_OK | os.R_OK | os.W_OK) =', ret)
#
# ################################################################################
#
# os.chmod("Py_os.py", stat.S_IREAD)
# ret = os.access("Py_os.py", os.W_OK)
# print('os.access("Py_os.py", os.W_OK) =', ret)
#
# ################################################################################
#
# fd = os.open("temp.txt", os.O_RDWR | os.O_CREAT)
# text = "长江后浪推前浪，前浪拍在沙滩。"
# leng = os.write(fd, text.encode("utf-8"))
# os.lseek(fd, 0, os.SEEK_SET)
# data = os.read(fd, leng)
# print(data.decode("utf-8"))
# os.close(fd)

################################################################################

os.symlink("Py_os.py", "link.py") # note: require system adminstrator privilege.
os.link("Py_os.py", "link.py")    # note: hard link in Linux, but copy file in Windows.
