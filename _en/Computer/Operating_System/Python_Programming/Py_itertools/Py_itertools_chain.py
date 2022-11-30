''' Py_itertools_chain.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Standard Library: itertools.chain
'''

import itertools

languages1 = ['C', 'C++', 'C#']
languages2 = ['Java', 'Python']
for language in itertools.chain(languages1, languages2):
    print(language, end=', ')
print()

for language in languages1 + languages2:
    print(language, end=', ')
print()
