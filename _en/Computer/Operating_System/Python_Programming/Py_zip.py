"""
Py_zip.py
Author: BSS9395
Update: 2022-07-30T23:21:00+08@China-Shanghai+08
Design: Python Built-in Function: zip()
"""

degrees = ["幼儿园", "小学", "初中", "高中", "大学", "硕士", "博士", "讲师", "教授", "研究员"]
scores = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]
for degree, score in zip(degrees, scores):
    print("%s: %d" % (degree, score))
