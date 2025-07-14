/* CS_FileInfo.cs
Author: BSS9395
Update: 2022-04-25T00:55:00+08@China-Shanghai+08
Design: C# Standard Library: FileInfo
*/

using System;
using System.IO;
using System.Reflection;

class CS_FileInfo {
    public static void Main(string[] args) {
        const string path = "E:/temp/code.txt";
        const string move = "E:/tmp/code.txt";
        _FileInfo(path, move);
    }
    public static void _FileInfo(string path, string move) {
        Console.WriteLine("{0}.{1}", typeof(CS_FileInfo).Name, MethodBase.GetCurrentMethod().Name);

        FileInfo fileInfo = new FileInfo(path);
        if (fileInfo.Exists == false) {
            fileInfo.Directory.Create();
            fileInfo.Create().Flush();  // note: this file cotains 0 bytes and hasn't been flushed, thus hasn't been created.
        }
        Console.WriteLine("DirectoryName = {0}", fileInfo.DirectoryName);
        Console.WriteLine("Name = {0}", fileInfo.Name);
        Console.WriteLine("IsReadOnly = {0}", fileInfo.IsReadOnly);
        long size = fileInfo.Length;
        Console.WriteLine("Length = {0}B, {1}KB, {2}MB, {3}GB", size, size / 1024, size / 1024 / 1024, size / 1024 / 1024 / 1024);

        FileInfo moveInfo = new FileInfo(move);
        if (moveInfo.Exists == true) {
            moveInfo.Delete();
        } else {
            moveInfo.Directory.Create();
        }
        fileInfo.MoveTo(move);          // note: this file cotains 0 bytes and hasn't been flushed, thus hasn't been created.

        //fileInfo = null;              // note: this is of no use.
        //System.GC.Collect();          // note: this is of no use.
    }
}

