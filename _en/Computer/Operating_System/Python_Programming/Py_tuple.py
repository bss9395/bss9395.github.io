"""
Py_tuple.py
Author: BSS9395
Update: 2022-07-30T18:02:+08@China-Shanghai+08
Design: Python Built-in Class: tuple
"""

items_list = [2, 3.4, "5678"]
items_list[2] = "8765"
print(items_list)
print(items_list + items_list)

items_tuple = (2, 3.4, "5678")
# items_tuple[2] = "8765"
print(items_tuple)
print(items_tuple + items_tuple)

# print(items_list + items_tuple)  # note: list could not directly addup tuple.

################################################################################

endings = ("st", "nd", "rd") + ("th", ) * 17 + ("st", "nd", "rd") + ("th", ) * 7 + ("st", )
print(endings)
day = 27
print(str(day) + endings[day - 1])
