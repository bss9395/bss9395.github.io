/* Java_Unsafe.java
Author: bss9395
Update: 2025/09/26T11:47:00+08@China-GuangDong-ZhanJiang+08
*/

import sun.misc.Unsafe;
import java.lang.reflect.Field;

public class Java_Unsafe {
    static public void main(String[] args) throws Exception {
        Field field = Unsafe.class.getDeclaredField("theUnsafe");
        field.setAccessible(true);
        Unsafe unsafeObject = (Unsafe)field.get(null);
        Singleton instance = (Singleton) unsafeObject.allocateInstance(Singleton.class);
        instance._Print();
    }

}

class Singleton {
    private Singleton() {
        System.out.println("private Singleton() {");
    }
    public void _Print() {
        System.out.println("bss9395@github.com");
    }
}