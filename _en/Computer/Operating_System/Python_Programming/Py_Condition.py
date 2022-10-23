''' Py_Condition.py
Author: BSS9395
Update: 2022-10-23T17:30:00+08@China-Shanghai+08
Design: Python Standard Library: Condition
'''

import threading


class Account():
    def __init__(self, account, balance):
        self._account = account
        self._balance = balance
        self._condition = threading.Condition()

    def _Get_Balance(self):
        return self._balance

    def _Draw(self, amount):
        try:
            self._condition.acquire()
            if self._balance < amount:
                self._condition.wait()
            else:
                self._balance -= amount
                print("_Draw: %s remained" % (self._balance,))
            self._condition.notify_all()
        finally:
            self._condition.release()

    def _Deposit(self, amount):
        try:
            self._condition.acquire()
            if 0 < self._balance:
                self._condition.wait()
            else:
                self._balance += amount
                print("_Deposit: %s remained" % (self._balance))
                self._condition.notify_all()
        finally:
            self._condition.release()


account = Account("1234", 0)


def _Draw():
    for i in range(100):
        account._Draw(800)


def _Deposit():
    for i in range(100):
        account._Deposit(800)


threading.Thread(target=_Draw).start()
threading.Thread(target=_Deposit).start()
threading.Thread(target=_Deposit).start()
threading.Thread(target=_Deposit).start()
