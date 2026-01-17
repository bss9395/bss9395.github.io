/* Java_Identifier_Lookup.java
Author: bss9395
Update: 2025-07-25T15:01:00+08@China-GuangDong-ZhanJiang+08
*/

class Base {
    public void Func() {
        System.out.println("Base.Func()");
    }
}

class Derive extends Base {
    @Override
    public void Func() {
        System.out.println("Derive.Func()");
    }
}

class Extend extends Derive {
    public void Function() {
        System.out.println("Extend$Function()");
    }
}

public class Java_Identifier_Lookup {
    public static void main(String[] args) {
        Base base = new Extend();
        base.Func();
    }
}
