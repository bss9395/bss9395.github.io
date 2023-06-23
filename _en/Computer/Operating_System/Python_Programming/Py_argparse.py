""" Py_argparse.py
Author: BSS9395
Update: 2023-06-17T21:55:00+08@China-Beijing+08
Design: Python Standard Library: argparse
"""

import argparse
import datetime


class Py_argparse:
    @staticmethod
    def _Py_argparse():
        parser = argparse.ArgumentParser()
        parser.add_argument("-a", "--dateA", dest="dateA", type=str, default="2023-06-01")
        parser.add_argument("-b", "--dateB", dest="dateB", type=str, default="2023-06-19")
        args = parser.parse_args()
        print("dateA = %s" % args.dateA)
        print("dateB = %s" % args.dateB)

        incr = datetime.timedelta(days=1)
        dateA = datetime.datetime.strptime(args.dateA, "%Y-%m-%d")
        dateB = datetime.datetime.strptime(args.dateB, "%Y-%m-%d")
        while dateA <= dateB:
            print("%s" % (dateA.strftime("%Y-%m-%dT%H:%M:%S", )))
            dateA += incr


if __name__ == "__main__":
    Py_argparse._Py_argparse()
