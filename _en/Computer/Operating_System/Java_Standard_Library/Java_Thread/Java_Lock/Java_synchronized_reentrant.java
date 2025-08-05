/* Java_synchronized_reentrant.java
Author: bss9395
Update: 2025-08-03T16:06:00+08@China-GuangDong-ZhanJiang+08
*/

public class Java_synchronized_reentrant {
    synchronized public void _Func(int depth) {
        if((0 <= depth) == false) {
            return;
        }
        _Func(depth - 1);
        System.out.println(depth);
    }

    public static void main(String[] args) {
        Java_synchronized_reentrant abc = new Java_synchronized_reentrant();
        abc._Func(3);
    }
}
