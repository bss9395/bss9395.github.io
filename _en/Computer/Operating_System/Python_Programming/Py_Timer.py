''' Py_Timer.py
Author: BSS9395
Update: 2022-10-23T17:30:00+08@China-Shanghai+08
Design: Python Standard Library: Timer
'''

from threading import Timer
import time

# 定义总共输出几次的计数器
count = 0


def _Action():
    print("%s" % time.ctime())
    global count
    count += 1
    if count < 10:
        Timer(1, _Action).start()


Timer(1, _Action).start()
