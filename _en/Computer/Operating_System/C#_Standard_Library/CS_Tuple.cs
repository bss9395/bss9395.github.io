/* CS_Tuple.cs
Author: BSS9395
Update: 2022-05-21T21:04:00+08@China-Shanghai+08
Design: C# Standard Library: Tuple
*/

using System;
class CS_Tuple {
    public Tuple<double, double, double> _New_Tuple() {
        return new Tuple<double, double, double>(0.1, 0.2, 0.3);
    }

    public Tuple<double, double, double> _Tuple_Create() {
        return Tuple.Create(0.1, 0.2, 0.3);
    }

    public (double in01, double in02, double in03) _New_ValueTuple() {
        return new ValueTuple<double, double, double>(0.1, 0.2, 0.3);
    }

    public (double in01, double in02, double in03) _ValueTuple() {
        return (0.1, 0.2, 0.3);
    }

    public static void Main() {
        // _Test_Tuple();
        _Test_ValueTuple();
    }
    public static void _Test_Tuple() {
        CS_Tuple cs_tuple = new CS_Tuple();
        Console.WriteLine($"item2 = {cs_tuple._New_Tuple().Item2}");
        Console.WriteLine($"item2 = {cs_tuple._Tuple_Create().Item2}");
    }
    public static void _Test_ValueTuple() {
        CS_Tuple cs_tuple = new CS_Tuple();
        Console.WriteLine($"item2 = {cs_tuple._New_ValueTuple().in02}");
        Console.WriteLine($"item2 = {cs_tuple._ValueTuple().in02}");
    }
}
