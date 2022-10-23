''' Py_threading.py
Author: BSS9395
Update: 2022-10-23T17:30:00+08@China-Shanghai+08
Design: Python Standard Library: threading
'''

import threading
import time

# def Action(numb):
#     for i in range(numb):
#         print(threading.current_thread().getName() + ": " + str(i))
#
#
# if __name__ == "__main__":
#     for i in range(100):
#         print(threading.current_thread().getName() + ": " + str(i))
#         if i == 20:
#             t1 = threading.Thread(target=Action, args=(100,))
#             t2 = threading.Thread(target=Action, args=(100,))
#             t1.start()
#             t2.start()
#
#
# ################################################################################
#
# class Action(threading.Thread):
#     def __init__(self, args):
#         threading.Thread.__init__(self)
#         self.args = args
#
#     def run(self):
#         for i in range(self.args):
#             print(threading.current_thread().getName() + ": " + str(i))
#
#
# if __name__ == "__main__":
#     for i in range(100):
#         print(threading.current_thread().getName() + ": " + str(i))
#         if i == 20:
#             t1 = Action(100)
#             t2 = Action(100)
#             t1.start()
#             t2.start()
#             print("%s is_alive: %s" %(threading.current_thread().getName(), threading.current_thread().is_alive()))
#
# ################################################################################
#
# def Action(arg):
#     for i in range(arg):
#         print("%s:%s" % (threading.current_thread().name, i))
#
# if __name__ == "__main":
#     th = threading.Thread(target=Action, args=(100,))
#     th.daemon = True
#     th.start()
#     for i in range(10):
#         print("%s: %s" % (threading.current_thread().name, i))
#
# ###############################################################################

class Account:
    def __init__(self, name, balance):
        self.name = name
        self.balance = balance
        self.lock = threading.RLock()

    def Draw(self, amount):
        try:
            self.lock.acquire()
            if self.balance >= amount:
                time.sleep(0.01)
                self.balance -= amount
                print("%s: %d remained" % (threading.current_thread().name, self.balance))
            else:
                print("%s: failed" % (threading.current_thread().name))
        finally:
            pass
            self.lock.release()


account = Account("bss9395", 100)
threading.Thread(target=account.Draw, args=(80,)).start()
threading.Thread(target=account.Draw, args=(80,)).start()
