/* Java_final.java
Author: BSS9395
Update: 2023-01-01T20:32:00+08@China-Shanghai+08
Design: Java Keyword final
*/

import java.util.Date;

public class Java_final {
    static public class Datum {
        static {
            System.out.println("static");
        }
        final static public String _compile = "compile";
        final static public Date _date = new Date();
        public String _id = "ID";
        public Datum(final String id) {
            _id = id;
        }
    }
    static public void main(String[] args) {
        // _final();
        // _static();
        _run();
    }
    static public void _final() {
        final Datum datum = new Datum("1156");
        datum._id = "1157";
        System.out.println(datum._id);
        // datum = null;
    }
    static public void _static() {
        System.out.println(Datum._compile);
    }
    static public void _run() {
        System.out.println(Datum._date);
    }
}
