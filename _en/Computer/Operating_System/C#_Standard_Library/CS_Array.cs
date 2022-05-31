/* CS_Array.cs
Author: BSS9395
Update: 2022-04-17T18:20:00+08@China-Shanghai+08
Design: C# Standary Library: Array
*/

using System;

class CS_Array {
    public static void Main(string[] args) {
        //_Array();
        //_Jagged();
        // _Sort();
        _Clone();
    }

    public static void _Array() {
        double[,] points = new double[3, 2] { { 90, 80 }, { 100, 89 }, { 88.5, 86 } };
        Console.WriteLine("points.Length = {0}", points.Length);

        ////////////////////////////////////////////////////////////////////////

        for (long row = 0; row < points.GetLength(0);) {
            if (0 == row) {
                Console.Write("{ ");
            } else if (1 <= row) {
                Console.Write(", ");
            }
            for (long col = 0; col < points.GetLength(1);) {
                if (0 == col) {
                    Console.Write("[");
                } else if (1 <= col) {
                    Console.Write(", ");
                }
                Console.Write("{0}", points[row, col]);
                col += 1;
                if (col == points.GetLength(1)) {
                    Console.Write("]");
                }
            }
            row += 1;
            if (row == points.GetLength(0)) {
                Console.Write(" }");
            }
        }
        Console.WriteLine();

        ////////////////////////////////////////////////////////////////////////

        if (1 <= points.GetLength(0)) {
            Console.Write("{ ");
            for (long row = 0; row < points.GetLength(0); row += 1) {
                if (1 <= row) {
                    Console.Write(", ");
                }
                if (1 <= points.GetLength(1)) {
                    Console.Write("[");
                    for (long col = 0; col < points.GetLength(1); col += 1) {
                        if (1 <= col) {
                            Console.Write(", ");
                        }
                        Console.Write("{0}", points[row, col]);
                    }
                    Console.Write("]");
                }
            }
            Console.Write(" }");
        }
        Console.WriteLine();
    }

    public static void _Jagged() {
        double[][] jagged = new double[3][];
        jagged[0] = new double[] { 1.0, 2.0 };
        jagged[1] = new double[] { 3.0, 4.0, 5.0 };
        jagged[2] = new double[] { 6.0, 7.0, 8.0, 9.0 };

        ////////////////////////////////////////////////////////////////////////

        for (long row = 0; row < jagged.Length;) {
            if (0 == row) {
                Console.Write("{ ");
            } else if (1 <= row) {
                Console.Write(", ");
            }
            for (long col = 0; col < jagged[row].Length;) {
                if (0 == col) {
                    Console.Write("[");
                } else if (1 <= col) {
                    Console.Write(", ");
                }
                Console.Write("{0}", jagged[row][col]);
                col += 1;
                if (col == jagged[row].Length) {
                    Console.Write("]");
                }
            }
            row += 1;
            if (row == jagged.Length) {
                Console.Write(" }");
            }
        }
        Console.WriteLine();

        ////////////////////////////////////////////////////////////////////////

        if (1 <= jagged.Length) {
            Console.Write("{ ");
            for (long row = 0; row < jagged.Length; row += 1) {
                if (1 <= row) {
                    Console.Write(", ");
                }
                if (1 <= jagged[row].Length) {
                    Console.Write("[");
                    for (long col = 0; col < jagged[row].Length; col += 1) {
                        if (1 <= col) {
                            Console.Write(", ");
                        }
                        Console.Write("{0}", jagged[row][col]);
                    }
                    Console.Write("]");
                }
            }
            Console.Write(" }");
        }
        Console.WriteLine();
    }

    public static void _Sort() {
        double[] array = { 5, 1, 7, 2, 3 };
        for (long i = 0; i < array.Length; i += 1) {
            for (long j = array.Length - 1; i < j; j -= 1) {
                if (array[j - 1] < array[j]) {
                    double swap = array[j - 1];
                    array[j - 1] = array[j];
                    array[j] = swap;
                }
            }
        }

        foreach (double elem in array) {
            Console.Write("{0} ", elem);
        }
        Console.WriteLine();

        ////////////////////////////////

        Array.Sort(array);
        foreach (double elem in array) {
            Console.Write("{0} ", elem);
        }
        Console.WriteLine();
    }

    class Datum {
        public double _value = 0.0;
        public Datum(double value) {
            _value = value;
        }
    }
    public static void _Clone() {
        double[] value_array = new double[3] {
            1.0, 2.0, 3.0
        };

        Datum[] reference_array = new Datum[3] {
            new Datum(1.0), new Datum(2.0), new Datum(3.0)
        };

        double[] clone_value_array = (double[])value_array.Clone();
        for (int i = 0; i < clone_value_array.Length; i += 1) {
            clone_value_array[i] += 10.0;
            Console.WriteLine($"value_array[{i}] == {value_array[i]}");
        }

        Datum[] clone_reference_array = (Datum[])reference_array.Clone();
        for (int i = 0; i < clone_reference_array.Length; i += 1) {
            clone_reference_array[i]._value += 10.0;
            Console.WriteLine($"reference_array[{i}]._value == {reference_array[i]._value}");
        }
    }
}
