"""
Diamond.py
Author: BSS9395
Update: 2022-07-31T17:07:00+08@China-Shanghai+08
Design: Diamond Pattern
"""

def Diamond(char, rows):
    assert(rows % 2 == 1)
    for row in range(rows):
        level = row if (row <= (rows // 2)) else (rows - 1 - row)
        index = rows // 2 - level
        cols = 2 * level + 1
        print("-" * index + str(char) * cols)


Diamond("*", 5)
