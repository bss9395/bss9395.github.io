'''
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Library: scrapy
'''


import urllib.request

class Unsplash_Pipeline:
    def process_item(self, item, spider):
        print('=' * 20, self.process_item.__name__, flush=True)
        print('=' * 20, spider.name, flush=True)

        try:
            print('=' * 20, item, flush=True)
            url = f'{item["_download"]}&force=true'
            print('=' * 20, url, flush=True)
            with urllib.request.urlopen(url) as stream:
                data = stream.read()
                with open(f'images/{item["_image_id"]}.jpg', 'wb') as file:
                    file.write(data)
        except Exception as exception:
            print(str(exception), flush=True)
            print(f'error occurs: {item["_image_id"]}')

        return item
