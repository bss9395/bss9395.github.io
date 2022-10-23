""" Py_pathlib_PurePath.py
Author: bss9395
Update: 2022-10-07T08:57:00+08@China-Guangdong-Zhanjiang+08
Design: Python Standard Library: pathlib.PurePath()
"""

import pathlib

pp = pathlib.PurePath("root", "folder/sub", "temp")
print(pp)
pp = pathlib.PureWindowsPath("root", "folder/sub", "temp")
print(pp)
pp = pathlib.PurePosixPath("root", "folder/sub", "temp")
print(pp)

################################################################################

pp = pathlib.PurePath()
print(pp)
pp = pathlib.PurePath("root/./folder")
print(pp)
pp = pathlib.PurePath("root/../folder")
print(pp)

################################################################################

print(pathlib.PureWindowsPath("BSS9395") == pathlib.PureWindowsPath("bss9395"))
print(pathlib.PurePosixPath("C:/") < pathlib.PurePosixPath("D:/"))

################################################################################

pp = pathlib.PurePath("root") / "folder" / "sub" / "temp"
print(pp)

###############################################################################

pp = pathlib.PureWindowsPath("C:/Program Files/folder/temp.txt.zip")
print(pp.parts)
print(pp.anchor)
print(pp.parent)
print(pp.name)
print(pp.suffix)
print(pp.stem)    # note: temp.txt
print(pp.as_posix())
print(pp.as_uri())
print(pp.match("*/temp*.zip"))
print(pp.relative_to("C:/Program Files"))
print(pp.with_name("new"))
print(pp.with_suffix(".tar"))
