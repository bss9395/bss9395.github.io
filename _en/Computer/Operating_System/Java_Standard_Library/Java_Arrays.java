/* Java_Arrays.java
Author: BSS9395
Update: 2023-01-05T21:01:00+08@China-Shanghai+08
Design: Java Standard Library: Arrays
*/

import java.util.Arrays;

public class Java_Arrays {
    public static void main(String[] args) {
        var array_0 = new String[] {
            "C", "C++", "C#", "Java", "Python"
        };
        Arrays.parallelSort(array_0, (lhs, rhs) -> {
            return lhs.length() - rhs.length();
        });
        System.out.println(Arrays.toString(array_0));

        var array_1 = new double[] {
            3, -4, 25, 16, 30, 18
        };
        Arrays.parallelPrefix(array_1, (left, right) -> {
            return left * right;
        });
        System.out.println(Arrays.toString(array_1));

        var array_2 = new double[5];
        Arrays.parallelSetAll(array_2, (elem) -> {
            return elem * 5;
        });
        System.out.println(Arrays.toString(array_2));
    }
}
