""" Py_pathlib_Path.py
Author: bss9395
Update: 2022-10-07T08:57:00+08@China-Guangdong-Zhanjiang+08
Design: Python Standard Library: pathlib.Path()
"""

import pathlib

p = pathlib.Path()
for item in p.iterdir():
    print(item)
for item in p.glob("*.py"):
    print(item)

################################################################################

p = pathlib.Path("temp.txt")
text = "长江后浪推前浪，前浪拍在沙滩上。"
print(p.write_text(text, encoding="utf-8"))
content = p.read_text(encoding="utf-8")
print(content)
