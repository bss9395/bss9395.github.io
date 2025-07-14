/* CS_Parallel_ForEach.cs
Author: BSS9395
Update: 2022-06-04T10:50:00+08@China-Shanghai+08
Design: C# Standard Library: Parallel.ForEach()
*/

using System;
using System.Threading.Tasks;
class CS_Parallel_ForEach {
    public static void Main(String[] args) {
        CS_Parallel_ForEach cs_parallel = new CS_Parallel_ForEach();
        cs_parallel._Parallel_For();
        cs_parallel._Parallel_ForEach();
    }
    public const int _numb = 100;
    public double[] _square = new double[_numb];
    public void _Parallel_For() {
        Parallel.For(0, _numb, (i) => {
            _square[i] = i * i;
            Console.WriteLine($"the square of {i} is {_square[i]}");
        });
    }
    public String[] _word = new String[] {
        "We", "hold", "these", "truths", "to", "be", "self-evident", "that", "all", "men", "are", "created", "equal"
    };
    public void _Parallel_ForEach() {
        Parallel.ForEach(_word, (word) => {
            Console.WriteLine($"{word} has {word.Length} letters.");
        });
    }
}
