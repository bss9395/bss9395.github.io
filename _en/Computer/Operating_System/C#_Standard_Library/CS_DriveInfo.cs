/* CS_DriveInfo.cs
Author: BSS9395
Update: 2022-04-23T22:12:00+08@China-Shanghai+08
Design: C# Standard Library: DriveInfo
*/

using System;
using System.IO;

class CS_DriveInfo {
    public static void Main(string[] args) {
        DriveInfo driveinfo = new DriveInfo("C");
        // _DriveInfo(driveinfo);
        _GetDrives();
    }

    public static void _DriveInfo(DriveInfo driveinfo) {
        long size = 0;
        Console.WriteLine("========================================");
        Console.WriteLine("drive name = {0}", driveinfo.Name);
        Console.WriteLine("drive type = {0}", driveinfo.DriveType);
        Console.WriteLine("drive format = {0}", driveinfo.DriveFormat);
        size = driveinfo.TotalFreeSpace;
        Console.WriteLine("drive free space = {0}B, {1}KB, {2}MB, {3}GB", size, size / 1024, size / 1024 / 1024, size / 1024 / 1024 / 1024);
        size = driveinfo.TotalSize;
        Console.WriteLine("drive total size = {0}B, {1}KB, {2}MB, {3}GB", size, size / 1024, size / 1024 / 1024, size / 1024 / 1024 / 1024);
    }
    public static void _GetDrives() {
        DriveInfo[] drives = DriveInfo.GetDrives();
        foreach (DriveInfo drive in drives) {
            _DriveInfo(drive);
        }
    }
}
