''' Py_http_cookiejar.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python standard Library: cookiejar
'''

import urllib.parse
import urllib.request
import http.cookiejar

_cookie_jar = http.cookiejar.MozillaCookieJar("cookie.txt")
_cookie_processor = urllib.request.HTTPCookieProcessor(_cookie_jar)
_opener = urllib.request.build_opener(_cookie_processor)

_url = "http://localhost:8080/fkit/login.jsp"
_user_agent = "Mozilla/5.0 (Windows NT 6.1; WOW64) "     \
              "AppleWebKit/537.36 (KHTML, like Gecko) "  \
              "Chrome/56.0.2924.87 Safari/537.36 "
_headers = {"User-Agent": _user_agent, "Connection": "Keep-Alive"}
_params = {"username": "bss9395", "password": "Pass"}
_request = urllib.request.Request(url=_url, headers=_headers, data=urllib.parse.urlencode(_params).encode())
_response = _opener.open(_request)
print(_response.read().decode("utf-8"))
_cookie_jar.save(ignore_discard=True, ignore_expires=True)

################################################################################

_cookie_jar = http.cookiejar.MozillaCookieJar()
_cookie_jar.load("cookie.txt", ignore_discard=True, ignore_expires=True)
for item in _cookie_jar:
    print((item.name, item.value))
_cookie_processor = urllib.request.HTTPCookieProcessor(_cookie_jar)
_opener = urllib.request.build_opener(_cookie_processor)

_url = "http://localhost:8080/fkit/secret.jsp"
_user_agent = "Mozilla/5.0 (Windows NT 6.1; WOW64) "     \
              "AppleWebKit/537.36 (KHTML, like Gecko) "  \
              "Chrome/56.0.2924.87 Safari/537.36 "
_headers = {"User-Agent": _user_agent, "Connection": "Keep-Alive"}
_request = urllib.request.Request(url=_url, headers=_headers)
_response = _opener.open(_request)
print(_response.read().decode("utf-8"))
