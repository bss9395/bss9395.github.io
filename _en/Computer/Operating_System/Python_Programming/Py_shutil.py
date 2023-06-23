""" Py_shutil.py
Author: BSS9395
Update: 2023-06-17T23:11:00+08@China-Beijing+08
Design: Python Standard Library: shutil
"""

import os
import shutil


class Py_shutil:
    @staticmethod
    def _Path_Move(directory_into="E:/Desktop/into/", directory_from="E:/Desktop/from/"):
        filenames = os.listdir(directory_from)
        for filename in filenames:
            path_from = os.path.join(directory_from, filename)
            if os.path.isdir(path_from):
                path_into = os.path.join(directory_into, filename)
                Py_shutil._Path_Move(path_into, path_from)
                try:
                    os.rmdir(path_from)
                except Exception as exception:
                    pass  # note: If the directory does not exist or is not empty
            elif os.path.isfile(path_from):
                filesize = os.path.getsize(path_from)
                if 10 * 1024 < filesize:
                    try:
                        print(path_from, directory_into)
                        os.makedirs(directory_into, exist_ok=True)
                        shutil.move(path_from, os.path.join(directory_into, filename))
                    except Exception as exception:
                        raise  # note:


if __name__ == "__main__":
    Py_shutil._Path_Move()
