/* Java_Anonymous_Class.java
Author: BSS9395
Update: 2023-01-02T22:22:00+08@China-Shanghai+08
Design: Java Anonymous Class
*/


import java.util.Arrays;

public class Java_Anonymous_Class {
    interface IDatum {
        public double _Process(double elem);
    }
    abstract static class ADatum {
        public double _exponent = 1.0;
        public ADatum(double exponent) {
            _exponent = exponent;
        }
        abstract public double _Process(double elem);
    }

    public static void main(String[] args) {
        System.out.println("public static void main(String[] args) {");
        double[] data = {
            1, -2, 3, -4
        };

        var anonymous = new Java_Anonymous_Class();
        anonymous._Process_Array(data, (double elem) -> {
            return (elem + 1.0);
        });
        System.out.println(Arrays.toString(data));

        anonymous._Process_Array(data, new IDatum() {
            @Override
            public double _Process(double elem) {
                return elem * elem;
            }
        });
        System.out.println(Arrays.toString(data));

        anonymous._Process_Array(data, new ADatum(2.0) {
            @Override
            public double _Process(double elem) {
                return Math.pow(elem, _exponent);
            }
        });
        System.out.println(Arrays.toString(data));
    }
    public void _Process_Array(double[] data, IDatum idatum) {
        System.out.println("public void _Process_Array(double[] data, IDatum idatum) {");
        for (int i = 0; i < data.length; i += 1) {
            data[i] = idatum._Process(data[i]);
        }
    }
    public void _Process_Array(double[] data, ADatum adatum) {
        System.out.println("public void _Process_Array(double[] data, ADatum adatum) {");
        for (int i = 0; i < data.length; i += 1) {
            data[i] = adatum._Process(data[i]);
        }
    }
}
