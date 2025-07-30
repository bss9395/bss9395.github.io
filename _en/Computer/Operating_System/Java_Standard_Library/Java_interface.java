/* Java_interface.java
Author: bss9395
Update: 2025-07-25T21:48:00+08@China-GuangDong-ZhanJiang+08
*/

interface IMessage {
    public static final String INFO = "info";
    public abstract String getInfo();
}

interface IChannel {
    public abstract boolean connect();
}

interface IService extends IMessage, IChannel {
    public abstract String service();
}

abstract class DatabaseAbstract {
    public abstract boolean getDatabaseConnection();
}

class MessageImpl extends DatabaseAbstract implements IService {
    public String getInfo() {
        if(this.connect()) {
            if(this.getDatabaseConnection() == false) {
                return "数据库消息无法访问。";
            }
            return "数据库中得到一个消息。";
        }
        return "通道创建失败。";
    }
    public boolean connect() {
        System.out.println("消息发送通道已经成功建立。");
        return true;
    }

    public String service() {
        return "获取消息服务。";
    }

    public boolean getDatabaseConnection() {
        return true;
    }
}

public class Java_interface {
    public static void main(String[] args) {
        IMessage message = new MessageImpl();
        System.out.println(message.getInfo());
        System.out.println(IMessage.INFO);
    }
}
