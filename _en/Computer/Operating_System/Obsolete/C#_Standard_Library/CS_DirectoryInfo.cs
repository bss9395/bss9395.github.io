/* CS_DirectoryInfo.cs
Author: BSS9395
Update: 2022-04-23T22:46:00+08@China-Shanghai+08
Design: C# Standard Library: DirectoryInfo
*/

using System;
using System.Collections.Generic;
using System.IO;

class CS_DirectoryInfo {
    public static void Main(string[] args) {
        const string path = "E:/temp";
        _CreateSubdirectory(path);
        _EnumerateDirectories(path);
        _Delete(path);
    }
    public static void _CreateSubdirectory(string path) {
        DirectoryInfo directoryInfo = new DirectoryInfo(path);
        directoryInfo.Create();
        directoryInfo.CreateSubdirectory("dire 1/dire 11");
        directoryInfo.CreateSubdirectory("dire 2");
    }
    public static void _EnumerateDirectories(string path) {
        void Traversal(DirectoryInfo directoryInfo, string tab = "=>") {
            IEnumerable<DirectoryInfo> directories = directoryInfo.EnumerateDirectories();
            foreach (DirectoryInfo directory in directories) {
                Console.WriteLine("{0}{1}", tab, directory.Name);
                Traversal(directory, "==" + tab);
            }
        }
        Traversal(new DirectoryInfo(path));
    }
    public static void _Delete(string path) {
        DirectoryInfo directoryInfo = new DirectoryInfo(path);
        directoryInfo.Delete(true);
    }
}

