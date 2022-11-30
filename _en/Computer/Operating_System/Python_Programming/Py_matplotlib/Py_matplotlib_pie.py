''' Py_matplotlib_pie.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Library: matplotlib
'''


import matplotlib.pyplot as pyplot
import matplotlib.font_manager as font_manager

class Matplotlib(object):
    _font = font_manager.FontProperties(fname='C:/Windows/Fonts/simkai.ttf')
    pyplot.rcParams['font.monospace'] = ['KaiTI']
    pyplot.rcParams['axes.unicode_minus'] = False
    _figure = 0

    @staticmethod
    def _Pie():
        pyplot.figure(Matplotlib._figure)
        Matplotlib._figure += 1
        data = [0.16881, 0.14966, 0.07471, 0.06992, 0.04762, 0.03541, 0.02925, 0.02411, 0.02316, 0.01409, 0.36326]
        labels = ['Java', 'C', 'C++', 'Python', 'Visual Basic .NET', 'C#', 'PHP', 'JavaScript', 'SQL', 'Assembly Language', 'others']
        explode = [0, 0, 0, 0.1, 0, 0, 0, 0, 0, 0, 0]
        pyplot.pie(x=data, labels=labels, labeldistance=1.1, explode=explode, autopct='%.3f%%', pctdistance=0.8, counterclock=True)
        pyplot.title('TIOBE Languages 2018-08')
        pyplot.savefig(fname='Py_matplotlib_pie_Pie.svg', format='svg')
        pyplot.show()

if __name__ == '__main__':
    matplot = Matplotlib()
    matplot._Pie()
