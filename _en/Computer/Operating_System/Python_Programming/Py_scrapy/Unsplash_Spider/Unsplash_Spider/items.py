'''
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Library: scrapy
'''

import scrapy


class Unsplash_Item(scrapy.Item):
    _image_id = scrapy.Field()
    _download = scrapy.Field()
