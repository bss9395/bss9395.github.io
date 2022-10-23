''' Py_Condition.py
Author: BSS9395
Update: 2022-10-23T17:30:00+08@China-Shanghai+08
Design: Python Standard Library: Queue
'''

import multiprocessing
import os

def _Action(quque):
    print("new process %s" % (os.getpid(),))
    quque.put("Python")

if __name__ == "__main__":
    queue = multiprocessing.Queue()
    process = multiprocessing.Process(target=_Action, args=(queue, ))
    process.start()
    print(queue.get())
