""" Py_with.py
Author: bss9395
Update: 2022-10-07T08:57:00+08@China-Guangdong-Zhanjiang+08
Design: Python Keyword: with
"""


# with open("Py_with.py", "rt", encoding="utf-8") as file:
#     for line in file:
#         print(line, end="")

################################################################################

class Resource():
    def __init__(self, tag):
        print("def __init__(self, tag):")
        self.tag = tag

    def __enter__(self):
        print("def __enter__(self):")
        return "bss9395"

    def __exit__(self, exc_type, exc_val, exc_tb):
        print("def __exit__(self, exc_type, exc_val, exc_tb):")
        if exc_tb is None:
            print("close resource without exception")
        else:
            print("close resource with exception")
            return False

with Resource("tag") as resource:
    print(resource)
    print("before raise Exception")
    # raise Exception
    print("after raise Exception")
