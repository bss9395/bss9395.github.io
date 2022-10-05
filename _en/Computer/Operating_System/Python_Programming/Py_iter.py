""" Py_iter.py
Author: bss9395
Update: 2022-10-T14:17:00+08@China-Guangdong-Zhanjiang+08
Design: Python Language Feature: __iter__
"""

class Fibonacci:
    def __init__(self, leng):
        self.first = 0
        self.second = 1
        self.leng = leng
    def __next__(self):
        if self.leng == 0:
            raise StopIteration
        self.first, self.second = self.second, self.first + self.second
        self.leng -= 1
        return self.first
    def __iter__(self):
        return self

fibonacci = iter(Fibonacci(10))
print(next(fibonacci))

################################################################################

iteration = iter(["1156", "bss9395", 28])
print(next(iteration))
for item in iteration:
    print(item)
