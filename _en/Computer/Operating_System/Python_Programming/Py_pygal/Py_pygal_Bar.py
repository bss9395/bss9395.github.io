''' Py_pygal_Bar.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Library: pygal
'''

import pygal as pygal
import codecs as codecs
import json as json

class Pygal(object):
    @staticmethod
    def _Bar():
        x_data = ['2011', '2012', '2013', '2014', '2015', '2016', '2017']
        y_data_0 = [58000, 60200, 63000, 71000, 84000, 90500, 107000]
        y_data_1 = [52000, 54200, 51500,58300, 56800, 59500, 62700]
        bar = pygal.Bar()
        bar.add('疯狂Java讲义', y_data_0)
        bar.add('疯狂Android讲义', y_data_1)
        bar.x_labels = x_data
        bar.x_label_rotation = -45
        bar.x_title = '年份'
        bar.y_title = '销量'
        bar.title = '《疯狂Java讲义》与《疯狂Android讲义》'
        bar.legend_at_bottom = True
        bar.render_to_file('Py_pygal_Bar.svg')

    @staticmethod
    def _JSON():
        gdp_filename = 'gdp.json'
        population_filename = 'population.json'
        years = range(2000, 2016)
        gdps_mean = {
            'USA': {'name': '美国', 'gdp_mean': []},
            'CHN': {'name': '中国', 'gdp_mean': []},
            'JPN': {'name': '日本', 'gdp_mean': []},
            'CAN': {'name': '加拿大', 'gdp_mean': []},
            'RUS': {'name': '俄罗斯', 'gdp_mean': []},
        }

        with codecs.open(gdp_filename, 'r', 'utf-8') as file:
            gdp_list = json.load(file)
        with codecs.open(population_filename, 'r', 'utf-8') as file:
            population_list = json.load(file)
        for gdp in gdp_list:
            (country, year) = (gdp['Country Code'], gdp['Year'])
            if country in gdps_mean.keys() and year in years:
                for population in population_list:
                    if population['Country_Code'] == country:
                        gdps_mean[country][year] = round(gdp['Value'] / population[f'Population_in_{year}'])
        for gdp_mean in gdps_mean.values():
            for year in years:
                gdp_mean['gdp_mean'].append(gdp_mean[year])

        bar = pygal.Bar()
        for gdp_mean in gdps_mean.values():
            bar.add(gdp_mean['name'], gdp_mean['gdp_mean'])
        bar.x_labels = years
        bar.x_label_rotation = -45
        bar.x_title = '年份'
        bar.y_title = '人均GDP /美元'
        bar.title = '2000年到2016年各国人均GDP对比'
        bar.legend_at_bottom = True
        bar.render_to_file('Py_pygal_Bar_JSON.svg')


if __name__ == '__main__':
    gal = Pygal()
    # gal._Bar()
    gal._JSON()
