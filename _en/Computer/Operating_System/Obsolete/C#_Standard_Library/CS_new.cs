
using System;

class CS_new {
    class Super {
        public String _value = "Super";
        public static void _Method(String value) {
            Console.WriteLine($"Super._Method: {value}");
        }
    }
    class Derived : Super {
        new public String _value = "Derived";
        new public void _Method(String value) {
            Console.WriteLine($"Derived._Method: {value}");
        }
    }
    public static void Main(String[] args) {
        Derived derived = new Derived();
        derived._Method(derived._value);
    }
}
