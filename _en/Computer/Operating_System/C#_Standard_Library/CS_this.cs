/* CS_this.cs
Author: BSS9395
Update: 2022-05-12T21:02:00+08@China-Shanghai+08
Design: C# Keyword: this
*/
class CS_this {
    public double _value = 123.456;
    public static void Main(String[] args) {
        CS_this cs = new CS_this();
        double _value = 456.123;
        Console.WriteLine("min{{ {0}, {1} }} = {0}", cs._value, _value, cs._this(_value));
    }
    public double _this(double _value) {
        return (this._value < _value ? this._value : _value);
    }
}
