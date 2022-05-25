/* CS_Event.cs
Author: BSS9395
Update: 2022-05-25T12:08:00+08@China-Shanghai+08
Design: C# Keyword: event
*/

using System;
using System.Reflection;

class Args : EventArgs {
    public int _value = 0;
}

class Publisher {
    public delegate void Custom_Handler();
    public event Custom_Handler _custom_handler = null;
    public event EventHandler _event_handler = null;
    public event EventHandler<Args> _args_handler = null;

    public void _Trigger() {
        for (int i = 1; i < 100; i += 1) {
            Args args = new Args();

            if (i % 12 == 0) {
                if (_custom_handler != null) {
                    _custom_handler();
                }
                if (_args_handler != null) {
                    args._value = i;
                    _args_handler(this, args);
                }
            }
        }
    }

    public void _Event_Trigger() {
        _event_handler(this, null);
    }
}

class Subscriber {
    public int _value = 0;

    public Subscriber() {

    }
    public Subscriber(Publisher incrementer) {
        incrementer._custom_handler += _Increment;
    }

    public void _Increment() {
        _value += 1;
    }
    public void _Increment(object source, Args args) {
        Console.WriteLine($"in {source} at {args._value}");
        _value += 1;
    }

    public void _Func1(object obj, EventArgs args) {
        Console.WriteLine($"{nameof(_Func1)}");
    }
    public void _Func2(object obj, EventArgs args) {
        Console.WriteLine($"{nameof(_Func2)}");
    }
}


class Datum {
    public delegate void Dele_Event();
    public event Dele_Event _event_buy;
    public Dele_Event _dele_buy;
    public static void _Buy_Meat() {
        Console.WriteLine("{0}.{1}", typeof(Datum).FullName, MethodBase.GetCurrentMethod().Name);
    }
    public static void _Buy_Vegetable() {
        Console.WriteLine("{0}.{1}", typeof(Datum).FullName, MethodBase.GetCurrentMethod().Name);
    }
    public static void _Buy_Fruit() {
        Console.WriteLine("{0}.{1}", typeof(Datum).FullName, MethodBase.GetCurrentMethod().Name);
    }
    public void _Invoke_Event() {
        _event_buy();
    }
}

class CS_event {
    public static void Main() {
        // _Custom_Event();
        // _Remove_Event();
        // _Args_Event();
        _Delegate();
    }
    public static void _Custom_Event() {
        Publisher publisher = new Publisher();
        Subscriber subscriber = new Subscriber(publisher);

        publisher._Trigger();
        Console.WriteLine($"subscriber._value = {subscriber._value}");
    }
    public static void _Remove_Event() {
        Publisher publisher = new Publisher();
        Subscriber subscriber = new Subscriber();

        publisher._event_handler += subscriber._Func1;
        publisher._event_handler += subscriber._Func2;
        publisher._Event_Trigger();
        publisher._event_handler -= subscriber._Func2;
        publisher._Event_Trigger();
    }
    public static void _Args_Event() {
        Publisher publisher = new Publisher();
        Subscriber subscriber = new Subscriber(publisher);

        publisher._Trigger();
        Console.WriteLine($"subscriber._value = { subscriber._value }");
    }
    public static void _Delegate() {
        Datum datum = new Datum();
        datum._event_buy += Datum._Buy_Meat;
        datum._event_buy += Datum._Buy_Vegetable;
        datum._event_buy += Datum._Buy_Fruit;
        datum._Invoke_Event();
        Console.WriteLine("========================================");
        datum._dele_buy += Datum._Buy_Meat;
        datum._dele_buy += Datum._Buy_Vegetable;
        datum._dele_buy += Datum._Buy_Fruit;
        datum._dele_buy();
    }
}