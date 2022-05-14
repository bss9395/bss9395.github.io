/* CS_Predicate.cs
Author: BSS9395
Update: 2022-05-13T22:50:00+08@China-Shanghai+08
Design: C# Language Feature: Predicate
*/
class CS_Predicate {
    public static void Main(String[] args) {
        _Test_Predicate();
    }
    public static bool IsOdd(int x) {
        return (x % 2 == 1);
    }
    public static void _Test_Predicate() {
        int[] numbers = new int[] { 3, 4, 5, 6, 7, 9 };
        int count = 0;


        Func<int, bool> lamb = new Func<int, bool>(IsOdd);
        count = numbers.Count(lamb);
        Console.WriteLine("count = {0}", count);


        count = numbers.Count(IsOdd);
        Console.WriteLine("count = {0}", count);


        count = numbers.Count(x => x % 2 == 1);
        Console.WriteLine("count = {0}", count);


        Func<int, bool> dele = delegate (int x) {
            return (x % 2 == 1);
        };
        count = numbers.Count(dele);
        Console.WriteLine("count = {0}", count);
    }
}
