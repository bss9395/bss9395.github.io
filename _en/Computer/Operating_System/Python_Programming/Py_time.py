""" Py_time.py
Author: bss9395
Update: 2022-10-05T22:27:00+08@China-Guangdong-Zhanjiang+08
Design: Python Standard Library: time
"""

import time

print(time.time())
print(time.timezone)
print(time.tzname)

################################################################################

print(time.asctime())
print(time.ctime())
print(time.gmtime())
print(time.localtime())
print(time.mktime(time.localtime()))
print(time.strftime("%Y-%m-%dT%H:%M:%S"))
print(time.strptime("2022-10-05T22:10:00", "%Y-%m-%dT%H:%M:%S"))

################################################################################

print(time.perf_counter())
print(time.process_time())
