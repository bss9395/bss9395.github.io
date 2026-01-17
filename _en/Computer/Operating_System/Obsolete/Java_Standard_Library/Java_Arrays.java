/* Java_Arrays.java
Author: BSS9395
Update: 2023-01-05T21:01:00+08@China-Shanghai+08
Design: Java Standard Library: Arrays
*/

import java.util.Arrays;

public class Java_Arrays {
    public static void main(String[] args) {
        // _Test_parallelSort();
        // _Test_parallelPrefix();
        // _Test_ParallelSetAll();
        _Test_arraycopy();
    }

    public static void _Test_parallelSort() {
        var array_0 = new String[] {
                "C", "C++", "C#", "Java", "Python"
        };
        Arrays.parallelSort(array_0, (lhs, rhs) -> {
            return lhs.length() - rhs.length();
        });
        System.out.println(Arrays.toString(array_0));
    }

    public static void _Test_parallelPrefix() {
        var array_1 = new double[] {
                3, -4, 25, 16, 30, 18
        };
        Arrays.parallelPrefix(array_1, (left, right) -> {
            return left * right;
        });
        System.out.println(Arrays.toString(array_1));
    }

    public static void _Test_ParallelSetAll() {
        var array_2 = new double[5];
        Arrays.parallelSetAll(array_2, (elem) -> {
            return elem * 5;
        });
        System.out.println(Arrays.toString(array_2));
    }

    public static void _Test_arraycopy() {
        int[] dataA = new int[] {
            0, 1, 2, 3, 4, 5, 6, 7, 8, 9
        };
        int[] dataB = new int[] {
            00, 11, 22, 33, 44, 55, 66, 77, 88, 99
        };
        System.arraycopy(dataA, 5, dataB, 3, 3);
        System.out.println(Arrays.toString(dataB));
    }
}
