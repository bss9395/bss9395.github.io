""" Py_open.py
Author: bss9395
Update: 2022-10-T14:17:00+08@China-Guangdong-Zhanjiang+08
Design: Python Keyword: open
"""

# def test():
#     file = None
#     try:
#         file = open("Py_open.py", "r", encoding="utf-8")
#         print(file.encoding)
#         print(file.mode)
#         print(file.name)
#         print(file.closed)
#
#         print(file.read())
#     except OSError as ex:
#         print(ex)
#     finally:
#         if file is not None:
#             try:
#                 file.close()
#             except OSError as ex:
#                 print(ex)
#         print("finally:")
#
# test()

################################################################################

# file = None
# try:
#     file = open("Py_open.py", "rb")
#     print(file.read().decode("utf-8"))
# finally:
#     file.close()

################################################################################

# file = None
# try:
#     file = open("Py_open.py", "rt")
#     while True:
#         line = file.readline()
#         if not line:
#             break
#         print(line)
# finally:
#     file.close()

################################################################################

file = None
try:
    file = open("Py_open.py", "rt", encoding="utf-8")
    for line in file:
        print(line, end="")
finally:
    file.close()