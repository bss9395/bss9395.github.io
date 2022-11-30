'''
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Library: scrapy
'''

import scrapy
from Zhipin.items import JobItem

class Zhipin_Spider(scrapy.Spider):
    name = 'Zhipin_Spider'
    allowed_domains = ['www.zhipin.com']
    start_urls = ['https://www.zhipin.com/shanghai/']

    def parse(self, response, **kwargs):
        print('=' * 10 + self.parse.__name__ + '=' * 10, flush=True)
        titles = response.xpath('//div[@class="sub-li-top"]/p[1]/text()').extract()
        salaries = response.xpath('//div[@class="sub-li-top"]/p[2]/text()').extract()
        for (title, salary) in zip(titles, salaries):
            job = JobItem()
            job['title'] = title
            job['salary'] = salary
            yield job

        # next_links = response.xpath('//a[@ka="open_joblist"]/@href').extract()
        # if next_links:
        #     next_link = self.allowed_domains[0] + next_links[0]
        #     print('=' * 10, next_link, '=' * 10, flush=True)
        #     yield scrapy.Request(next_link, callback=self.parse)