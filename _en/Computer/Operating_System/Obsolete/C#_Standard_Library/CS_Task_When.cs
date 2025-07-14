/* CS_Task_When.cs
Author: BSS9395
Update: 2022-06-03T13:08:00+08@China-Shanghai+08
Design: C# Standard Library: Task.WhenAll()
*/

using System;
using System.Collections.Generic;
using System.Net;
using System.Threading.Tasks;

class CS_Task_When {
    public static void Main(String[] args) {
        CS_Task_When ds = new CS_Task_When();
        ds._Run();
    }
    public void _Run() {
        Task<bool> tasks = _Download("http://www.baidu.com", "http://www.illustratedcsharp.com");
        Console.WriteLine("tasks {0}finished", tasks.IsCompleted ? "" : "not ");
        Console.WriteLine("tasks result == {0}", tasks.Result);                   // note: wait all tasks finished.
    }
    public async Task<bool> _Download(string url_0, string url_1) {
        WebClient client_0 = new WebClient();
        WebClient client_1 = new WebClient();
        Task<string> task_0 = client_0.DownloadStringTaskAsync(url_0);
        Task<string> task_1 = client_1.DownloadStringTaskAsync(url_1);

        List<Task<string>> tasks = new List<Task<string>> {
            task_0, task_1
        };
        // await Task.WhenAny(tasks);
        await Task.WhenAll(tasks);
        Console.WriteLine("task_0 {0}finished", task_0.IsCompleted ? "" : "not ");
        Console.WriteLine("task_1 {0}finished", task_1.IsCompleted ? "" : "not ");

        return (task_0.IsCompleted && task_1.IsCompleted);
    }

}
