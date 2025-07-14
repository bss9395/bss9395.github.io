/* CS_try.cs
Author: BSS9395
Update: 2022-05-01T17:40:00+08@China-Shanghai+08
Design: C# keyword: try
*/

using System;

class CS_try {
    public static void Main(string[] args) {
        _try();
    }
    public static void _try() {
        try {
            // return;
            // string text = "4321";
            string text = "9876543210";
            // string text = "dcba";
            // short number = short.Parse(text);
            char ch = text[12];
            return;
        } catch (FormatException exception) {
            Console.WriteLine("{0}", exception);
        } catch (OverflowException exception) {
            Console.WriteLine("{0}", exception);
        } catch (IndexOutOfRangeException exception) {
            Console.WriteLine($"exception: {exception}");
            Console.WriteLine($"exception.Message: {exception.Message}");
            Console.WriteLine($"exception.StackTrace: {exception.StackTrace}");
            Console.WriteLine($"exception.Source: {exception.Source}");
        } catch (Exception exception) {
            Console.WriteLine("{0}", exception);
        } finally {
            // MessageBox.Show("in finally-block.");
            Console.WriteLine("in finally-block.");
        }
    }
}
