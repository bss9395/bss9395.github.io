''' Py_tempfile.py
Author: BSS9395
Update: 2022-10-23T17:30:00+08@China-Shanghai+08
Design: Python Standard Library: tempfile
'''


import os
import tempfile

with tempfile.TemporaryFile() as file:
    print(file.name)
    file.write("长江后浪推前浪，前浪拍在沙滩上".encode("utf-8"))
    file.seek(0, os.SEEK_SET)
    print(file.read().decode("utf-8"))

with tempfile.TemporaryDirectory() as dire:
    print(dire)