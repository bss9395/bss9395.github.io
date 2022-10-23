''' Py_TestSuite.py
Author: BSS9395
Update: 2022-10-23T17:30:00+08@China-Shanghai+08
Design: Python Standard Library: unittest
'''

from Py_unittest import *
import unittest

_cases = (Test,)
def _Suite():
    loader = unittest.TestLoader()
    suite = unittest.TestSuite()
    for case in _cases:
        suite.addTests(loader.loadTestsFromTestCase(case))
    return suite

if __name__ == "__main__":
    # runner = unittest.TextTestRunner(verbosity=2)
    # runner.run(_Suite())

    with open("report.txt", "a") as file:
        runner = unittest.TextTestRunner(verbosity=2, stream=file)
        runner.run(_Suite())
