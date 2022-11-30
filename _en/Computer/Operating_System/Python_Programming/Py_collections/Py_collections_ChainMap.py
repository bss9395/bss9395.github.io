''' Py_collections_ChainMap.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Standard Library: ChainMap
'''

import collections as collections

dict1 = {"C": 90, "C++": 80}
dict2 = {"C#": 30, "C++": 70}
dict3 = {"Java": 90, "C#": 10}

chain = collections.ChainMap(dict1, dict2, dict3)
print(chain)
print(chain["C++"])
print(chain["C#"])

################################################################################

import builtins

_name = "bss9395"
def _Func():
    _name = "maker"
    lookup = collections.ChainMap(locals(), globals(), vars(builtins))
    print(lookup["_name"])
    print(lookup["len"])

_Func()

################################################################################

import argparse
import os

parser = argparse.ArgumentParser()
parser.add_argument("-u", "--user")
parser.add_argument("-c", "--color")
command = {k: v for (k, v) in vars(parser.parse_args()).items() if v}
default = {"color": "blue", "user": "bss9395"}

combined = collections.ChainMap(command, os.environ, default)
print(combined["user"])
print(combined["color"])
