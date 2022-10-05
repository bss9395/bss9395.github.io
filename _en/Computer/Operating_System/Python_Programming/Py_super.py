""" Py_super.py
Author: bss9395
Update: 2022-10-03T15:00:00+08@China-Guangdong-Zhanjiang+08
Design: Python Built-in Function: super
"""

class Fruit():
    def __init__(self, name):
        self.name = name
    def info(self):
        print("Fruit name: %s" % self.name)

class Food():
    def __init__(self, name, type):
        self.name = name
        self.type = type
    def info(self):
        print("Food info: name = %s, type = %s" % self.name, self.type)

class Apple(Fruit, Food):
    def __init__(self):
        Fruit.__init__(self, "Apple")
        Food.__init__(self, "apple", "fruit")
        super().__init__("super Apple")
        super(Apple, self).__init__("super Apple")
        # super().__init__("super apple", "super fruit") # note: error

apple = Apple()
apple.info()
