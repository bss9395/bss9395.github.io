/* CS_Queue.cs
Author: BSS9395
Update: 2022-04-17T18:20:00+08@China-Shanghai+08
Design: C# Standary Library: Queue
*/

using System;
using System.Collections;
using System.Diagnostics;

class CS_Queue {
    public static void Main(string[] args) {
        // _Enqueue();
        // _Dequeue();
        // _ToArray();
        _GetEnumerator();
    }
    public static void _Enqueue() {
        Queue queue = new Queue();
        queue.Enqueue("def");
        queue.Enqueue("abc");
        queue.Enqueue("ghi");
        queue.Enqueue(123);
        while (0 < queue.Count) {
            var elem = queue.Dequeue();
            Console.WriteLine("{0} ", elem.ToString());
        }
        Console.WriteLine();
    }
    public static void _Dequeue() {
        Queue queue = new Queue();
        queue.Enqueue("def");
        queue.Enqueue("abc");
        queue.Enqueue("ghi");
        queue.Enqueue(123);
        while (0 < queue.Count) {
            var elem = queue.Dequeue();
            Console.WriteLine("{0} ", elem.ToString());
        }
        Console.WriteLine();
    }
    public static void _ToArray() {
        Queue queue = new Queue();
        queue.Enqueue("def");
        queue.Enqueue("ghi");
        queue.Enqueue("abc");
        object[] array = queue.ToArray();
        foreach (var elem in array) {
            Console.Write("{0} ", elem);
        }
        Console.WriteLine();
    }
    public static void _GetEnumerator() {
        Queue queue = new Queue();
        queue.Enqueue("abc");
        queue.Enqueue("def");
        queue.Enqueue("ghi");
        IEnumerator enumerator = queue.GetEnumerator();
        while (enumerator.MoveNext()) {
            Console.Write("{0} ", enumerator.Current);
        }
        Console.WriteLine();
    }
}
