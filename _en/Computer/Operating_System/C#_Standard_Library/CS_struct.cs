/* CS_struct.cs
Author: BSS9395
Update: 2022-05-31T15:20:00+08@China-Shanghai+08
Design: C# Keyword: struct
*/

using System;

class CS_struct {
    struct Point {
        public int _x;
        public int _y;
    }
    public static void Main(String[] args) {
        _struct();
    }
    public static void _struct() {
        Point lhs;
        Point rhs;
        Point point;
        lhs._x = 10;
        lhs._y = 10;
        rhs._x = 20;
        rhs._y = 20;
        point._x = lhs._x + rhs._x;
        point._y = lhs._y + rhs._y;

        Console.WriteLine($"point._x == {point._x}, point._y == {point._y}");
    }
}
