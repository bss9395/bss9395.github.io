"""
Py_pass.py
Author: BSS9395
Update: 2022-07-30T23:21:00+08@China-Shanghai+08
Design: Python Keyword: pass
"""

score = 70
if 0 <= score < 60:
    print("if 0 <= score < 60:")
elif score < 70:
    print("elif score < 70:")
elif score < 80:
    pass
elif score < 90:
    print("elif score < 90:")
elif score <= 100:
    print("elif score <= 100:")
