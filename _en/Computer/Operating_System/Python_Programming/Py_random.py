""" Py_random.py
Author: bss9395
Update: 2022-10-05T22:27:00+08@China-Guangdong-Zhanjiang+08
Design: Python Standard Library: random
"""

import random

languages = ["C", "C++", "C#", "Java", "Python"]
probability = [5, 4, 1, 3, 2]

print(random.random())
print(random.uniform(2.5, 10.0))
print(random.expovariate(1 / 5))
print(random.randrange(10))
print(random.choice(languages))
print(random.choices(languages, probability, k=3))
random.shuffle(languages)
print(languages)
print(random.sample(languages, k=3))                # note: unique elements
