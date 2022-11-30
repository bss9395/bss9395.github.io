''' Py_collections_deque.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: python Standard Library: deque
'''


import collections as collections

stack = collections.deque()
stack.append("C")
stack.append("C++")
stack.append("C#")
print(stack)
stack.pop()
print(stack)

################################################################################

queue = collections.deque()
queue.append("C")
queue.append("C++")
queue.append("C#")
print(queue)
queue.popleft()
print(queue)

################################################################################

deq = collections.deque()
deq.append("C")
deq.append("C++")
deq.append("C#")
print(deq)
deq.popleft()
deq.pop()
print(deq)

################################################################################

deq = collections.deque(range(5))
print(deq)
deq.rotate()
print(deq)
deq.rotate()
print(deq)
