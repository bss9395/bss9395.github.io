/* CS_Exeption.cs
Author: BSS9395
Update: 2022-05-01T17:40:00+08@China-Shanghai+08
Design: C# Standard Library: Exception
*/

using System;

class CS_Exception {
    class Custom : Exception {
        public Custom(string record)
            : base(record) {

        }
    }
    public static void Main(string[] args) {
        _Exception();
    }
    public static void _Exception() {
        try {
            string text = "4321";
            int number = int.Parse(text);
            if (128 < number) {
                throw new Custom("number exceeds range.");
            }
        } catch (Custom exception) {
            Console.WriteLine("{0}", exception);
        } catch (Exception exception) {
            Console.WriteLine("{0}", exception);
        } finally {
            // MessageBox.Show("in finally-block.");
            Console.WriteLine("in finally-block.");
        }
    }
}
