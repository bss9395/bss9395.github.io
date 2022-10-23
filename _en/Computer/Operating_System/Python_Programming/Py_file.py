''' Py_File.py
Author: BSS9395
Update: 2022-10-23T17:30:00+08@China-Shanghai+08
Design: Python Standard Library: File
'''

import os

f = open("Py_File.py", "rb")
print(f.tell())
f.seek(3)
print(f.tell())
print(f.read(3))
f.seek(3, 1)
print(f.tell())
f.seek(-2, 2)
print(f.tell())
print(f.read(2))
f.close()

################################################################################

f = open("temp.txt", "w+")
text = "长江后浪推前浪，" + os.linesep +"前浪拍在沙滩上。"
f.write(text)
f.close()

################################################################################

f = open("temp.bin", "wb+")
text = "长江后浪推前浪，" + os.linesep +"前浪拍在沙滩上。"
f.write(text.encode("utf-8"))
f.close()


