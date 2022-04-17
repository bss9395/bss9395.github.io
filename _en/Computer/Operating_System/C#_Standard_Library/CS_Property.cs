/* CS_Property.cs
Author: BSS9395
Update: 2022-04-14T23:11:00+08@China-Shanghai+08
Design: C# Feature: Property
Encode: UTF-8
*/

using System;
using System.Diagnostics;

class CS_Property {
    public static void Main(string[] args) {
        CS_Property property = new CS_Property();
        property._id = "20220414";
        Console.WriteLine("property = {0}", property._id);
    }

    protected string __id = "";
    public string _id {
        get {
            return __id;
        }
        protected set {
            __id = value;
        }
    }
}
