''' Py_itertools_product.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Standard Library: itertools.product
'''


import itertools

for elem in itertools.product('AB', 'CD'):
    print(''.join(elem), end=', ')
print()

for elem in itertools.product('AB', repeat=3):
    print(''.join(elem), end=', ')
