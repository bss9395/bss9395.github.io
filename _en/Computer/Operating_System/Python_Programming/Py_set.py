''' Py_set.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Standard Library: set
'''

names = {'bss9395', 'maker'}
names.add("emperor")
print(f'len(names) = {len(names)}')
names.remove("emperor")
print('emperor' in names)
