/* CS_FileStream.cs
Author: BSS9395
Update: 2022-04-26T16:21:00+08@China-Shanghai+08
Design: C# Standard Library: FileStream
*/

using System;
using System.IO;
using System.Text;

class CS_FileStream {
    public static void Main(string[] args) {
        const string path = "E:/temp/code.txt";
        _Write(path);
        _Read(path);
    }
    public static void _Write(string path) {
        FileStream fileStream = new FileStream(path, FileMode.Create, FileAccess.ReadWrite, FileShare.ReadWrite);
        string text = "2022-04-26";
        byte[] bytes = Encoding.UTF8.GetBytes(text);
        fileStream.Write(bytes, 0, bytes.Length);
        fileStream.Flush();
        fileStream.Close();
    }
    public static void _Read(string path) {
        FileStream fileStream = new FileStream(path, FileMode.Open, FileAccess.Read);
        byte[] bytes = new byte[fileStream.Length];
        fileStream.Read(bytes, 0, bytes.Length);
        string text = Encoding.UTF8.GetString(bytes);
        Console.WriteLine(text);
        fileStream.Close();
    }
}
