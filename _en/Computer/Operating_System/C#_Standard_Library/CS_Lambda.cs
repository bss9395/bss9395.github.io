/* CS_Lambda.cs
Author: BSS9395
Update: 2022-04-17T18:20:00+08@China-Shanghai+08
Design: C# Language Feature: Lambda
*/

using System;
using System.Diagnostics;

class CS_Lambda {

    static void Main(string[] args) {
        // _Nested();
        // _Func();
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

    public static void _Func() {
        double a = 3;
        double b = 4;
        Func<double, double, double> Add = (double lhs, double rhs) => {
            return (lhs + rhs);
        };
        Console.WriteLine("{0} + {1} = {2}", a, b, Add(a, b));
    }

    delegate int Dele(int x);
    public static void _Lambda() {
        Dele dele0 = delegate (int x) {
            return x + 0;
        };
        Dele dele1 = (int x) => {
            return x + 1;
        };
        Dele dele2 = (x) => {
            return x + 2;
        };
        Dele dele3 = x => {
            return x + 3;
        };
        Dele dele4 = x => x + 4;

        Console.WriteLine($"dele0 = {dele0(12)}");
        Console.WriteLine($"dele1 = {dele1(12)}");
        Console.WriteLine($"dele2 = {dele2(12)}");
        Console.WriteLine($"dele3 = {dele3(12)}");
        Console.WriteLine($"dele4 = {dele4(12)}");
    }
}
