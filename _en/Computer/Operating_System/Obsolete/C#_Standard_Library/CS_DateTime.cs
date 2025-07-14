/* CS_DateTime.cs
Author: BSS9395
Update: 2022-04-17T18:20:00+08@China-Shanghai+08
Design: C# Standary Library: DateTime
*/

using System;

class CS_DateTime {
    public static void Main(string[] args) {
        _DateTime();
        _TimeSpan();
    }
    public static void _DateTime() {
        // DateTime datetime = new DateTime();
        DateTime datetime = DateTime.Now;
        Console.WriteLine("当前日期：{0}-{1}-{2}T{3}:{4}:{5}", datetime.Year, datetime.Month, datetime.Day, datetime.Hour, datetime.Minute, datetime.Second);
        Console.WriteLine("当前年内天数：{0}", datetime.DayOfYear);
        datetime = datetime.AddDays(28);
        Console.WriteLine("28天后的日期：{0}-{1}-{2}T{3}:{4}:{5}", datetime.Year, datetime.Month, datetime.Day, datetime.Hour, datetime.Minute, datetime.Second);
    }
    public static void _TimeSpan() {
        DateTime now = DateTime.Now;
        DateTime future = new DateTime(2022, 4, 22);
        TimeSpan timespan = -(future - now);
        Console.WriteLine("间隔天数：{0}", timespan.Days);
    }
}

