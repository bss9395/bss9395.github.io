/* CS_Lambda.cs
Author: BSS9395
Update: 2022-04-17T18:20:00+08@China-Shanghai+08
Design: C# Language Feature: Lambda
*/

using System;
using System.Diagnostics;

class CS_Lambda {
    static void Main(string[] args) {
        _Nested();
        _Lambda();
    }
    public static double _Add(double lhs, double rhs) {
        return (lhs + rhs);
    }
    public static void _Nested() {
        double a = 3;
        double b = 4;
        double Add(double lhs, double rhs) {
            return (lhs + rhs);
        }
        Console.WriteLine("{0} + {1} = {2}", a, b, Add(a, b));
        Console.WriteLine("{0} + {1} = {2}", a, b, CS_Lambda._Add(a, b));
    }
    public static void _Lambda() {
        double a = 3;
        double b = 4;
        Func<double, double, double> Add = (double lhs, double rhs) => {
            return (lhs + rhs);
        };
        Console.WriteLine("{0} + {1} = {2}", a, b, Add(a, b));
    }
}
