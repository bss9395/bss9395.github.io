/* Java_final.java
Author: BSS9395
Update: 2023-01-01T20:32:00+08@China-Shanghai+08
Design: Java Keyword final
*/

public class Java_final {
    public static class Datum {
        public String _id = "ID";
        public Datum(final String id) {
            _id = id;
        }
    }
    public static void main(String[] args) {
        final Datum datum = new Datum("1156");
        datum._id = "1157";
        System.out.println(datum._id);

        // datum = null;
    }
}
