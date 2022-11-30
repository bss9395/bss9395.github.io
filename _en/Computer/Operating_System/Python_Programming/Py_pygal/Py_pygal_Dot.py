''' Py_pygal_Dot.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Library: pygal
'''

import pygal

class Pygal(object):
    @staticmethod
    def _Dot():
        x_data = ['2011', '2012', '2013', '2014', '2015', '2016', '2017']
        y_data_0 = [58000, 60200, 63000, 71000, 84000, 90500, 107000]
        y_data_1 = [52000, 54200, 51500, 58300, 56800, 59500, 62700]
        dot = pygal.Dot()
        dot.add('疯狂Java讲义', y_data_0)
        dot.add('疯狂Android讲义', y_data_1)
        dot.x_labels = x_data
        dot.y_labels = ['疯狂Java讲义', '疯狂Android讲义']
        dot.y_label_rotation = -45
        dot.x_title = '年份'
        dot.y_title = '图书'
        dot.title = '《疯狂Java讲义》与《疯狂Android讲义》'
        dot.legend_at_bottom = True
        dot.render_to_file('Py_pygal_Dot.svg')

if __name__ == '__main__':
    gal = Pygal()
    gal._Dot()
