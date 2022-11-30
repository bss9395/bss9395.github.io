''' Py_matplotlib_plot.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Library: matplotlib
'''

import urllib.request
import re as re

import matplotlib.pyplot as pyplot
import matplotlib.font_manager as font_manager
import matplotlib.gridspec as gridspec
import numpy as numpy
import csv as csv
import datetime as datetime
import codecs as codecs


class Matplotlib(object):
    _font = font_manager.FontProperties(fname='C:/Windows/Fonts/simkai.ttf')
    pyplot.rcParams['font.monospace'] = ['KaiTI']
    pyplot.rcParams['axes.unicode_minus'] = False
    _figure = 0

    @staticmethod
    def _Plot():
        pyplot.figure(Matplotlib._figure)
        Matplotlib._figure += 1
        x_data = ['2011', '2012', '2013', '2014', '2015', '2016', '2017']
        y_data_0 = [58000, 60200, 63000, 71000, 84000, 90500, 107000]
        y_data_1 = [52000, 54200, 51500,58300, 56800, 59500, 62700]

        (handle_0, ) = pyplot.plot(x_data, y_data_0, color='red', linewidth=2.0, linestyle='--')
        (handle_1, ) = pyplot.plot(x_data, y_data_1, color='blue', linewidth=3.0, linestyle='-.')
        pyplot.yticks([50000, 70000, 100000], ['挺好', '优秀', '火爆'])
        axies = pyplot.gca()
        axies.xaxis.set_ticks_position('bottom')
        axies.yaxis.set_ticks_position('left')
        axies.spines['right'].set_color('none')
        axies.spines['top'].set_color('none')
        axies.spines['bottom'].set_position(('data', 70000))

        pyplot.xlabel('年份 /1')
        pyplot.ylabel('图书销量 /本')
        pyplot.title('疯狂图书的历年销量')
        pyplot.legend(handles=[handle_0, handle_1], labels=['疯狂Java讲义年销量', '疯狂Android讲义年销量'], loc='best')
        pyplot.savefig(fname='Py_matplotlib_plot_Plot.svg', format='svg')
        pyplot.show()

    @staticmethod
    def _Subplot():
        pyplot.figure(Matplotlib._figure)
        Matplotlib._figure += 1
        x_data = numpy.linspace(-numpy.pi, numpy.pi, 100, endpoint=True)

        pyplot.subplot(2, 1, 1)
        pyplot.plot(x_data, numpy.sin(x_data))
        pyplot.gca().spines['right'].set_color('none')
        pyplot.gca().spines['top'].set_color('none')
        pyplot.gca().spines['bottom'].set_position(('data', 0))
        pyplot.gca().spines['left'].set_position(('data', 0))
        pyplot.title('正弦曲线')

        pyplot.subplot(2, 3, 4)
        pyplot.plot(x_data, numpy.cos(x_data))
        pyplot.gca().spines['right'].set_color('none')
        pyplot.gca().spines['top'].set_color('none')
        pyplot.gca().spines['bottom'].set_position(('data', 0))
        pyplot.gca().spines['left'].set_position(('data', 0))
        pyplot.title('余弦曲线')

        pyplot.subplot(2, 2, 4)
        pyplot.plot(x_data, numpy.tan(x_data))
        pyplot.gca().spines['right'].set_color('none')
        pyplot.gca().spines['top'].set_color('none')
        pyplot.gca().spines['bottom'].set_position(('data', 0))
        pyplot.gca().spines['left'].set_position(('data', 0))
        pyplot.title('正切曲线')
        pyplot.savefig(fname='Py_matplotlib_plot_Subplot.svg', format='svg')
        pyplot.show()

    @staticmethod
    def _GridSpec():
        pyplot.figure(Matplotlib._figure)
        Matplotlib._figure += 1
        x_data = numpy.linspace(-numpy.pi, numpy.pi, 100, endpoint=True)

        grid = gridspec.GridSpec(2, 3)
        axis_0 = pyplot.subplot(grid[0, :])
        axis_1 = pyplot.subplot(grid[1, 0])
        axis_2 = pyplot.subplot(grid[1, 1:3])

        axis_0.plot(x_data, numpy.sin(x_data))
        axis_0.spines['right'].set_color('none')
        axis_0.spines['top'].set_color('none')
        axis_0.spines['bottom'].set_position(('data', 0))
        axis_0.spines['left'].set_position(('data', 0))
        axis_0.set_title('正弦曲线')

        axis_1.plot(x_data, numpy.cos(x_data))
        axis_1.spines['right'].set_color('none')
        axis_1.spines['top'].set_color('none')
        axis_1.spines['bottom'].set_position(('data', 0))
        axis_1.spines['left'].set_position(('data', 0))
        axis_1.set_title('余弦曲线')

        axis_2.plot(x_data, numpy.tan(x_data))
        axis_2.spines['right'].set_color('none')
        axis_2.spines['top'].set_color('none')
        axis_2.spines['bottom'].set_position(('data', 0))
        axis_2.spines['left'].set_position(('data', 0))
        axis_2.set_title('正切曲线')

        pyplot.savefig(fname='Py_matplotlib_plot_GridSpec.svg', format='svg')
        pyplot.show()

    @staticmethod
    def _CSV():
        pyplot.figure(Matplotlib._figure)
        Matplotlib._figure += 1
        filename = 'guangzhou_2017.csv'
        (dates, highs, lows) = ([], [], [])
        with codecs.open(filename, "r", "utf-8") as file:
            reader = csv.reader(file)
        (start_date, end_date) = (datetime.datetime(2017, 6, 30), datetime.datetime(2017, 8, 1))
        header = next(reader)
        print(header)
        for row in reader:
            date = datetime.datetime.strptime(row[0], '%Y-%m-%d')
            if start_date < date < end_date:
                dates.append(date)
                highs.append(int(row[1]))
                lows.append(int(row[2]))
        figure = pyplot.figure(0, figsize=(12, 9), dpi=128)
        pyplot.plot(dates, highs, label='最高气温', c='red', linestyle='-', marker='o')
        pyplot.plot(dates, lows, label='最低气温', c='blue', linestyle='-', marker='o')
        pyplot.fill_between(dates, highs, lows, facecolor='blue', alpha=0.1)
        pyplot.xticks(rotation=45)
        pyplot.xlabel('日期')
        pyplot.ylabel('气温 /°C')
        pyplot.title('广州2017年7月最高气温与最低气温')
        pyplot.gca().spines['top'].set_color('none')
        pyplot.gca().spines['right'].set_color('none')
        pyplot.legend()
        pyplot.savefig(fname='Py_matplotlib_plot_CSV.svg', format='svg')
        pyplot.show()

    @staticmethod
    def _Urllib():
        def _Get_HTML(city, year, month):
            url = f'http://lishi.tianqi.com/{city}/{year}{month}.html'
            request = urllib.request.Request(url)
            request.add_header('User-Agent', 'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/54.0.2840.99 Safari/537.36')
            response = urllib.request.urlopen(request)
            return response.read().decode('utf-8')

        def _Parse_HTML(html):
            temperatures = []
            ul = re.findall(re.compile('<ul class="thrui">(.*?)</ul>', re.S), html)
            # print(ul)
            lis = re.findall(re.compile('<li.*?>(.*?)</li>', re.S), ul[0])
            for li in lis:
                # print(li)
                divs = re.findall(re.compile('<div class=".*?">(.*?)</div>', re.S), li)
                # print(divs)
                # date = datetime.datetime.strptime(divs[0].split()[0], '%Y-%m-%d')
                date = divs[0].split()[0]
                # print(date)
                high = re.findall(re.compile('(.{1,2})℃'), divs[1])[0]
                # print(high)
                low = re.findall(re.compile('(.{1,2})℃'), divs[2])[0]
                # print(low)
                description = divs[3]
                # print(description)
                (direction, force) = divs[4].split(' ')
                # print(direction, force)
                temperatures.append([date, high, low, description, direction, force])
            return temperatures

        def _Dump_Data(temperatures, city, year):
            with codecs.open(f'{city}_{year}.csv', 'w', 'utf-8') as file:
                file.write(','.join(['date', 'high', 'low', 'description', 'direction', 'force']) + '\n')
                for temperature in temperatures:
                    print(temperature)
                    file.write(','.join(temperature) + '\n')

        def _Plot_Data(temperatures, city, year):
            pyplot.figure(Matplotlib._figure, figsize=(16, 9), dpi=128)
            Matplotlib._figure += 1
            dates = [datetime.datetime.strptime(temperature[0], '%Y-%m-%d') for temperature in temperatures]
            highs = [float(temperature[1]) for temperature in temperatures]
            lows  = [float(temperature[2]) for temperature in temperatures]
            pyplot.plot(dates, highs, label='最高气温', c='red')
            pyplot.plot(dates, lows, label='最低气温', c='green')
            pyplot.fill_between(dates, highs, lows, facecolor='blue', alpha=0.5)
            pyplot.xticks(rotation=45)
            pyplot.xlabel('日期')
            pyplot.ylabel('气温 /°C')
            pyplot.title(f'{city}_{year}_最高气温与最低气温')
            pyplot.legend()
            pyplot.gca().spines['top'].set_color('none')
            pyplot.gca().spines['right'].set_color('none')
            pyplot.savefig(fname=f'{city}_{year}_temperature.svg', format='svg')
            pyplot.show()

        cities = ['guangzhou']
        years = ['2017']
        months = ['01', '02', '03', '04', '05', '06', '07', '08', '09', '10', '11', '12']
        for city in cities:
            for year in years:
                temperatures = []
                for month in months:
                    temperatures += _Parse_HTML(_Get_HTML(city, year, month))
                print(temperatures)
                # _Dump_Data(temperatures, city, year)
                _Plot_Data(temperatures, city, year)


if __name__ == '__main__':
    matplot = Matplotlib()
    # matplot._Plot()
    # matplot._Subplot()
    # matplot._GridSpec()
    # matplot._CSV()
    matplot._Urllib()
