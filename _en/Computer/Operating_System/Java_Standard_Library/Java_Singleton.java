/* Java_Singleton.java
Author: bss9395
Update: 2025-07-29T16:01:00+08@China-GuangDong-ZhanJiang+08
*/

class Singleton {
    private static Singleton _instance = new Singleton();
    public static Singleton _Instance() {
        return _instance;
    }
    private Singleton() {

    }
    public void print() {
        System.out.println("Singleton.print()");
    }
}

public class Java_Singleton {
    public static void main(String[] args) {
        Singleton instance = Singleton._Instance();
        instance.print();
    }
}
