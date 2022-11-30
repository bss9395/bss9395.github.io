''' Py_matplotlib_plot_surface.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Library: matplotlib
'''


import numpy as numpy
import matplotlib.pyplot as pyplot
import matplotlib.font_manager as font_manager
import mpl_toolkits.mplot3d as mplot3d

class Matplotlib(object):
    _font = font_manager.FontProperties(fname='C:/Windows/Fonts/simkai.ttf')
    pyplot.rcParams['font.monospace'] = ['KaiTI']
    pyplot.rcParams['axes.unicode_minus'] = False
    _figure = 0

    @staticmethod
    def _Plot_Surface():
        figure = pyplot.figure(figsize=(12, 8))
        Matplotlib._figure += 1
        axes3d = figure.add_axes(mplot3d.Axes3D(figure))

        delta = 0.125
        x_data = numpy.arange(-3.0, 3.0, delta)
        y_data = numpy.arange(-2.0, 2.0, delta)
        (x, y) = numpy.meshgrid(x_data, y_data)
        z_0 = numpy.exp(- x ** 2 - y ** 2)
        z_1 = numpy.exp(- (x - 1) ** 2 - (y - 1) ** 2)
        z = (z_0 - z_1) * 2
        axes3d.plot_surface(x, y, z, cmap=pyplot.get_cmap('rainbow'))
        axes3d.contour(x, y, z, 16, zdir='z', offset=min(y_data), cmap=pyplot.get_cmap('rainbow'))
        axes3d.set_xlabel('经度')
        axes3d.set_ylabel('纬度')
        axes3d.set_zlabel('高度')
        axes3d.set_zlim(-2, 2)
        pyplot.title('3D图形')  # noop
        pyplot.savefig(fname='Py_matplotlib_plot_surface.svg', format='svg')
        pyplot.show()



if __name__ == '__main__':
    matplot = Matplotlib()
    matplot._Plot_Surface()
