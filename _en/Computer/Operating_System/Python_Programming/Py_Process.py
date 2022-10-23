''' Py_Process.py
Author: BSS9395
Update: 2022-10-23T17:30:00+08@China-Shanghai+08
Design: Python Standard Library: Process
'''

import multiprocessing
import os


# def _Action(numb):
#     for i in range(numb):
#         print("parent process %s, child process %s, %s" % (os.getppid(), os.getpid(), i))
#
# if __name__ == "__main__":
#     for i in range(100):
#         print("main process %s, %s" % (os.getpid(), i))
#         if i == 20:
#             process1 = multiprocessing.Process(target=_Action, args=(100,))
#             process2 = multiprocessing.Process(target=_Action, args=(100,))
#             process1.start()
#             process2.start()
#             process1.join()

################################################################################

class Action(multiprocessing.Process):
    def __init__(self, numb):
        super().__init__()
        self._numb = numb

    def run(self):
        for i in range(self._numb):
            print("parent process %s, child process %s, %s" % (os.getppid(), os.getpid(), i))


if __name__ == "__main__":
    for i in range(100):
        print("main process %s, %s" % (os.getpid(), i))
        if i == 20:
            process1 = Action(100)
            process2 = Action(100)
            process1.start()
            process2.start()
            process1.join()
