/* Java_equals.java
Author: BSS9395
Update: 2022-12-30T22:01:00+08@China-Shanghai+08
Design: Java equals()
*/

public class Java_equals {
    static public class Datum {
        public String _id = "id";
        public String _name = "name";
        public Datum(String id, String name) {
            _id = id;
            _name = name;
        }
        @Override
        public boolean equals(Object object) {
            if(this == object) {
                return true;
            }
            if(object == null || (object instanceof Datum) == false) {
                return false;
            }

            Datum that = (Datum) object;
            if(_id == that._id && _name == that._name) {
                return true;
            }
            if(_id != null && _id.equals(that._id) && _name != null && _name.equals(that._name)) {
                return true;
            }
            return false;
        }
    }
    public static void main(String[] args) {
        Datum datum_0 = new Datum("1156", "bss9395");
        Datum datum_1 = new Datum("1157", "maker");
        Datum datum_2 = new Datum("1156", "brilliant");
        Datum datum_3 = new Datum(new String("1156"), new String("bss9395"));
        System.out.println(datum_0.equals(datum_1));
        System.out.println(datum_0.equals(datum_2));
        System.out.println(datum_0.equals(datum_3));
    }
}
