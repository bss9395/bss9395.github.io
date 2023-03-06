/* Java_Array.java
Author: BSS9395
Update: 2021-10-13T21:00:00+08@China-Guangdong-Shenzhen+08
Design: Java Language Feature: Array
*/

import java.lang.reflect.Array;

public class Java_Array {
    @SuppressWarnings("unchecked")
    static public <T> T[] _newInstance(Class<T> type, int length) {
        return (T[])Array.newInstance(type, length);
    }

    static public void main(String[] args) {
        // _Multi_Array();
        // _newInstance();
        // _newInstance_Multi();
        _Generic();
    }
    static public void _Multi_Array() {
        double array_C[] = new double[3];
        double[] array_Java = new double[3];
        double[] array_static = {
                1.0, 2.0, 3.0
        };
        double[] array_new = new double[] {
                1.0, 2.0, 3.0
        };

        Object[] array = new Object[] {
                1, 2.0, "3.0"
        };
        for (var e : array) {
            System.out.println(e.getClass());
        }

        ////////////////////////////////
        System.out.println("========================================");
        double[][] dim12 = new double[3][3];
        double[][] dim10 = new double[3][];
        for (int i = 0; i < dim10.length; i += 1) {
            dim10[i] = new double[i];
        }
        for (var e : dim10) {
            System.out.println(e.length);
        }

        ////////////////////////////////
        System.out.println("========================================");
        double[][] dim34 = new double[3][4];
        for(int i = 0; i < dim34.length; i += 1) {
            for(int j = 0; j < dim34[0].length; j += 1) {
                dim34[i][j] = i + j;
            }
        }
        System.out.println(dim34[1][2]);

        ////////////////////////////////
        System.out.println("========================================");
        /* Array of Array in Java. */
        Object dim = new Object[1];
        ((Object[]) dim)[0] = new Object[2];
        ((Object[]) (((Object[]) dim)[0]))[1] = new Object[3];
        ((Object[]) (((Object[]) (((Object[]) dim)[0]))[1]))[2] = new Object[4];
        ((Object[]) (((Object[]) (((Object[]) (((Object[]) dim)[0]))[1]))[2]))[3] = new Object[]{
                1, 2, 3, 4, 5
        };

        for (var obj : (Object[]) (((Object[]) (((Object[]) (((Object[]) (((Object[]) dim)[0]))[1]))[2]))[3])) {
            System.out.println(obj);
        }
    }
    static public void _newInstance() {
        int width = 5;
        int height = 6;
        Object array = Array.newInstance(String.class, width * height);
        Array.set(array, 5, "   5");
        Array.set(array, 6, "   6");

//        for(int i = 0; i < height; i += 1) {
//            for(int j = 0; j < width; j += 1) {
//                Array.set(array, i * width + j, String.format("%4d", i * width + j));
//            }
//        }
        for(int i = 0; i < height; i += 1) {
            for(int j = 0; j < width; j += 1) {
                Object value = Array.get(array, i * width + j);
                System.out.printf("%s ", value);
            }
            System.out.println();
        }
    }
    static public void _newInstance_Multi() {
        Object array = Array.newInstance(String.class, 3, 4, 5);
        Object array_2 = Array.get(array, 2);
        Array.set(array_2, 3, new String[] {
            "C", "C++", "C#", "Java", "Python"
        });

        String[][][] array_3_4_5 = (String[][][])array;
        for(int i = 0; i < 3; i += 1) {
            for(int j = 0; j < 4; j += 1) {
                for(int k = 0; k < 5; k += 1) {
                    System.out.printf("%6s ", array_3_4_5[i][j][k]);
                }
                System.out.println();
            }
            System.out.println();
        }
    }
    static public void _Generic() {
        String[][] strs = Java_Array._newInstance(String[].class, 10);
        strs[0] = new String[] {
            "C", "C++", "C#", "Java", "Python"
        };
    }
}
