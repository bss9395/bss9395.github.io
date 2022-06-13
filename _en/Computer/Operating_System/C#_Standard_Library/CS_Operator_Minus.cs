/* CS_Operator_Minus.cs
Author: BSS9395
Update: 2022-05-30T13:04:00+08@China-Shanghai+08
Design: C# Language Feature: Operator Minus
*/

using System;

class CS_Operator_Minus {
    /* public class Minus { */   // note: increasement and decreasement are not for class.
    public struct Minus {        // note: increasement and decreasement are for struct.   
        public double _value;
        public Minus(double value = 0.0) {
            _value = value;
        }
        public static Minus operator -(Minus lhs) {
            Minus minus = new Minus();
            minus._value = -lhs._value;
            return minus;
        }
        public static Minus operator -(Minus lhs, double rhs) {
            Minus minus = new Minus();
            minus._value = lhs._value - rhs;
            return minus;
        }
        public static Minus operator --(Minus minus) {
            minus._value--;
            return minus;
        }
    }
    public static void Main(String[] args) {
        // _Minus();
        _Decrease();
    }
    public static void _Minus() {
        Minus lhs = new Minus(10.0);
        Minus unary = -lhs;
        Minus binary = lhs - 5.0;
        Console.WriteLine($"-lhs == {unary._value}");
        Console.WriteLine($"lhs - 5.0 == {binary._value}");
    }
    public static void _Print(String message, Minus minus) {
        Console.WriteLine($"{message}: minus._value == {minus._value}");
    }
    public static void _Decrease() {
        Minus minus = new Minus(10);
        _Print("pre decrease", --minus);

        minus = new Minus(10);
        _Print("post decrease", minus--);
    }
}
