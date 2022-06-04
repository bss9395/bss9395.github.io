/* CS_Parallel_For.cs
Author: BSS9395
Update: 2022-06-04T10:50:00+08@China-Shanghai+08
Design: C# Standard Library: Parallel.For()
*/

using System;
using System.Threading.Tasks;
class CS_Parallel_For {
    public static void Main(String[] args) {
        CS_Parallel_For cs_parallel_for = new CS_Parallel_For();
        cs_parallel_for._Parallel_For();
    }
    public const int _numb = 100;
    public double[] _square = new double[_numb];
    public void _Parallel_For() {
        Parallel.For(0, _numb, (i) => {
            _square[i] = i * i;
            Console.WriteLine($"the square of {i} is {_square[i]}");
        });
    }
}
