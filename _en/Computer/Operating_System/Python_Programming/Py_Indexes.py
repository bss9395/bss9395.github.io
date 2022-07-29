"""
Py_Indexes.py
Author: BSS9395
Update: 2022-07-29T23:55:00+08@China-Shanghai+08
Design: Python Language Feature: Index
"""

# +00 +01 +02 +03 +04 +05 +06 +07 +08 +09 +10 +11 +12 +13
#   H   e   l   l   o   ,       W   o   r   l   d   !
# -14 -13 -12 -11 -10 -09 -08 -07 -06 -05 -04 -03 -02 -01   # python
# -13 -12 -11 -10 -09 -08 -07 -06 -05 -04 -03 -02 -01 -00   # Do

string = 'Hello, World!'
print('%d' % len(string))         # note: 13
print("%r" % string[+5])          # note: ','
print("%r" % string[-5])          # note: 'o'
print("%r" % string[+5:])         # note: ', World!'
print('%r' % string[:-5])         # note: 'Hello, W'
print("%r" % string[+5: -5])      # note: ', W'
print("%r" % string[+5: -5: +1])  # note: ', W'
print("%r" % string[-5: +5: -1])  # note: 'oW '

print("He" in string)             # note: True
print("or" in string)             # note: False
print("%r" % min(string))         # note: ' '
print("%r" % max(string))         # note: 'r'
