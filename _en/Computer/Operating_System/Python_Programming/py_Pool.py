''' Py_Pool.py
Author: BSS9395
Update: 2022-10-23T17:30:00+08@China-Shanghai+08
Design: Python Standard Library: Pool
'''

import multiprocessing
import os

def _Action(name="default"):
    print("%s: %s" % (os.getpid(), name))

if __name__ == "__main__":
    pool = multiprocessing.Pool(processes=3)
    pool.apply_async(_Action)
    pool.apply_async(_Action, args=("positional"))
    pool.apply_async(_Action, kwds={"name", "keyword"})
    pool.close()