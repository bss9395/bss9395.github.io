/* Java_Nested_Class.java
Author: BSS9395
Update: 2023-01-02T20:48:00+08@China-Shanghai+08
Design: Java Nested Class
*/

public class Java_Nested_Class {
    private class Inner {
        private String _id = "inner";

        public void _Info() {
            System.out.println("public void _Info() {");
            String _id = "local";

            System.out.println(_id);
            System.out.println(this._id);
            System.out.println(Java_Nested_Class.this._id);
        }
    }

    private String _id = "outer";

    public void _Test() {
        System.out.println("private void _Test() {");
        new Inner()._Info();
    }

    public static void main(String[] args) {
        System.out.println("public static void main(String[] args) {");
        new Java_Nested_Class()._Test();
    }
}
