''' Py_Condition.py
Author: BSS9395
Update: 2022-10-23T17:30:00+08@China-Shanghai+08
Design: Python Standard Library: Queue
'''

import threading
import queue
import time


class Model():
    def __init__(self):
        self._languages = ("C", "C++", "C#", "Java", "Python")
        self._queque = queue.Queue(1)
    def _Produce(self):
        for i in range(99999):
            time.sleep(0.1)
            language = self._languages[i % len(self._languages)]
            self._queque.put(language)
            print("%s: produce %s" % (threading.current_thread().name, language))
    def _Consume(self):
        while True:
            time.sleep(0.1)
            language = self._queque.get()
            print("%s: consume %s" % (threading.current_thread().name, language))

model = Model()
threading.Thread(target=model._Produce).start()
threading.Thread(target=model._Produce).start()
threading.Thread(target=model._Produce).start()
threading.Thread(target=model._Consume).start()