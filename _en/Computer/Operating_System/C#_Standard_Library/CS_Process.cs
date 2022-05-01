/* CS_Process.cs
Author: BSS9395
Update: 2022-05-01T22:14:00+08@China-Shanghai+08
Design: C# Standard Library: Process
*/

using System;
using System.Diagnostics;

class CS_Process {
    public static void Main(string[] args) {
        _Process();
        _Kill();
    }
    public static void _Process() {
        Console.WriteLine("========================================");
        Process[] processes = Process.GetProcesses();
        foreach (Process process in processes) {
            Console.WriteLine("{0}", process.ProcessName);
        }
    }
    public static void _Kill() {
        Console.WriteLine("========================================");
        try {
            string process_name = "mspaint";
            Process[] processes = Process.GetProcessesByName(process_name);
            foreach (Process process in processes) {
                if (process.HasExited == false) {
                    process.Kill();
                }
            }
        } catch (Exception exception) {
            Console.WriteLine("{0}", exception);
        }
    }
}
