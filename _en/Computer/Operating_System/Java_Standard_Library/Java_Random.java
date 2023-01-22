/* Java_Random.java
Author: BSS9395
Update: 2023-01-12T20:27:00+08@China-Shanghai+08
Design: Java Standard Library: Random
*/

import java.util.Arrays;
import java.util.Random;

public class Java_Random {
    static public void main(String[] args) {
        // _next();
        _Random();
    }
    static public void _next() {
        byte[] array = new byte[16];

        Random random = new Random();
        System.out.println(random.nextBoolean());
        System.out.println(random.nextLong());
        System.out.println(random.nextDouble());
        System.out.println(random.nextGaussian());
        random.nextBytes(array);
        System.out.println(Arrays.toString(array));
    }
    static public void _Random() {
        byte[] array = new byte[16];

        Random random = new Random(70);
        System.out.println(random.nextBoolean());
        System.out.println(random.nextLong());
        System.out.println(random.nextDouble());
        System.out.println(random.nextGaussian());
        random.nextBytes(array);
        System.out.println(Arrays.toString(array));

        random = new Random(70);
        System.out.println(random.nextBoolean());
        System.out.println(random.nextLong());
        System.out.println(random.nextDouble());
        System.out.println(random.nextGaussian());
        random.nextBytes(array);
        System.out.println(Arrays.toString(array));

        random = new Random(System.currentTimeMillis());
        System.out.println(random.nextBoolean());
        System.out.println(random.nextLong());
        System.out.println(random.nextDouble());
        System.out.println(random.nextGaussian());
        random.nextBytes(array);
        System.out.println(Arrays.toString(array));
    }
}
