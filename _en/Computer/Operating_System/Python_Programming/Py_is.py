"""
Py_is.py
Author: BSS9395
Update: 2022-07-29T23:55:00+08@China-Shanghai+08
Design: Python Keyword: is
"""

timestamp_1 = "2022-07-30T11:13:00%+03d" % 8
timestamp_2 = "2022-07-30T11:13:00" + "+08"
print(timestamp_1)
print(timestamp_2)
print(id(timestamp_1))
print(id(timestamp_2))
print(timestamp_1 == timestamp_2)
print(timestamp_1 is timestamp_2)
