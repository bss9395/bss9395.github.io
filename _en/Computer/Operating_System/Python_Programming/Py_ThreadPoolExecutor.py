''' Py_ThreadPoolExecutor.py
Author: BSS9395
Update: 2022-10-23T17:30:00+08@China-Shanghai+08
Design: Python Standard Library: ThreadPoolExecutor
'''

from concurrent.futures import ThreadPoolExecutor
import threading
import time


def _Action(numb):
    sum = 0
    for i in range(numb):
        sum += i
        print("%s: %s" % (threading.current_thread().name, i))
    return sum


# with ThreadPoolExecutor(max_workers=3) as pool:
#     def _Get_Result(future):
#         print(future.result())
#
#
#     future1 = pool.submit(_Action, 100)
#     future2 = pool.submit(_Action, 50)
#     future3 = pool.submit(_Action, 150)
#     time.sleep(3)
#     print(future2.done())
#     print(future1.result())
#     future2.add_done_callback(_Get_Result)
#     future3.add_done_callback(_Get_Result)

with ThreadPoolExecutor(max_workers=3) as pool:
    results = pool.map(_Action, (100, 50, 150))
    for result in results:
        print(result)
