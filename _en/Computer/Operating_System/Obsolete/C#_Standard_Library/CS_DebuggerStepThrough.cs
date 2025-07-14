/* CS_DebuggerStepThrough.cs
Author: BSS9395
Update: 2022-05-20T17:54:00+08@China-Shanghai+08
Design: C# Attribute: DebuggerStepThrough
*/

using System;
using System.Diagnostics;

class CS_DebuggerStepThrough {
    int _value = 1;
    public static void Main(string[] args) {
        CS_DebuggerStepThrough through = new CS_DebuggerStepThrough();

        Console.WriteLine(through._value);
        through._DebuggerStepThrough();
        Console.WriteLine(through._value);
    }
    int _Value {
        get {
            return _value;
        }
        set {
            _value = _value * 2;
            _value += value;
        }
    }

    [DebuggerStepThrough]
    public void _DebuggerStepThrough() {
        _Value += 1;
    }
}
