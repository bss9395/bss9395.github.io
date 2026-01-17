/* Java_Closeable.java
Author: bss9395
Update: 2025-08-04T19:16:00+08@China-GuangDong-ZhanJiang+08
*/

interface IMessage {
    public void _Send();
}
class NetMessage implements IMessage, AutoCloseable {
    private String _message = "";
    public NetMessage(String message) {
        _message = message;
    }
    public boolean _Open() {
        System.out.println("【Open】获取消息发送连接资源");
        return true;
    }
    @Override
    public void _Send() {
        if(this._Open()) {
            System.out.println("【发送消息】" + _message);
        }
    }
    @Override
    public void close() throws Exception {
        System.out.println("【Close】关闭消息发送通道");
    }
}
public class Java_Closeable {
    public static void main(String[] args) throws Exception {
        try(NetMessage netMessage = new NetMessage("www.mldn.cn")) {
            netMessage._Send();
        } catch (Exception except) {
            except.printStackTrace();
        }
    }
}
