''' Py_Event.py
Author: BSS9395
Update: 2022-10-23T17:30:00+08@China-Shanghai+08
Design: Python Standard Library: Event
'''

import threading
import time


class Model():
    def __init__(self):
        self._event = threading.Event()

    def _Func(self):
        print("%s: before" % (threading.current_thread().name,))
        self._event.wait()
        print("%s: after" % (threading.current_thread().name,))


model = Model()
threading.Thread(target=model._Func).start()
threading.Thread(target=model._Func).start()
print("-" * 40)
model._event.set()

################################################################################
