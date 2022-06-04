/* CS_IEnumerator.cs
Author: BSS9395
Update: 2022-06-01T14:57:00+08@China-Shanghai+08
Design: C# Interface: IEnumerator
*/

using System;
using System.Collections;

class CS_IEnumerator {
    public static void Main(String[] args) {
        _IEnumerator();
    }
    public static void _IEnumerator() {
        double[] array = new double[] { 10, 11, 12, 13 };
        IEnumerator enumerator = array.GetEnumerator();
        while (enumerator.MoveNext()) {
            double item = (double)enumerator.Current;
            Console.WriteLine($"item: {item}");
        }
    }
}
