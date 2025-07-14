/* CS_Task_Wait.cs
Author: BSS9395
Update: 2022-06-02T23:32:00+08@China-Shanghai+08
Design: C# Standard Library: Task.WaitAll()
*/

using System;
using System.Diagnostics;
using System.Net;
using System.Threading.Tasks;

class CS_Task_Wait {
    Stopwatch watch = new Stopwatch();
    public static void Main(String[] args) {
        CS_Task_Wait cs_task_wait = new CS_Task_Wait();
        cs_task_wait._Run();
    }
    public void _Run() {
        watch.Start();
        Task<int> task_0 = _Download("http://www.baidu.com");
        Task<int> task_1 = _Download("http://www.illustratedcsharp.com");

        //task_0.Wait();
        Task.WaitAll(task_0, task_1);
        //Task.WaitAny(task_0, task_1);
        Console.WriteLine("task_0 {0}finished.", task_0.IsCompleted ? "" : "not ");
        Console.WriteLine("task_1 {0}finished.", task_1.IsCompleted ? "" : "not ");
    }

    public async Task<int> _Download(String url) {
        WebClient client = new WebClient();
        String site = await client.DownloadStringTaskAsync(url);
        Console.WriteLine($"downloading {url} completed at {watch.Elapsed.TotalMilliseconds}ms");
        return site.Length;
    }
}
