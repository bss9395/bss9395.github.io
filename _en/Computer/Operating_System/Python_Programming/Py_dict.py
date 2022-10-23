""" Py_dict.py
Author: BSS9395
Update: 2022-07-30T18:02:+08@China-Shanghai+08
Design: Python Built-in Class: dict
"""

steps = {"幼儿园": 10, "小学": 20, "初中": 30, "高中": 40, "大学": 50, "硕士": 60, "博士": 70, "讲师": 80, "教授": 90, "研究员": 100}
print(steps)
print("小学" in steps)

################################################################################

steps = dict(幼儿园 = 10, 小学 = 20, 初中 = 30, 高中 = 40, 大学 = 50, 硕士 = 60, 博士 = 70, 讲师 = 80, 教授 = 90, 研究员 = 100)
print(steps)

################################################################################

steps = [["幼儿园", 10], ["小学", 20], ["初中", 30], ["高中", 40], ["大学", 50], ["硕士", 60], ["博士", 70], ["讲师", 80], ["教授", 90], ["研究员", 100]]
print(steps)
steps = dict(steps)
print(steps)

################################################################################

print(steps.get("大专"))
steps.update({"教授": 100, "大专": 45})
print(steps)

print(steps.pop("小学"))
print(steps)

print(steps.popitem())
print(steps)

################################################################################

items = steps.items()
print(items)
print(type(items))

keys = steps.keys()
print(keys)
print(type(keys))

values = steps.values()
print(values)
print(type(values))

################################################################################

format = "大学: %(大学)d，硕士: %(硕士)d"
print(format % steps)

################################################################################

class Person():
    def __init__(self, name, age):
        self.name = name
        self.age = age

person = Person("bss9395", 28)
print(person.__dict__)
person.__dict__["age"] = 29
print(person.__dict__)
