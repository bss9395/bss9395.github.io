'''
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Library: scrapy
'''


import json
import sqlite3
import os

class Zhipin_Pipeline:
    def open_spider(self, spider):
        print('=' * 10 + self.open_spider.__name__ + '=' * 10, flush=True)
        print(spider.name, flush=True)
        if os.path.exists('zhipin.sqlite'):
            os.remove('zhipin.sqlite')
        self._connect = sqlite3.connect('zhipin.sqlite')
        self._sql_create = '''
        create table zhipin (
            'id' integer not null,
            'title' text,
            'salary' text,
            primary key('id' autoincrement)
        );
        '''
        self._sql_insert = '''
        insert into zhipin (title, salary)
        values ('{}', '{}');
        '''
        self._connect.execute(self._sql_create)
        self._cursor = self._connect.cursor()

        self._json = open('zhipin.json', 'wb')
        self._json.write('['.encode('utf-8'))
        self._count = 0

    def process_item(self, item, spider):
        print('=' * 10 + self.process_item.__name__ + '=' * 10, flush=True)
        print(spider.name, flush=True)
        # print(item['title'], flush=True)
        # print(item['salary'], flush=True)
        insert_item = self._sql_insert.format(item['title'], item['salary'])
        print(insert_item, flush=True)
        self._cursor.execute(insert_item)
        self._connect.commit()

        self._count += 1
        if self._count <= 1:
            json_text = '\n' + json.dumps(dict(item))
        else:
            json_text = ',\n' + json.dumps(dict(item))
        print(json_text, flush=True)
        self._json.write(json_text.encode('utf-8'))

        return item

    def close_spider(self, spider):
        print('=' * 10 + self.close_spider.__name__ + '=' * 10, flush=True)
        print(spider.name, flush=True)
        self._connect.close()

        self._json.write('\n]\n'.encode('utf-8'))
        self._json.close()
