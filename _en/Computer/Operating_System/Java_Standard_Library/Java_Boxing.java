/* Java_Boxing.java
Author: BSS9395
Update: 2022-12-30T19:16:00+08@China-Shanghai+08
Design: Java Boxing
*/

public class Java_Boxing {
    public static void main(String[] args) {
//        _Boxing();
//        _parse();
//        _valueOf();
        _Integer();
    }
    public static void _Boxing() {
        double num = 123.456;
        Double box = num;
        System.out.printf("type = %s, hash = %s %n", box.getClass(), box.hashCode());

        Object val = num;
        System.out.printf("type = %s, hash = %s %n", box.getClass(), box.hashCode());

        num = 456.789;
        System.out.printf("num = %s, box = %s %n", num, box);
    }
    public static void _parse() {
        double num = Double.parseDouble("123.456");
        System.out.printf("num = %s %n", num);
    }
    public static void _valueOf(){
        Double num = Double.valueOf("123.456");
        System.out.printf("num = %s %n", num);
    }
    public static void _Integer() {
        System.out.println(Integer.valueOf(2) == Integer.valueOf(2));
        System.out.println(Integer.valueOf(2).equals(Integer.valueOf(2)));
        System.out.println(Integer.valueOf(234) == Integer.valueOf(234));
        System.out.println(Integer.valueOf(234).equals(Integer.valueOf(234)));
    }
}
