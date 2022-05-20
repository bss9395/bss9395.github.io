/* CS_Obsolete.cs
Author: BSS9395
Update: 2022-05-20T16:11:00+08@China-Shanghai+08
Design: C# Attribute: Obsolete
*/

using System;

class CS_Obsolete {
    public static void Main(string[] args) {
        _Printf();
        // _Obsolete();
    }

    [Obsolete("Use method _Print.")]
    public static void _Printf() {
        Console.WriteLine(nameof(_Printf));
    }

    [Obsolete("Use method _Print.", true)]
    public static void _Obsolete() {
        Console.WriteLine(nameof(_Obsolete));
    }
}
