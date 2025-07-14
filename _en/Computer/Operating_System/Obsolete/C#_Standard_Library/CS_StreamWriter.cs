/* CS_StreamWriter.cs
Author: BSS9395
Update: 2022-04-26T15:18:00+08@China-Shanghai+08
Design: C# Standard Library: StreamWriter
*/

using System;
using System.IO;

class CS_StreamWriter {
    public static void Main(string[] args) {
        const string path = "E:/temp/code.txt";
        _StreamWriter(path);
        // _ReadLine(path);
        _ReadToEnd(path);
    }
    public static void _StreamWriter(string path) {
        StreamWriter streamWriter = new StreamWriter(path);
        streamWriter.WriteLine("Hello, world!");
        streamWriter.WriteLine("2022-04-26");
        streamWriter.Flush();
        streamWriter.Close();
    }
    public static void _ReadLine(string path) {
        StreamReader streamReader = new StreamReader(path);
        while (streamReader.EndOfStream == false) {
            string text = streamReader.ReadLine();
            Console.WriteLine(text);
        }
        streamReader.Close();
    }
    public static void _ReadToEnd(string path) {
        StreamReader streamReader = new StreamReader(path);
        string text = streamReader.ReadToEnd();
        Console.Write(text);
        streamReader.Close();
    }
}
