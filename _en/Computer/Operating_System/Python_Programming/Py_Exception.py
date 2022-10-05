""" Py_Exception.py
Author: bss9395
Update: 2022-10-T14:17:00+08@China-Guangdong-Zhanjiang+08
Design: Python Language Feature: Exception
"""

class Gobang():
    _height = 5
    _width = 5

    def _Init(self) :
        self.board = []
        for row in range(Gobang._height) :
            string = ["╋"] * Gobang._width
            self.board.append(string)

    def _Print(self) :
        for row in range(Gobang._height) :
            for col in range(Gobang._width) :
                print(self.board[row][col], end="")
            print()

    def _Run(self):
        self._Init()
        self._Print()
        string = input("input coordinate (x, y): \n")
        while string != None :
            try:
                x, y = string.split(sep = ",")
                if self.board[int(y)][int(x)] != "╋":
                    string = input("invalid input, reinput coordinate (x, y): \n")
                    continue
                self.board[int(y)][int(x)] = "●"
            except Exception:
                string = input("invalid input, reinput coordinate (x, y): \n")
                continue
            self._Print()
            string = input("input coordinate (x, y): \n")

Gobang()._Run()