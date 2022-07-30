"""
Py_bytes.py
Author: BSS9395
Update: 2022-07-29T23:55:00+08@China-Shanghai+08
Design: Python Built-in Class: bytes
"""

b1 = bytes()
b2 = b''
b3 = b'Hello, World!'
b4 = bytes('你好，世界！', encoding='utf-8')
b5 = '你好，世界！'.encode('utf-8')
print(b1)
print(b2)
print(b3)
print(b4)
print(b5)

################################################################################

b6 = b5.decode('utf-8')
print(b6)
