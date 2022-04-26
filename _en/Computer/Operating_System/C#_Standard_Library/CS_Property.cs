/* CS_Property.cs
Author: BSS9395
Update: 2022-04-14T23:11:00+08@China-Shanghai+08
Design: C# Feature: Property
Encode: UTF-8
*/

using System;
using System.Reflection;

class CS_Property {
    public static void Main(string[] args) {
        _Property();
    }
    public static void _Property() {
        CS_Property property = new CS_Property();
        property._id = "20220414";
        Console.WriteLine("_id = {0}, __id = {1}", property._id, property.__id);

        property._id = property.__id;   // note: probably OK.
        Console.WriteLine("_id = {0}, __id = {1}", property._id, property.__id);
    }

    public string __id = "";
    public string _id {
        get {
            Console.WriteLine("{0}.{1}", typeof(CS_Property).FullName, MethodBase.GetCurrentMethod().Name);

            // _id = __id;                 // note: propably OK.            
            // __id = _id;                 // note: infinite loop.
            return __id;
        }
        protected set {
            Console.WriteLine("{0}.{1}", typeof(CS_Property).FullName, MethodBase.GetCurrentMethod().Name);
            __id = value;

            // _id = __id;                 // note: infinite loop.            
            // __id = _id;                 // note: propably OK.
        }
    }
}
