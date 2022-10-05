""" Py_open.py
Author: bss9395
Update: 2022-10-T14:17:00+08@China-Guangdong-Zhanjiang+08
Design: Python Keyword: open
"""

def test():
    file = None
    try:
        file = open("temp.text")
    except OSError as ex:
        print(ex)
    finally:
        if file is not None:
            try:
                file.close()
            except OSError as ex:
                print(ex)
        print("finally:")

test()
