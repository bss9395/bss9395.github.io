/* CS_Random.cs
Author: BSS9395
Update: 2022-04-17T18:20:00+08@China-Shanghai+08
Design: C# Standary Library: Random
*/

using System;

class CS_Random {
    public static void Main(string[] args) {
        _Random();
    }

    public static void _Random() {
        Random random = new Random();
        Console.WriteLine("产生一个[0, 10)内的整数：{0}", random.Next(0, 10));
        Console.WriteLine("产生一个[0.0, 1.0)内的小数：{0}", random.NextDouble());

        byte[] buffer = new byte[10];
        random.NextBytes(buffer);
        Console.WriteLine("产生一个随机字节数组：");
        if (1 <= buffer.Length) {
            Console.Write("{0}", buffer[0]);
            for (long i = 1; i < buffer.Length; i += 1) {
                Console.Write(", {0}", buffer[i]);
            }
            Console.WriteLine();
        }
    }
}

