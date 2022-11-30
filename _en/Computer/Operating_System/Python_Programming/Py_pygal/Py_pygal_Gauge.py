''' Py_pygal_Gauge.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Library: pygal
'''

import pygal

class Pygal(object):
    @staticmethod
    def _Gauge():
        data = [0.16881, 0.14966, 0.07471, 0.06992, 0.04762, 0.03541, 0.02925, 0.02411, 0.02316, 0.01409, 0.36326]
        labels = ['Java', 'C', 'C++', 'Python', 'Visual Basic .NET', 'C#', 'PHP', 'JavaScript', 'SQL', 'Assembly langugage', '其他']
        gauge = pygal.Gauge()
        for (datum, label) in zip(data, labels):
            gauge.add(label, datum)
        gauge.range = [0, 1]
        gauge.title = 'TIOBE Languages 2018-08'
        gauge.legend_at_bottom = True
        gauge.render_to_file('Py_pygal_Gauge.svg')

if __name__ == '__main__':
    gal = Pygal()
    gal._Gauge()
