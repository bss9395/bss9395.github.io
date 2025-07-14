/* CS_yield.cs
Author: BSS9395
Update: 2022-06-01T17:21:00+08@China-Shanghai+08
Design: C# Keyword: yield
*/

using System;
using System.Collections.Generic;

class CS_yield {
    public IEnumerator<String> GetEnumerator() {
        //yield return "red";
        //yield return "yellow";
        //yield return "blue";

        return _Yield_Color_1();

        //return _Yield_Color_2().GetEnumerator();
    }
    public IEnumerator<String> _Yield_Color_1() {
        yield return "red";
        yield return "yellow";
        yield return "blue";
    }
    public IEnumerable<String> _Yield_Color_2() {
        yield return "red";
        yield return "yellow";
        yield return "blue";
    }
    public static void Main(String[] args) {
        CS_yield cs_yield = new CS_yield();
        foreach (String color in cs_yield) {
            Console.WriteLine($"{color}");
        }
        Console.WriteLine();
        foreach (String color in cs_yield._Yield_Color_2()) {
            Console.WriteLine($"{color}");
        }
    }
}
