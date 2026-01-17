/* Java_Singleton.java
Author: bss9395
Update: 2025/09/25T21:37:00+08@China-GuangDong-ZhanJiang+08
*/

public class Java_Singleton {
    static public void main(String[] args) {
        // _Test_Singleton0();
        _Test_Singleton1();
    }

    static public void _Test_Singleton0() {
        for(int i = 0; i < 3; i += 1) {
            new Thread(() -> {
                Singleton0._Instance()._Print();
            }, "单例" + i).start();
        }
    }

    static public void _Test_Singleton1() {
        for(int i = 0; i < 3; i += 1) {
            new Thread(() -> {
                Singleton1._Instance()._Print();
            }, "单例" + i).start();
        }
    }
}

class Singleton0 {
    static private Singleton0 _instance = new Singleton0();

    static public Singleton0 _Instance() {
        return _instance;
    }

    private Singleton0() {
        System.out.println("[" + Thread.currentThread().getName() + "]");
    }

    public void _Print() {
        System.out.println("hello!");
    }
}


class Singleton1 {
    static private volatile Singleton1 _instance = null;

    static public Singleton1 _Instance() {
        if(_instance == null) {
            synchronized (Singleton1.class) {
                if(_instance == null) {
                    _instance = new Singleton1();
                }
            }
        }
        return _instance;
    }

    private Singleton1() {
        System.out.println("[" + Thread.currentThread().getName() + "]");
    }

    public void _Print() {
        System.out.println("hello!");
    }
}