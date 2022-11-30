''' Py_re.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Standard Library: re
'''

import re

class RE():
    @staticmethod
    def _Match():
        match_0 = re.match('bss9395', 'bss9395.github.io')
        print(match_0.span())
        print(match_0.group())
        match_1 = re.match('github', 'bss9395.github.io')
        print(match_1)

    @staticmethod
    def _Search():
        search_0 = re.search('bss9395', 'bss9395.github.io')
        print(search_0.span())
        print(search_0.group())
        search_1 = re.search('github', 'bss9395.github.io')
        print(search_1.span())
        print(search_1.group())

    @staticmethod
    def _Find_All():
        find_all = re.findall('big', 'Big big girl.', re.I)
        print(find_all)

    @staticmethod
    def _Find_Iter():
        find_iter = re.finditer('big', 'Big big girl.', re.I)
        for iter in find_iter:
            print((iter.start(), iter.group()))

    @staticmethod
    def _Sub():
        sub_0 = re.sub('-', '/', '2022-11-29')
        sub_1 = re.sub('-', '/', '2022-11-29', 1)
        print(sub_0)
        print(sub_1)

        def _Func(matched):
            return f'《{matched.group()}》'
        sub_2 = re.sub('(?P<lang>\w+)', _Func, 'Python很好，Java也很好', flags=re.A)
        print(sub_2)

    @staticmethod
    def _Split():
        split_0 = re.split(', ', 'Big, big, girl.')
        print(split_0)

    @staticmethod
    def _Escape():
        escape_0 = re.escape('Big, big, girl.')
        print(escape_0)

    @staticmethod
    def _Group_Dict():
        group_0 = re.search(r'(?P<github_io>(?P<github>github).(?P<io>io))', 'bss9395.github.io is a good domain.')
        print(group_0.span())
        print(group_0.groups())
        print(group_0.groupdict())

    @staticmethod
    def _Sub_Expression():
        search_0 = re.search(r'Windows (95|98|NT|2000)[\w ]+\1', 'Windows 98 published in 98')
        print(search_0)
        search_1 = re.search(r'<(?P<tag>\w+)>\w+</(?P=tag)>', '<h3>xx</h3>')
        print(search_1)
        search_2 = re.search(r'(?<=<h1>).+?(?=</h1>)', 'hello <h1>bss9395.github.io</h1>!')
        print(search_2)
        search_3 = re.search(r'[a-zA-Z0-9_]+(?#username)\.github\.io', 'welcome to bss9395.github.io!')
        print(search_3)
        search_4 = re.search(r'(?i)[a-z0-9_]+(?#username)\.github\.io', 'welcome to BSS9395.github.io!')
        print(search_4)
        search_5 = re.search(r'(?i:[a-z0-9_]+)(?#username)\.github\.io', 'welcome to BSS9395.github.io!')
        print(search_5)
        search_6 = re.search(r'(@.+\.)', 'bss9395@github.com.cn')
        print(search_6)
        search_7 = re.search(r'(@.+?\.)', 'bss9395@github.com.cn')
        print(search_7)

if __name__ == '__main__':
    # RE._Match()
    # RE._Search()
    # RE._Find_All()
    # RE._Find_Iter()
    # RE._Sub()
    # RE._Split()
    # RE._Escape()
    # RE._Group_Dict()
    RE._Sub_Expression()

