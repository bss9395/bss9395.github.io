/* Java_Pass_By_Pointer.java
Author: BSS9395
Update: 2022-12-27T17:56:00+08@China-Shanghai+08
Design: Java Arguments Passing
*/

public class Java_Pass_By_Pointer {
    public static class Datum {
        double _value_0;
        double _value_1;

        @Override
        public String toString() {
            return String.format("[%f, %f]", _value_0, _value_1);
        }
    }

    public static void main(String[] args) {
        Datum datum = new Datum();
        datum._value_0 = 2.0;
        datum._value_1 = 3.0;
        _Pass_By_Pointer(datum);

        System.out.println(datum);
    }

    public static void _Pass_By_Pointer(Datum datum) {
        double temp = datum._value_0;
        datum._value_0 = datum._value_1;
        datum._value_1 = temp;

        datum = null;
    }
}
