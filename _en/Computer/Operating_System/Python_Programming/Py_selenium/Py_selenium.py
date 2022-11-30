''' Py_selenium.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Library: selenium
'''

import selenium.webdriver
import selenium.webdriver.firefox.service
import selenium.webdriver.common.by
import selenium.webdriver.chrome.service
import time

class Selenium(object):
    def __init__(self):
        # service  = selenium.webdriver.firefox.service.Service('geckodriver.exe')
        # browser  = selenium.webdriver.Firefox(service=service)
        service = selenium.webdriver.chrome.service.Service('chromedriver.exe')
        browser = selenium.webdriver.Chrome(service=service)
        browser.get('https://weibo.com/login')
        time.sleep(10)
        username = browser.find_element(selenium.webdriver.common.by.By.XPATH, '//input[@id="loginname"]')
        username.send_keys('bss9395')
        time.sleep(1)
        password = browser.find_element(selenium.webdriver.common.by.By.XPATH, '//input[@type="password"]')
        password.send_keys('Password9395')
        time.sleep(1)
        submit = browser.find_element(selenium.webdriver.common.by.By.XPATH, '//a[@node-type="submitBtn"]')
        submit.click()
        time.sleep(10)

        if '微博-随时随地发现新鲜事' in browser.title:
            _cookies = browser.get_cookies()
            print('=' * 10, _cookies, flush=True)
        else:
            print('=' * 10, '登录失败！', flush=True)

if __name__ == '__main__':
    Selenium()



