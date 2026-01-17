/* Java_Polymorphism.java
Author: BSS9395
Update: 2022-12-28T20:11:00+08@China-Shanghai+08
Design: Java Polymorphism
*/

public class Java_Polymorphism {
    public static class Base {
        public double _id = 123.456;

        public void _Info() {
            System.out.printf("Base._Info(): %f %n", _id);
        }
    }

    public static class Derived extends Base {
        public String _id = "ID";

        public void _Info() {
            System.out.printf("Derived._Info(): %s %n", _id);
        }
    }

    public static void main(String[] args) {
        Base derived = new Derived();
        System.out.println("_id = " + derived._id);
        derived._Info();
    }
}
