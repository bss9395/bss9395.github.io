'''
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Library: scrapy
'''

import time

import scrapy
import selenium.webdriver
import selenium.webdriver.firefox.service
import selenium.webdriver.common.by

class WeiboSpider(scrapy.Spider):
    name = 'Weibo_Spider'
    allowed_domains = ['weibo.com']
    start_urls = ['http://weibo.com/']
    _headers  = {
        'Referer'   : 'https://weibo.com/login/',
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:107.0) Gecko/20100101 Firefox/107.0'
    }

    def __init__(self):
        super().__init__()
        print('=' * 10, self.__init__.__name__, flush=True)
        self._cookies = []

    def start_requests(self):
        print('=' * 10, self.start_requests.__name__, flush=True)
        service = selenium.webdriver.firefox.service.Service('geckodriver.exe')
        browser = selenium.webdriver.Firefox(service=service)
        browser.get('https://weibo.com/login.php')
        time.sleep(30)
        username = browser.find_element(selenium.webdriver.common.by.By.XPATH, '//input[@id="loginname"]')
        password = browser.find_element(selenium.webdriver.common.by.By.XPATH, '//input[@type="password"]')
        submit   = browser.find_element(selenium.webdriver.common.by.By.XPATH, '//a[@node-type="submitBtn"]')
        username.send_keys('bss9395')
        password.send_keys('*******')
        submit.click()
        time.sleep(10)

        if '微博-随时随地发现新鲜事' in browser.title:
            self._cookies = browser.get_cookies()
        else:
            print('=' * 10, '登录失败！', flush=True)

        print('=' * 10, self._cookies, flush=True)
        return [scrapy.Request('https://weibo.com/bss9395/', headers=self._headers, cookies=self._cookies, callback=self.parse)]

    def parse(self, response, **kwargs):
        print('=' * 10, self.parse.__name__, flush=True)

