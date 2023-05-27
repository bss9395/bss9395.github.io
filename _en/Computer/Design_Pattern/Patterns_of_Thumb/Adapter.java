/* Adapter.java
Author: BSS9395
Update: 2023-05-26T15:56:00+08@China-Guangdong-Zhanjiang+08
Design: Design Pattern: Adapter
*/

abstract class AMethod {
    abstract public void _Method_Adaptee();
    abstract public void _Method_Adapter();
}

class Adaptee {
    public void _Method() {
        System.out.println("Adaptee method!");
    }
}

class Adapter extends AMethod {
    public Adaptee _adaptee = null;
    public Adapter(Adaptee adaptee) {
        _adaptee = adaptee;
    }
    @Override
    public void _Method_Adaptee() {
        _adaptee._Method();
    }
    @Override
    public void _Method_Adapter() {
        System.out.println("Adapter method!");
    }

    public static void main(String[] args) {
        AMethod target = new Adapter(new Adaptee());
        target._Method_Adaptee();
        target._Method_Adapter();
    }
}
