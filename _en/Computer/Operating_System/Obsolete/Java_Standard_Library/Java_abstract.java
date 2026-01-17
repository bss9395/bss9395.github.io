/* Java_abstract.java
Author: bss9395
Update: 2025-07-25T19:24:00+08@China-GuangDong-ZhanJiang+08
*/

abstract class Message {
    public static Message getInstance() {
        return new DatabaseMessage();
    }
    public abstract String getInfo();
}

class DatabaseMessage extends Message {
    public String getInfo() {
        return "数据库连接信息";
    }
}

public class Java_abstract {
    public static void main(String[] args) {
        Message message = Message.getInstance();
        System.out.println(message.getInfo());
    }
}
