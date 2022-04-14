/* _Property.cs
Author: BSS9395
Update: 2022-04-14T23:11:00+08@China-Shanghai+08
Design: C# Feature: Property
Encode: UTF-8
*/

using System;
using System.Diagnostics;


class _Property {
    static void Main(string[] args) {
        _Property property = new _Property();
        property._ID = "20220414";
        Console.WriteLine("property = {0}", property._ID);
    }

    protected string __ID = "";
    public string _ID {
        get {
            return __ID;
        }
        protected set {
            __ID = value;
        }
    }
}
