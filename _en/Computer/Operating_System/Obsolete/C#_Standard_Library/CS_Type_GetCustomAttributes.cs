/* CS_Type_GetCustomAttributes.cs
Author: BSS9395
Update: 2022-06-05T17:42:00+08@China-Shanghai+08
Design: C# Standard Library: Type.GetCustomAttributes()
*/

using System;

class CS_Type_GetCustomAttributes {
    [AttributeUsage(AttributeTargets.Class)]
    sealed class DecorateAttribute : Attribute {
        public String _description = "";
        public String _version = "";
        public String _reviewer = "";
        public DecorateAttribute(String description, String version) {
            _description = description;
            _version = version;
        }
    }

    [Decorate("custom", "0.0.1")]
    class Custom {

    }
    public static void Main(String[] args) {
        _IsDefined();
        // _GetCustomAttributes();
    }
    public static void _IsDefined() {
        Custom custom = new Custom();
        Type type = custom.GetType();
        if (type.IsDefined(typeof(DecorateAttribute), false)) {
            Console.WriteLine($"{type.Name} has Attribute {nameof(DecorateAttribute)}");
        }
    }
    public static void _GetCustomAttributes() {
        Type type = typeof(Custom);
        object[] attr = type.GetCustomAttributes(false);
        foreach (Attribute attribute in attr) {
            DecorateAttribute decorate = attribute as DecorateAttribute;
            if (decorate != null) {
                Console.WriteLine($"description: {decorate._description}");
                Console.WriteLine($"version    : {decorate._version}");
                Console.WriteLine($"reviewer   : {decorate._reviewer}");
            }
        }
    }
}
