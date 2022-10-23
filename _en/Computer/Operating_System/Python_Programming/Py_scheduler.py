''' Py_scheduler.py
Author: BSS9395
Update: 2022-10-23T17:30:00+08@China-Shanghai+08
Design: Python Standard Library: scheduler
'''

import sched
import time
import threading

def _Action(name="default"):
    print("%s: %s" % (time.ctime(), name))

scheduler = sched.scheduler()
scheduler.enter(5, 1, _Action)
scheduler.enter(5, 2, _Action, argument=("positional",))
scheduler.enter(5, 1, _Action, kwargs={"name": "keyword"})
scheduler.run()
