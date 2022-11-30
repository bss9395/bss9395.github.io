''' Supermarket.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Supermarket
'''

import os

class Supermarket(object):
    def __init__(self):
        goods_0 = ['10001', 'C', 90.0]
        goods_1 = ['10002', 'C++', 80.0]
        goods_2 = ['10003', 'C#', 70.0]
        goods_3 = ['10004', 'Java', 80.0]
        goods_4 = ['10005', 'Python', 80.0]
        self._repository = {}
        self._repository[goods_0[0]] = goods_0
        self._repository[goods_1[0]] = goods_1
        self._repository[goods_2[0]] = goods_2
        self._repository[goods_3[0]] = goods_3
        self._repository[goods_4[0]] = goods_4
        self._cart = []
    def _Operating(self):
        while True:
            self._Show_Command()
    def _Show_Command(self):
        print('='*80)
        print(f'goods  => show goods')
        print(f'cart   => show cart')
        print(f'add    => add item')
        print(f'edit   => edit cart')
        print(f'delete => delete item')
        command = input('command: ')
        if command == 'goods':
            self._Show_Goods()
        elif command == 'cart':
            self._Show_Cart()
        elif command == 'add':
            self._Cart_Add()
        elif command == 'edit':
            self._Cart_Edit()
        elif command == 'delete':
            self._Cart_Delete()
        elif command == 'exit':
            os._exit(0)
        else:
            print('wrong command...')
    def _Show_Goods(self):
        print('='*80)
        print('Goods list: ')
        print(f'{"code":<10}{"name":<10}{"price":<10}')
        for goods in self._repository.values():
            print(f'{goods[0]:<10}{goods[1]:<10}{goods[2]:<10}')
    def _Show_Cart(self):
        print('='*80)
        print('shopping cart: ')
        print(f'{"ID":<10}{"code":<10}{"name":<10}{"price":<10}{"quantity":<10}{"amount":<10}')
        sum = 0.0
        for (i, item) in enumerate(self._cart):
            id = i + 1
            code = item[0]
            name = self._repository[code][1]
            price = self._repository[code][2]
            quantity = item[1]
            amount = price * quantity
            sum += amount
            print(f'{id:<10}{code:<10}{name:<10}{price:<10}{quantity:<10}{amount:<10}')
            print(f'{"total":>40}: {sum}')
    def _Cart_Add(self):
        code = input('goods code: ')
        if code not in self._repository.keys():
            print('wrong code...')
            return
        goods = self._repository[code]
        quantity = input('quantity: ')
        self._cart.append([code, int(quantity)])
    def _Cart_Edit(self):
        id = input('id: ')
        item = self._cart[int(id) - 1]
        quantity = input('quantity: ')
        item[1] = int(quantity)
    def _Cart_Delete(self):
        id = input('id: ')
        del self._cart[int(id) - 1]


if __name__ == '__main__':
    supermarket = Supermarket()
    supermarket._Operating()
