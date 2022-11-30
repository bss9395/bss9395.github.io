''' Py_matplotlib_bar.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Library: matplotlib
'''

import numpy as numpy
import matplotlib.pyplot as pyplot
import matplotlib.font_manager as font_manager
import codecs as codecs
import json as json

class Matplotlib(object):
    _font = font_manager.FontProperties(fname='C:/Windows/Fonts/simkai.ttf')
    pyplot.rcParams['font.monospace'] = ['KaiTI']
    pyplot.rcParams['axes.unicode_minus'] = False
    _figure = 0

    @staticmethod
    def _Bar():
        pyplot.figure(Matplotlib._figure)
        Matplotlib._figure += 1
        x_data = ['2011', '2012', '2013', '2014', '2015', '2016', '2017']
        y_data_0 = [58000, 60200, 63000, 71000, 84000, 90500, 107000]
        y_data_1 = [52000, 54200, 51500,58300, 56800, 59500, 62700]
        pyplot.bar(x=x_data, height=y_data_0, label='疯狂Java讲义', alpha=0.8)
        pyplot.bar(x=x_data, height=y_data_1, label='疯狂Android将以', alpha=0.8)
        for (x, y) in enumerate(y_data_0):
            pyplot.text(x, y, str(y), ha='center', va='bottom')
        for (x, y) in enumerate(y_data_1):
            pyplot.text(x, y, str(y), ha='center', va='bottom')

        pyplot.xlabel('年份')
        pyplot.ylabel('销量')
        pyplot.title('《疯狂Java讲义》与《疯狂Android讲义》')
        pyplot.legend()
        pyplot.gca().spines['top'].set_color('none')
        pyplot.gca().spines['right'].set_color('none')
        pyplot.savefig(fname='Py_matplotlib_bar_Bar.svg', format='svg')
        pyplot.show()

    @staticmethod
    def _Bar_Width():
        pyplot.figure(Matplotlib._figure)
        Matplotlib._figure += 1
        x_data = ['2011', '2012', '2013', '2014', '2015', '2016', '2017']
        y_data_0 = [58000, 60200, 63000, 71000, 84000, 90500, 107000]
        y_data_1 = [52000, 54200, 51500, 58300, 56800, 59500, 62700]
        bar_width = 0.3
        pyplot.bar(x=numpy.arange(len(x_data)) - bar_width / 2, width=bar_width, height=y_data_0, label='疯狂Java讲义', alpha=0.8)
        pyplot.bar(x=numpy.arange(len(x_data)) + bar_width / 2, width=bar_width, height=y_data_1, label='疯狂Android讲义', alpha=0.8)
        for (x, y) in enumerate(y_data_0):
            pyplot.text(x - bar_width / 2, y, str(y), ha='center', va='bottom')
        for (x, y) in enumerate(y_data_1):
            pyplot.text(x + bar_width / 2, y, str(y), ha='center', va='bottom')
        pyplot.xticks(numpy.arange(len(x_data)), x_data)
        pyplot.xlabel('年份')
        pyplot.ylabel('销量')
        pyplot.title('《疯狂Java讲义》与《疯狂Android讲义》')
        pyplot.legend()
        pyplot.gca().spines['top'].set_color('none')
        pyplot.gca().spines['right'].set_color('none')
        pyplot.savefig(fname='Py_matplotlib_bar_Bar_Width.svg', format='svg')
        pyplot.show()

    @staticmethod
    def _Barh():
        pyplot.figure(Matplotlib._figure)
        Matplotlib._figure += 1
        y_data = ['2011', '2012', '2013', '2014', '2015', '2016', '2017']
        x_data_0 = [58000, 60200, 63000, 71000, 84000, 90500, 107000]
        x_data_1 = [52000, 54200, 51500, 58300, 56800, 59500, 62700]
        bar_width = 0.3
        pyplot.barh(y=numpy.arange(len(y_data)) - bar_width / 2, height=bar_width, width=x_data_0, label='疯狂Java讲义', alpha=0.8)
        pyplot.barh(y=numpy.arange(len(y_data)) + bar_width / 2, height=bar_width, width=x_data_1, label='疯狂Android讲义', alpha=0.8)
        for (y, x) in enumerate(x_data_0):
            pyplot.text(x, y - bar_width, str(x), ha='left', va='bottom')
        for (y, x) in enumerate(x_data_1):
            pyplot.text(x, y, str(x), ha='left', va='bottom')
        pyplot.yticks(numpy.arange(len(y_data)), y_data)
        pyplot.ylabel('年份')
        pyplot.xlabel('销量')
        pyplot.title('《疯狂Java讲义》与《疯狂Android讲义》')
        pyplot.legend()
        pyplot.gca().spines['right'].set_color('none')
        pyplot.gca().spines['top'].set_color('none')
        pyplot.savefig(fname='Py_matplotlib_bar_Barh.svg', format='svg')
        pyplot.show()

    @staticmethod
    def _JSON():
        pyplot.figure(Matplotlib._figure, figsize=(15,8), dpi=128)
        Matplotlib._figure += 1
        filename = 'gdp.json'
        gdps = {
            'USA': {'name': '美国', 'gdp': []},
            'CHN': {'name': '中国', 'gdp': []},
            'JPN': {'name': '日本', 'gdp': []},
            'CAN': {'name': '加拿大', 'gdp': []},
            'RUS': {'name': '俄罗斯', 'gdp': []},
        }
        years = range(2000, 2016)
        with codecs.open(filename, 'r', 'utf-8') as file:
            gdp_list = json.load(file)
        for gdp in gdp_list:
            country = gdp['Country Code']
            if country in gdps.keys():
                year = gdp['Year']
                if year in years:
                    gdps[country][year] = gdp['Value']
        for gdp in gdps.values():
            for year in years:
                gdp['gdp'].append(gdp[year] / 1E8)


        bar_width = 1 / (len(gdps) + 1)
        for (i, gdp) in enumerate(gdps.values()):
            x_data = numpy.arange(len(gdp['gdp'])) + bar_width * i
            pyplot.bar(x=x_data, height=gdp['gdp'], label=gdp['name'], width=bar_width)
            if i < 2:
                for (x, y) in enumerate(gdp['gdp']):
                    pyplot.text(x + bar_width * i, y, f'{y:.0F}', ha='center', va='bottom')
        pyplot.xticks(numpy.arange(len(years)) + (-bar_width + bar_width * len(gdps)) / 2, years)
        pyplot.xlabel('年份')
        pyplot.ylabel('GDP /亿美元')
        pyplot.title('2000年到2016年各国GDP对比')
        pyplot.legend()
        pyplot.savefig(fname='Py_matplotlib_plot_JSON.svg', format='svg')
        pyplot.show()

if __name__ == '__main__':
    matplot = Matplotlib()
    # matplot._Bar()
    # matplot._Bar_Width()
    # matplot._Barh()
    matplot._JSON()