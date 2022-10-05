""" Py_sys.py
Author: bss9395
Update: 2022-10-T14:17:00+08@China-Guangdong-Zhanjiang+08
Design: Python Standard Library: sys
"""

import sys

try:
    lhs = int(sys.argv[1])
    rhs = int(sys.argv[2])
    res = lhs / rhs
    print("%d / %d = %d" % (lhs, rhs, res))
except (IndexError, ValueError, ArithmeticError):
    print("except (IndexError, ValueError, ArithmeticError):")
except Exception:
    print("except Exception:")
except:
    print("except:")