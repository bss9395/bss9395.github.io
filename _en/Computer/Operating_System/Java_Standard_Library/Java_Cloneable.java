/* Java_Cloneable.java
Author: BSS9395
Update: 2023-01-09T22:09:00+08@China-Shanghai+08
Design: Java Interface: Cloneable
*/

class Address implements Cloneable {
    public String _location = "location";
    public Address clone()
        throws CloneNotSupportedException {
        return (Address) super.clone();
    }
}

class Datum implements Cloneable {
    public Address _address = new Address();
    public double _value = 0.0;
    public Datum clone()
        throws CloneNotSupportedException {
        return (Datum) super.clone();
    }
}

public class Java_Cloneable {
    static public void main(String[] args)
        throws CloneNotSupportedException {
        Datum datum_0 = new Datum();
        Datum datum_1 = datum_0.clone();  // shallow clone
        System.out.println(datum_0 == datum_1);
        System.out.println(datum_0._address == datum_1._address);

        datum_0._value = 123.456;
        datum_0._address._location = "shanghai";
        System.out.printf("datum_0._value=%s, datum_1._value=%s %n", datum_0._value, datum_1._value);
        System.out.printf("datum_0._address._location=%s, datum_1._address._location=%s %n", datum_0._address._location, datum_1._address._location);
    }
}
