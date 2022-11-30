''' Py_heapq.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Desing: Python Standard Library: heapq
'''

import heapq

data = list(range(10))
data.append(0.5)
print(data)
heapq.heapify(data)
print(data)
heapq.heappush(data, 3.2)
print(data)
print(heapq.heappop(data))
