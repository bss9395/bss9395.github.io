/* CS_async.cs
Author: BSS9395
Update: 2022-06-02T16:14:00+08@China-Shanghai+08
Design: C# Keyword: async
*/

using System;
using System.Net;
using System.Diagnostics;
using System.Threading.Tasks;

class CS_await {
    Stopwatch watch = new Stopwatch();
    public static void Main(String[] args) {
        CS_await cs_await = new CS_await();
        cs_await._Run();
    }
    public void _Run() {
        watch.Start();
        String url_0 = "http://www.baidu.com";
        String url_1 = "http://www.illustratedcsharp.com";
        Task<int> leng_0 = _Download(url_0);
        Task<int> leng_1 = _Download(url_1);
        _Workload();
        _Workload();
        _Workload();
        _Workload();
        Console.WriteLine($"length of {url_0} is {leng_0.Result}");
        Console.WriteLine($"length of {url_1} is {leng_1.Result}");
    }
    public async Task<int> _Download(String url) {
        WebClient client = new WebClient();
        Console.WriteLine($"start downloading {url} at {watch.ElapsedMilliseconds}ms");
        string site = await client.DownloadStringTaskAsync(url);
        Console.WriteLine($"stop downloading {url} at {watch.ElapsedMilliseconds}ms");
        return site.Length;
    }
    public void _Workload() {
        for (long i = 0; i < 6_000_000; i += 1) {
            ;
        }
        Console.WriteLine($"stop counting at {watch.ElapsedMilliseconds}ms");
    }
}
