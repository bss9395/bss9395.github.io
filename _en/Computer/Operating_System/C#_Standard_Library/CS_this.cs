/* CS_this.cs
Author: BSS9395
Update: 2022-05-12T21:02:00+08@China-Shanghai+08
Design: C# Keyword: this
*/

class Datum {
    public double[] _values = new double[3];
    public Datum(double value0, double value1, double value2) {
        _values[0] = value0;
        _values[1] = value1;
        _values[2] = value2;
    }
    public double _Sum() {
        double sum = 0.0;
        for (int i = 0; i < _values.Length; i += 1) {
            sum += _values[i];
        }
        return sum;
    }
}
class Regular {
    public static double _Average(Datum datum) {
        return datum._Sum() / 3;
    }
}
static class Extend {
    public static double _Average(this Datum datum) {
        return datum._Sum() / 3;
    }
}

class CS_this {
    public static void Main(String[] args) {
        // _Test_this();
        _Test_Extend_this();
    }
    public static void _Test_this() {
        CS_this cs = new CS_this();
        double _value = 456.123;
        Console.WriteLine("min{{ {0}, {1} }} = {0}", cs._value, _value, cs._this(_value));
    }
    public static void _Test_Extend_this() {
        Datum datum = new Datum(3, 4, 5);
        Console.WriteLine("sum = {0}", datum._Sum());
        Console.WriteLine("avg = {0}", datum._Average());
    }
    public double _value = 123.456;
    public double _this(double _value) {
        return (this._value < _value ? this._value : _value);
    }
}
