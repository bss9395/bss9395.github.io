/* Facade.java
Author: BSS9395
Update: 2023-05-26T21:22:00+08@China-Guangdong-Zhanjiang+08
Design: Design Pattern: Facade
*/

abstract class AService_A {
    abstract public void _Method_A();
}
abstract class AService_B {
    abstract public void _Method_B();
}
abstract class AService_C {
    abstract public void _Method_C();
}

class Service_A extends AService_A {
    @Override
    public void _Method_A() {
        System.out.println("这是服务A");
    }
}

class Service_B extends AService_B {
    @Override
    public void _Method_B() {
        System.out.println("这是服务B");
    }
}

class Service_C extends AService_C {
    @Override
    public void _Method_C() {
        System.out.println("这是服务C");
    }
}

public class Facade {
    public AService_A _service_a = new Service_A();
    public AService_B _service_b = new Service_B();
    public AService_C _service_c = new Service_C();

    public void _Method_A() {
        _service_a._Method_A();
        _service_b._Method_B();
    }

    public void _Method_B() {
        _service_b._Method_B();
        _service_c._Method_C();
    }

    public void _Method_C() {
        _service_c._Method_C();
        _service_a._Method_A();
    }

    static public void main(String[] args) {
        Facade facade = new Facade();
        facade._Method_A();
        facade._Method_B();
    }
}
