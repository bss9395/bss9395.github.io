''' Py_pygal_StackedLine.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Library: pygal
'''

import pygal

class Pygal(object):
    @staticmethod
    def _StackedLine():
        x_data = ['2011', '2012', '2013', '2014', '2015', '2016', '2017']
        y_data_0 = [58000, 60200, 63000, 71000, 84000, 90500, 107000]
        y_data_1 = [52000, 54200, 51500, 58300, 56800, 59500, 62700]
        stacked_line = pygal.StackedLine()
        stacked_line.add('疯狂Java讲义', y_data_0)
        stacked_line.add('疯狂Android讲义', y_data_1)
        stacked_line.x_labels = x_data
        stacked_line.y_labels = [20000, 40000, 60000, 80000, 100000]
        stacked_line.x_title = '销量'
        stacked_line.y_title = '年份'
        stacked_line.title = '《疯狂Java讲义》与《疯狂Android讲义》'
        stacked_line.legend_at_bottom = True
        stacked_line.render_to_file('Py_pygal_StackedLine.svg')

if __name__ == '__main__':
    gal = Pygal()
    gal._StackedLine()
