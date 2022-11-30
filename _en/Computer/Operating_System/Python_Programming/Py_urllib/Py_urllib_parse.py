''' Py_urllib_parse.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Standard Library: urllib.parse
'''

import urllib.parse

_result = urllib.parse.urlparse("http://www.crazyit.org:80/index.php;yeeku?name=fkit#frag")
print(_result)
print("scheme: ", _result.scheme)
print("netloc: ", _result.netloc)
print("hostname: ", _result.hostname)
print("port: ", _result.port)
print("path: ", _result.path)
print("params: ", _result.params)
print("query: ", _result.query)
print("fragment: ", _result.fragment)
print(_result.geturl())

################################################################################

print("-" * 40)
_result = urllib.parse.urlunparse(("http", "www.crazyit.org:80", "index.php", "yeeku", "name=fkit", "frag"))
print(_result)

################################################################################

print("-" * 40)
_result = urllib.parse.parse_qs('name=fkit&name=%E7%96%AF%E7%8B%82java&age=18')
print(_result)
_result = urllib.parse.parse_qsl('name=fkit&name=%E7%96%AF%E7%8B%82java&age=18')
print(_result)
_result = urllib.parse.urlencode(_result)
print(_result)

################################################################################



