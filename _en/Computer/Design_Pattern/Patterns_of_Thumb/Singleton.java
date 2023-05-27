/* Singleton.java
Author: BSS9395
Update: 2023-05-26T15:37:00+08@China-Guangdong-Zhanjiang+08
Design: Design Pattern: Singleton
*/

public class Singleton {
    public String _data = "singleton";
    public static Singleton _instance = null;
    public static Singleton _Instance() {
        if (_instance == null) {
            _instance = new Singleton();
        }
        return _instance;
    }

    static public void main(String[] args) {
        Singleton singleton = Singleton._Instance();
        System.out.println(singleton._data);
    }
}
