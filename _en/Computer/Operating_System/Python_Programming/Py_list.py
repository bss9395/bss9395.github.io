"""
Py_list.py
Author: BSS9395
Update: 2022-07-30T18:02:+08@China-Shanghai+08
Design: Python Built-in Class: list
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

################################################################################

x, y, z = 10, 20, 30
print(x, y, z)
x, y, z = y, z, x
print(x, y, z)

beg, mid, *end = range(10)
print(beg, mid, end)
beg, *mid, end = range(10)
print(beg, mid, end)
*beg, mid, end = range(10)
print(beg, mid, end)

################################################################################

languages = ["C", "C++", "Java", "Python", "C#"]
languages.sort(key=len)
print(languages)
languages.reverse()
print(languages)

################################################################################

items = [12, 45, 3.4, 12, "BSS9395", 45, 3.4, "BSS9395", 45, 3.4]
stat = {}
for item in items:
    if item in stat:
        stat[item] += 1
    else:
        stat[item] = 1
for item, count in stat.items():
    print("%s: %d" % (item, count))
