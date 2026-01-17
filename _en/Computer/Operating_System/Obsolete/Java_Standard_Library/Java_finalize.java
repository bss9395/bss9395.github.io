/* Java_finalize.java
Author: bss9395
Update: 2025-08-05T09:19:00+08@China-GuangDong-ZhanJiang+08
*/

class Type {
    public Type() {
        System.out.println("【构造】生存还是死亡，这是一个问题。");
    }

    @Override
    protected void finalize() throws Throwable {
        System.out.println("【析构】如果给我一个支点，我可以撬动地球。");
        throw new Exception("【异常】如果给我一个支点，我可以撬动地球。");
    }
}

public class Java_finalize {
    public static void main(String[] args) {
        _Test_finalize();
    }
    public static void _Test_finalize() {
        Type type = new Type();
        type = null;
        System.gc();
    }
}
