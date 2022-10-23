''' Py_Condition.py
Author: BSS9395
Update: 2022-10-23T17:30:00+08@China-Shanghai+08
Design: DeadLock
'''

import threading
import time


class A:
    def __init__(self):
        self._lock = threading.RLock()

    def _Func(self, b):
        try:
            self._lock.acquire()
            print("%s: enter in _Func of A" % threading.current_thread().name)
            time.sleep(0.1)
            b._Last()
        finally:
            self._lock.release()

    def _Last(self):
        try:
            self._lock.acquire()
            print("%s: enter in _Last of A" % threading.current_thread().name)
        finally:
            self._lock.release()


class B():
    def __init__(self):
        self._lock = threading.RLock()

    def _Func(self, a):
        try:
            self._lock.acquire()
            print("%s: enter in _Func of B" % threading.current_thread().name)
            time.sleep(0.1)
            a._Last()
        finally:
            self._lock.release()

    def _Last(self):
        try:
            self._lock.acquire()
            print("%s: enter _Last in B" % threading.current_thread().name)
        finally:
            self._lock.release()


a = A()
b = B()

threading.Thread(target=a._Func, args=(b,)).start()
threading.Thread(target=b._Func, args=(a,)).start()
