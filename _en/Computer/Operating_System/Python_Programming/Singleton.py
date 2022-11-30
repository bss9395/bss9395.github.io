''' Singleton.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Language Feature: Singleton
'''

import sys
import threading


class Singleton(object):
    _rlock = threading.RLock()
    _instance = {}

    @staticmethod
    def _Singleton(cls):
        def _Wrapper(*args, **keywords):
            with Singleton._rlock:
                if cls not in Singleton._instance:
                    Singleton._instance[cls] = cls(*args, **keywords)
            return Singleton._instance[cls]
        return _Wrapper


@Singleton._Singleton
class Protocol(object):
    class Const_Value_Error(PermissionError):
        pass

    def __setattr__(self, key, value):
        if key in self.__dict__:
            raise self.Const_Value_Error("can't revise const variable {0}".format(key))
        self.__dict__[key] = value


################################################################################

_protocol = Protocol()
_protocol._server_ip = "0.0.0.0"
_protocol._server_port = 50000

sys.modules[__name__] = _protocol
