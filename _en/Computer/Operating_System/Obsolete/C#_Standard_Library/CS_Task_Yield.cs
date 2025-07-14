/* CS_Task_Yield.cs
Author: BSS9395
Update: 2022-06-03T14:36:00+08@China-Shanghai+08
Design: C# Standard Library: Task.Yield();
*/

using System;
using System.Threading.Tasks;

class CS_Task_Yield {
    public static void Main(String[] args) {
        Task<int> sum = CS_Task_Yield._Accumulate(1_000_000);
        _Workload(100_000);
        _Workload(100_000);
        Console.WriteLine($"in Main()");
        _Workload(100_000);
        _Workload(100_000);
        Console.WriteLine($"sum == { sum.Result }");
    }

    public static async Task<int> _Accumulate(int number) {
        int sum = 0;
        for (int i = 0; i < number; i++) {
            sum += i;
            if (i % 1000 == 0) {
                await Task.Yield();
            }
        }
        return sum;
    }

    public static void _Workload(int number) {
        for (int i = 0; i < number; i++) {
            ;
        }
    }
}
