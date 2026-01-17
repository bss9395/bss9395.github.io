/* Java_Annotation.java
Author: BSS9395
Update: 2023-02-04T15:25:00+08@China-Shanghai+08
Design: Java Language Feature: Annotation
*/

public class Java_Annotation {
    @SuppressWarnings(value = "unchecked")
    @Deprecated(since = "10")
    static public class Datum {
        @Deprecated(since = "10")
        public void _Info() {
            System.out.println("void Java_Annotation.Datum._Info();");
        }
    }

    @FunctionalInterface
    interface IFace {
        public void _Invoke();
        static public void _Static() {
            System.out.println("void Java_Annotation.IFace._Invoke();");
        }
        default public void _Default() {
            System.out.println("void Java_Annotation.IFace._Default();");
        }
    }

    static public void main(String[] args) {
        _Deprecated();
    }
    static public void _Deprecated() {
        new Datum()._Info();
    }
}
