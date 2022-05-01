/* CS_Trace.cs
Author: BSS9395
Update: 2022-05-01T17:40:00+08@China-Shanghai+08
Design: C# Standard Library: Trace
*/

using System.Diagnostics;

class CS_Trace {
    public static void Main(string[] args) {
        // _Debug();  // note: start Debugging.
        _Trace();
    }
    public static void _Debug() {
        string[] array = new string[5];
        Debug.WriteLine("running...");
        for (int i = 0; i < array.Length; i += 1) {
            array[i] = i.ToString();
            Debug.WriteLine("array[{0}] == {1}", i, array[i]);
        }
        Debug.WriteLine("stopped...");
    }
    public static void _Trace() {
        string[] array = new string[5];
        Trace.WriteLine("running...");
        for (int i = 0; i < array.Length; i += 1) {
            array[i] = i.ToString();
            Trace.WriteLine(string.Format("array[{0}] == {1}", i, array[i]));
        }
        Trace.WriteLine("stopped...");
    }
}
