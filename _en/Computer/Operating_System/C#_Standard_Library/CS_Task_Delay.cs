/* CS_Task_Delay.cs
Author: BSS9395
Update: 2022-06-03T13:19:00+08@China-Shanghai+08
Design: C# Standard Library: Task.Delay()
*/

using System;
using System.Diagnostics;
using System.Threading.Tasks;

class CS_Task_Delay {
    Stopwatch watch = new Stopwatch();
    public static void Main(String[] args) {
        CS_Task_Delay task = new CS_Task_Delay();
        Console.WriteLine("before task");
        task._Task();
        Console.WriteLine("after task");
        Console.ReadLine();
    }

    public async void _Task() {
        watch.Start();
        Console.WriteLine($"before Task.Delay(): {watch.ElapsedMilliseconds}ms");
        await Task.Delay(1000);
        Console.WriteLine($"after Task.Delay() : {watch.ElapsedMilliseconds}ms");
    }

}
