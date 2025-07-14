/* CA_Task.cs
Author: BSS9395
Update: 2022-06-02T17:20:00+08@China-Shanghai+08
Design: C# Standard Library: Task
*/

using System;
using System.Threading.Tasks;

class CS_Task {
    public static void Main(String[] args) {
        int number = 109;
        Task task = _Task_Async(number);
        task.Wait();

        ////////////////////////////////////////////////////////////////////////

        Task<bool> is_prime = _Task_bool_Async(number);
        Console.WriteLine($"{number} is a prime: {is_prime.Result}");

        ////////////////////////////////////////////////////////////////////////

        //Task exception = _Exception_Async();
        //exception.Wait();
        //Console.WriteLine($"Task Status : { exception.Status }");
        //Console.WriteLine($"Task IsFaulted: { exception.IsFaulted }");
    }
    public static async Task _Task_Async(int number) {
        bool is_prime = await Task.Run(() => {
            return _Prime(number);
        });
        Console.WriteLine($"{number} is a prime: {is_prime}");
    }

    public static async Task<bool> _Task_bool_Async(int number) {
        bool is_prime = await Task.Run(() => {
            return _Prime(number);
        });
        return is_prime;
    }
    static async Task _Exception_Async() {
        try {
            await Task.Run(() => {
                throw new Exception();
            });
        } catch (Exception) {
            Console.WriteLine("Exception in BadAsync");
        }
    }
    public static bool _Prime(int number) {
        int sqrt = (int)Math.Sqrt(number);
        for (int i = 2; i <= sqrt; i += 1) {
            if (number % i == 0) {
                return false;
            }
        }
        return true;
    }
}
