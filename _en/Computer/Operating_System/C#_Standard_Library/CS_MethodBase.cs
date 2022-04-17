/* CS_MethodBase.cs
Author: BSS9395
Update: 2022-04-17T18:20:00+08@China-Shanghai+08
Design: C# Standary Library: MethodBase
*/

using System;
using System.Reflection;

public class MethodBase {
    public static void Main() {
        Value._nameof();
        Value._typeof();
        Value._MethodBase();
    }
    class Value {
        public static void _nameof() {
            Console.WriteLine("{0}.{1}", nameof(Value), MethodBase.GetCurrentMethod().Name);
        }
        public static void _typeof() {
            Console.WriteLine("{0}.{1}", typeof(Value).FullName, MethodBase.GetCurrentMethod().Name);
        }
        public static void _MethodBase() {
            Console.WriteLine("{0}.{1}", typeof(Value).FullName, MethodBase.GetCurrentMethod().Name);
        }
    }
}
