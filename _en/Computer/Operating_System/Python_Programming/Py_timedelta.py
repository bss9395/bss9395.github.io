''' Py_timedelta.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Standard Library: timedelta
'''

import datetime as datetime

class Timedelta(object):
    @staticmethod
    def _Timedelta():
        date_prev = '2016-03-03'
        date_curr = '2016-03-06'
        date_prev = datetime.datetime.strptime(date_prev, '%Y-%m-%d')
        date_curr = datetime.datetime.strptime(date_curr, '%Y-%m-%d')
        date_diff = date_curr - date_prev
        if date_diff != datetime.timedelta(days=2):
            print(f'lack of {date_diff.days - 1} days before {date_curr}')

if __name__ == '__main__':
    timedelta = Timedelta()
    timedelta._Timedelta()
