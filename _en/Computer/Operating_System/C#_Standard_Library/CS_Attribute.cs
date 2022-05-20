/* CS_Attribute.cs
Author: BSS9395
Update: 2022-05-20T21:15:00+08@China-Shanghai+08
Design: C# Language Feature: Attribute
*/

using System;

[AttributeUsage(AttributeTargets.Class | AttributeTargets.Field | AttributeTargets.Method, Inherited = false, AllowMultiple = false)]
sealed class CustomAttribute : System.Attribute {
    public String _description = "";
    public String _version = "";

    public CustomAttribute(String description = "", String version = "") {
        _description = description;
        _version = version;
    }
}


[Custom("class", "0.0")]
class CS_Attribute {
    public static void Main(String[] args) {
        _Attribute();
    }

    [Custom("field", "1.0")]
    public int _value = 0;

    [Custom("method", "2.0")]
    public void _Method() {
        Console.WriteLine($"{nameof(_Method)}");
    }
    public static void _Attribute() {
        CS_Attribute attri = new CS_Attribute();
        Type type = attri.GetType();
        Console.WriteLine($"[Custom]: {type.IsDefined(typeof(CustomAttribute), false)}");

        object[] attributes = type.GetCustomAttributes(false);
        foreach (Attribute attribute in attributes) {
            CustomAttribute custom = attribute as CustomAttribute;
            if (null != custom) {
                Console.WriteLine($"description = {custom._description}");
                Console.WriteLine($"version = {custom._version}");
            }
        }
    }
}
