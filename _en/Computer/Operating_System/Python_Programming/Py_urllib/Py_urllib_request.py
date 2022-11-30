''' Py_urllib_request.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Standard Library: urllib.request
'''

import urllib.request
import urllib.parse

with urllib.request.urlopen("https://cn.bing.com/?mkt=zh-CN") as file:
    _data = file.read(512)
    print(_data.decode("utf-8"))

################################################################################

print("-" * 40)
_url = f'http://localhost:8080/test/get.jsp?{urllib.parse.urlencode({"name": "bss9395", "password": "12345"})}'
print(_url)
with urllib.request.urlopen(url=_url) as file:
    print(file.read().decode("utf-8"))

with urllib.request.urlopen(url="http://localhost:8080/test/test", data="given data".encode("utf-8")) as file:
    print(file.read().decode("utf-8"))

################################################################################

print("-" * 40)
_params = "PUT data".encode("utf-8")
_request = urllib.request.Request(url="http://localhost:8080/test/put", data=_params, method="PUT")
with urllib.request.urlopen(_request) as file:
    print(file.status)
    print(file.read().decode("utf-8"))

_request = urllib.request.Request("http://localhost:8080/test/header.jsp")
_request.add_header("Referer", "http://www.crazyit.org/")
with urllib.request.urlopen(_request) as file:
    print(file.status)
    print(file.read().decode("utf-8"))
