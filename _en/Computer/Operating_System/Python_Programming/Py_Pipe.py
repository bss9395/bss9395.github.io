''' Py_Pipe.py
Author: BSS9395
Update: 2022-10-23T17:30:00+08@China-Shanghai+08
Design: Python Standard Library: Pipe
'''

import multiprocessing
import os

def _Action(pipe):
    print("%s" % multiprocessing.current_process().pid)
    pipe.send("Python")

if __name__ == "__main__":
    parent, child = multiprocessing.Pipe()
    process = multiprocessing.Process(target=_Action, args=(child,))
    process.start()
    print(parent.recv())
