public class Java_instanceof {
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
        Base base = new Derived();
        System.out.println("_id = " + base._id);
        base._Info();

        if(base instanceof Derived) {
            Derived derived = (Derived) base;
            derived._Info();
        }
    }
}
