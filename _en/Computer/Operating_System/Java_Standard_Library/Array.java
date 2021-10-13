/* Array.java
Author: BSS9395
Update: 2021-10-13T21:00:00+08@China-Guangdong-Shenzhen+08
Design: Java Array
*/

public class Array {
    public static void main(String[] args) {
        double array_C[] = new double[3];
        double[] array_Java = new double[3];
        double[] array_static = {
                1.0, 2.0, 3.0
        };
        double[] array_new = new double[]{
                1.0, 2.0, 3.0
        };

        Object[] array = new Object[]{
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
}
