''' Py_matplotlib_contour.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Library: matplotlib
'''

import numpy as numpy
import matplotlib.pyplot as pyplot
import matplotlib.font_manager as font_manager

class Matplotlib(object):
    _font = font_manager.FontProperties(fname='C:/Windows/Fonts/simkai.ttf')
    pyplot.rcParams['font.monospace'] = ['KaiTI']
    pyplot.rcParams['axes.unicode_minus'] = False
    _figure = 0

    @staticmethod
    def _Contour():
        pyplot.figure(Matplotlib._figure)
        Matplotlib._figure += 1
        delta = 0.025
        x_data = numpy.arange(-3.0, 3.0, delta)
        y_data = numpy.arange(-2.0, 2.0, delta)
        (x, y) = numpy.meshgrid(x_data, y_data)
        z_0 = numpy.exp(- x ** 2 - y ** 2)
        z_1 = numpy.exp(- (x - 1) ** 2 - (y - 1) ** 2)
        z = (z_0 - z_1) * 2
        pyplot.contourf(x, y, z, 16, alpha = 0.75)
        handle = pyplot.contour(x, y, z, 16, colors='black')
        pyplot.clabel(handle, inline=False)
        pyplot.xlabel('经度')
        pyplot.ylabel('纬度')
        pyplot.title('等高线图')
        pyplot.savefig(fname='Py_matplotlib_contour.svg', format='svg')
        pyplot.show()

if __name__ == '__main__':
    matplot = Matplotlib()
    matplot._Contour()
