/* Java_Serializable.java
Author: BSS9395
Update: 2023-02-11T21:49:00+08@China-Shanghai+08
Design: Java Language Feature: Serializable
*/

import java.io.*;

public class Java_Serializable {
    static public class Datum implements java.io.Serializable {
        static final private long serialVersionUID = 9395L;
        public String _id;
        public String _name;
        public Datum(String id, String name) {
            System.out.println("public Datum(String id, String name) {");

            _id = id;
            _name = name;
        }
        @Override
        public String toString() {
            return String.format("[%s: %s]", _id, _name);
        }
        public void set_id(String id) {
            _id = id;
        }
        public String get_id() {
            return _id;
        }
        public void set_name(String name) {
            _name = name;
        }
        public String get_name() {
            return _name;
        }
    }
    static public class Data implements java.io.Serializable {
        static final private long serialVersionUID = 9395L;
        public String _id;
        public transient String _name;
        public Datum _datum;
        public Data(String id, String name, Datum datum) {
            _id = id;
            _name = name;
            _datum = datum;
        }
        public void set_id(String id) {
            _id = id;
        }
        public String get_id() {
            return _id;
        }
        public void set_name(String name) {
            _name = name;
        }
        public String get_name() {
            return _name;
        }
        public void set_datum(Datum datum) {
            _datum = datum;
        }
        public Datum get_datum() {
            return _datum;
        }
    }

    static public void main(String[] args) {
        System.out.println("static public void main(String[] args) {");
        // _writeObject();
        // _readObject();
        // _Data();
        // _Mutable();
        _Transient();
    }
    static public void _writeObject() {
        System.out.println("static public void _writeObject() {");
        try(ObjectOutputStream stream = new ObjectOutputStream(new FileOutputStream("object.data"));) {
            Datum person = new Datum("1156", "BSS9395");
            stream.writeObject(person);
        } catch (IOException exception) {
            exception.printStackTrace();
        }
    }
    static public void _readObject() {
        System.out.println("static public void _readObject() {");
        try(ObjectInputStream stream = new ObjectInputStream(new FileInputStream("object.data"));) {
            Datum datum = (Datum)stream.readObject();
            System.out.println(datum);
        } catch(ClassNotFoundException exception) {
            exception.printStackTrace();
        } catch(IOException exception) {
            exception.printStackTrace();
        }
    }
    static public void _Data() {
        try(ObjectOutputStream stream = new ObjectOutputStream(new FileOutputStream("object.data"));) {
            Datum datum = new Datum("1156", "BSS9395");
            Data data_0 = new Data("1157", "Maker", datum);
            Data data_1 = new Data("1158", "Brilliant", datum);

            stream.writeObject(datum);
            stream.writeObject(data_0);
            stream.writeObject(data_1);
            stream.writeObject(data_0);
        } catch(IOException exception) {
            exception.printStackTrace();
        }

        try(ObjectInputStream stream = new ObjectInputStream(new FileInputStream("object.data"));) {
            Datum datum = (Datum) stream.readObject();
            Data data_0 = (Data) stream.readObject();
            Data data_1 = (Data) stream.readObject();
            Data data_2 = (Data) stream.readObject();

            System.out.println(datum == data_0.get_datum());
            System.out.println(data_0 == data_1);
            System.out.println(data_1.get_datum() == data_2.get_datum());
        } catch (IOException exception) {
            exception.printStackTrace();
        } catch (ClassNotFoundException exception) {
            exception.printStackTrace();
        }
    }
    static public void _Mutable() {
        try(ObjectOutputStream output = new ObjectOutputStream(new FileOutputStream("object.data"));
            ObjectInputStream input = new ObjectInputStream(new FileInputStream("object.data"));) {
            Datum datum = new Datum("1156", "BSS9395");
            output.writeObject(datum);
            datum.set_name("Brilliant");
            output.writeObject(datum);

            Datum datum_0 = (Datum)input.readObject();
            Datum datum_1 = (Datum)input.readObject();
            System.out.println(datum_0 == datum_1);
            System.out.println(datum_0.get_name());
            System.out.println(datum_1.get_name());
        } catch(FileNotFoundException exception) {
            exception.printStackTrace();
        } catch(IOException exception) {
            exception.printStackTrace();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
    static public void _Transient() {
        try(ObjectOutputStream output = new ObjectOutputStream(new FileOutputStream("object.data"));
            ObjectInputStream input = new ObjectInputStream(new FileInputStream("object.data"));) {
            Data data = new Data("1156", "BSS9395", null);
            output.writeObject(data);

            Data data_0 = (Data)input.readObject();
            System.out.println(data_0._id);
            System.out.println(data_0._name);
            System.out.println(data_0._datum);
        } catch(FileNotFoundException exception) {
            exception.printStackTrace();
        } catch(IOException exception) {
            exception.printStackTrace();
        } catch (ClassNotFoundException exception) {
            exception.printStackTrace();
        }
    }
}
