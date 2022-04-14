/* Diamond.cs
Author: BSS9395
Update: 2022-04-14T23:06:00+08@China-Guangdong+08
Design: Diamond pattern
Encode: UTF-8
*/

using System;
using System.Diagnostics;

class _Diamond {
    static void Main(string[] args) {
        Diamond();
    }
    static void Diamond() {
        long rows = 2 * 3 + 1; // note: a diamond has odd number rows.
        for (long row = 0; row < rows; row += 1) {
            long lev = (row <= rows / 2) ? row : (rows - 1 - row);
            long idx = rows / 2 - lev;
            long cols = 2 * lev + 1;
            for (long col = 0; col < idx; col += 1) {
                Console.Write("_");
            }
            for (long col = 0; col < cols; col += 1) {
                Console.Write("*");
            }
            Console.WriteLine();
        }
    }
}
