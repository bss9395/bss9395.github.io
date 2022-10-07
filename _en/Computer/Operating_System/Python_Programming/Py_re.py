""" Py_re.py
Author: bss9395
Update: 2022-10-07T08:57:00+08@China-Guangdong-Zhanjiang+08
Design: Python Standard Library: re
"""

# usage: echo "bss9395@yeah.net" | python pipein_test.py

import sys
import re

pattern = r"[A-Za-z0-9]*@[A-Za-z0-9]*\.[A-Za-z0-9]*"
text = sys.stdin.read()
iter = re.finditer(pattern, text, re.I)
for item in iter:
    print("%s --> %s" % (item.span(), item.group()))
