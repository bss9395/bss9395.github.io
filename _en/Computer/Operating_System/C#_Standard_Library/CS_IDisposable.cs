/* CS_IDisposable.cs
Author: BSS9395
Update: 2022-05-21T20:26:00+08@China-Shanghai+08
Design: C# Interface: IDisposable
*/

using System;

class Destruct : IDisposable {
    bool _disposed = false;
    ~Destruct() {
        Dispose(false);
    }
    public void Dispose() {
        Dispose(true);
        GC.SuppressFinalize(this);
    }
    protected virtual void Dispose(bool disposing) {
        if (_disposed == false) {
            if (disposing == true) {
                Console.WriteLine("release managed resources.");
            }
            Console.WriteLine("release unmanaged resources.");
            _disposed = true;
        }
    }
}

class CS_Dispose {
    public static void Main(String[] args) {
        _IDisposable();
    }
    public static void _IDisposable() {
        Console.WriteLine("before using");
        using (Destruct destruct = new Destruct()) {
            Console.WriteLine("in using");
        }
        Console.WriteLine("after using");
    }
}
