public class Java_instanceof {
    static class Base {
        public double _id = 123.456;

        public void _Info() {
            System.out.printf("Base._Info(): %f %n", _id);
        }
    }

    static class Derived extends Base {
        public String _id = "ID";
        @Override
        public void _Info() {
            System.out.printf("Derived._Info(): %s %n", _id);
        }
    }

    static class Descendant extends Derived {
        public int _id = 9395;
        @Override
        public void _Info() {
            System.out.printf("Descendant._Info(): %s %n", _id);
        }
    }

    static public void main(String[] args) {
        Base base = new Descendant();
        System.out.println("_id = " + base._id);
        base._Info();

        System.out.println(base.getClass());
        if(base instanceof Derived) {
            Derived derived = (Derived) base;
            derived._Info();
        }
    }
}
