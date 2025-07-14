/* CS_Directory.cs
Author: BSS9395
Update: 2022-04-24T10:04:00+08@China-Shanghai+08
Design: C# Standard Library: Directory
*/

using System.IO;

class CS_Directory {
    public static void Main(string[] args) {
        const string path = "E:/temp/dir 1/dir 11";
        _Directory(path);
    }
    public static void _Directory(string path) {
        if (Directory.Exists(path)) {
            Directory.Delete(path);
        } else {
            Directory.CreateDirectory(path);
        }
    }
}
