'''
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Library: scrapy
'''

import scrapy
import json
from Unsplash_Spider.items import Unsplash_Item

class Unsplash_Spider(scrapy.Spider):
    name = 'Unsplash_Spider'
    allowed_domains = ['unsplash.com']
    start_urls = ['https://unsplash.com/napi/photos?per_page=12&page=1']

    def __init__(self, **kwargs):
        super().__init__(**kwargs)
        print('=' * 20, self.__init__.__name__, flush=True)
        self._page = 1

    def parse(self, response, **kwargs):
        print('=' * 20, self.parse.__name__, flush=True)
        print('=' * 20, response, flush=True)

        images = json.loads(response.text)
        for image in images:
            item = Unsplash_Item()
            item['_image_id'] = image['id']
            item['_download'] = image['links']['download']
            yield item
        self._page += 1

        next_page = f'https://unsplash.com/napi/photos?per_page=12&page={self._page}'
        yield scrapy.Request(next_page, callback=self.parse)
