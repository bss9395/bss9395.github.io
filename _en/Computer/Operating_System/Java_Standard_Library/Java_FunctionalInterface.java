/* Java_FunctionalInterface.java
Author: bss9395
Update: 2025-07-30T16:00:00+08@China-GuangDong-ZhanJiang+08
*/

@FunctionalInterface
interface IMessage {
    public void send(String str);
}

@FunctionalInterface
interface IFunction<P> {
    public int compare(P p1, P p2);
}

public class Java_FunctionalInterface {
    public static void _Test_FunctionalInterface() {
        IMessage msg = (str) -> {
            System.out.println("发送消息：" + str);
        };
        msg.send("www.mldn.cn");
    }

    public static void _Test_FunctionalReference() {
        IFunction<String> func = String::compareTo;
        System.out.println(func.compare("A", "a"));
    }

    public static void main(String[] args) {
        // _Test_FunctionalInterface();
        _Test_FunctionalReference();
    }
}
