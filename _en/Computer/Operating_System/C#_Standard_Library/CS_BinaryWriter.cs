/* CS_BinaryWriter.cs
Author: BSS9395
Update: 2022-04-26T20:28:00+08@China-Shanghai+08
Design: C# Standard Library: BinaryWriter
*/

using System;
using System.IO;

class CS_BinaryWriter {
    public static void Main(string[] args) {
        const string path = "E:/temp/code.txt";
        _BinaryWriter(path);
        _BinaryReader(path);
    }
    public static void _BinaryWriter(string path) {
        FileStream fileStream = new FileStream(path, FileMode.Open, FileAccess.Write);
        BinaryWriter binaryWriter = new BinaryWriter(fileStream);
        binaryWriter.Write((short)2);
        string text = "abc";
        binaryWriter.Write(text);
        binaryWriter.Flush();
        binaryWriter.Close();
    }
    public static void _BinaryReader(string path) {
        FileStream fileStream = new FileStream(path, FileMode.Open, FileAccess.ReadWrite);
        BinaryReader binaryReader = new BinaryReader(fileStream);
        Console.WriteLine("{0}", binaryReader.ReadInt16());
        Console.WriteLine("{0}", binaryReader.ReadString());
        binaryReader.Close();
        fileStream.Close();
    }
}
