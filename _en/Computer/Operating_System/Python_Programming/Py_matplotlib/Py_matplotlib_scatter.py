''' Py_matplotlib_scatter.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Library: matplotlib
'''


import matplotlib.pyplot as pyplot
import matplotlib.font_manager as font_manager
import numpy as numpy

class Matplotlib(object):
    _font = font_manager.FontProperties(fname='C:/Windows/Fonts/simkai.ttf')
    pyplot.rcParams['font.monospace'] = ['KaiTI']
    pyplot.rcParams['axes.unicode_minus'] = False
    _figure = 0

    @staticmethod
    def _Scatter():
        pyplot.figure(Matplotlib._figure)
        Matplotlib._figure += 1
        x_data = numpy.linspace(-numpy.pi, numpy.pi, 100, endpoint=True)
        pyplot.scatter(x_data, numpy.sin(x_data), marker='p')
        pyplot.scatter(x_data[0], numpy.sin(x_data[0]), c='red')
        pyplot.scatter(x_data[len(x_data) - 1], numpy.sin(x_data[len(x_data) - 1]), c='red')
        pyplot.gca().spines['bottom'].set_position(('data', 0))
        pyplot.gca().spines['top'].set_color('none')
        pyplot.gca().spines['right'].set_color('none')
        pyplot.title('正弦曲线的散点图', y=-0.05)
        pyplot.savefig(fname='Py_matplotlib_scatter_Scatter.svg', format='svg')
        pyplot.show()

if __name__ == '__main__':
    matplot = Matplotlib()
    matplot._Scatter()
