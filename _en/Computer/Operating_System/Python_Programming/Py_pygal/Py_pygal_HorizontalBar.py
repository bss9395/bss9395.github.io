''' Py_pygal_HorizontalBar.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Library: pygal
'''

import pygal as pygal

class Pygal(object):
    @staticmethod
    def _HorizontalBar():
        y_data = ['2011', '2012', '2013', '2014', '2015', '2016', '2017']
        x_data_0 = [58000, 60200, 63000, 71000, 84000, 90500, 107000]
        x_data_1 = [52000, 54200, 51500, 58300, 56800, 59500, 62700]
        horizontal_bar = pygal.HorizontalBar()
        horizontal_bar.add('疯狂Java讲义', x_data_0)
        horizontal_bar.add('疯狂Android讲义', x_data_1)
        horizontal_bar.x_labels = y_data
        horizontal_bar.y_labels = [20000, 40000, 60000, 80000, 100000]
        horizontal_bar.x_title = '销量'
        horizontal_bar.y_title = '年份'
        horizontal_bar.title = '《疯狂Java讲义》与《疯狂Android讲义》'
        horizontal_bar.legend_at_bottom = True
        horizontal_bar.render_to_file('Py_pygal_HorizontalBar.svg')

if __name__ == '__main__':
    gal = Pygal()
    gal._HorizontalBar()
