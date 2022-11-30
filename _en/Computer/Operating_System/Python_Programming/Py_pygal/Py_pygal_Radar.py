''' Py_pygal_Radar.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Library: pygal
'''

import pygal

class Pygal(object):
    @staticmethod
    def _Radar():
        labels = ['Java', 'C', 'C++', 'Python', 'C#', 'PHP']
        dimensions = ['平台健壮性', '语法易用性', '社区活跃度', '市场份额', '未来趋势']
        data = [[5, 4.0, 5, 5, 5],
                [4.8, 2.8, 4.8, 4.8, 4.9],
                [4.5, 2.9, 4.6, 4.0, 4.9],
                [4.0, 4.8, 4.9, 4.0, 5],
                [3.0, 4.2, 2.3, 3.5, 2],
                [4.8, 4.3, 3.9, 3.0, 4.5]]

        radar = pygal.Radar()
        for (datum, label) in zip(data, labels):
            radar.add(label, datum)
        radar.x_labels = dimensions
        radar.dots_size = 4
        radar.title = '编程语言对比图'
        radar.legend_at_bottom = True
        radar.render_to_file('Py_pygal_Radar.svg')

if __name__ == '__main__':
    gal = Pygal()
    gal._Radar()
