/* CS_foreach.cs
Author: BSS9395
Update: 2022-04-17T18:20:00+08@China-Shanghai+08
Design: C# keyword: foreach
*/

using System;

class CS_foreach {
    public static void Main(string[] args) {
        _foreach();
    }
    public static void _foreach() {
        double[] scores = {
            80, 88, 86, 90, 75.5
        };
        double sum = 0;
        foreach (double score in scores) {
            sum += score;
        }
        double avg = sum / scores.Length;
        Console.WriteLine("sum = {0}", sum);
        Console.WriteLine("avg = {0}", avg);
    }
}

