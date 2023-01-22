/* Java_Singleton.java
Author: BSS9395
Update: 2023-01-01T120:00:00+08@China-Shanghai+08
Design: Java Singleton
*/

public class Java_Singleton {
    public static void main(String[] args) {
        Java_Singleton singleton_0 = Java_Singleton._Instance();
        Java_Singleton singleton_1 = Java_Singleton._Instance();
        System.out.println(singleton_0 == singleton_1);
    }
    private static final Java_Singleton _instance = new Java_Singleton();
    private Java_Singleton() {

    }
    public static Java_Singleton _Instance() {
        return _instance;
    }
}
