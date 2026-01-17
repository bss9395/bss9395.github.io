/* Java_ThreadLocal.java
Author: bss9395
Update: 2025-08-06T21:39:00+08@China-GuangDong-ZhanJiang+08
*/

public class Java_ThreadLocal {
    public static void main(String[] args) {
        new Thread(() -> {
            Message msg = new Message();
            msg.setInfo("第一个线程的消息");
            Channel.setMessage(msg);
            Channel.send();
        }, "消息发送者A").start();
        new Thread(() -> {
            Message msg = new Message();
            msg.setInfo("第二个线程的消息");
            Channel.setMessage(msg);
            Channel.send();
        }, "消息发送者B").start();
        new Thread(() -> {
            Message msg = new Message();
            msg.setInfo("第三个线程的消息");
            Channel.setMessage(msg);
            Channel.send();
        }, "消息发送者C").start();
    }
}

class Channel {
    private static final ThreadLocal<Message> THREADLOCAL = new ThreadLocal<Message>();
    private Channel() {

    }
    public static void setMessage(Message message) {
        THREADLOCAL.set(message);
    }
    public static void send() {
        System.out.println("【" + Thread.currentThread().getName() + "消息发送】" + THREADLOCAL.get().getInfo());
    }
}

class Message {
    private String _info;
    public void setInfo(String info) {
        _info = info;
    }
    public String getInfo() {
        return _info;
    }
}
