/* Java_Factory.java
Author: bss9395
Update: 2025/09/25T21:24:00+08@China-GuangDong-ZhanJiang+08
*/

public class Java_Factory {
    static public void main(String[] args) {
        IMessage message = Factory.getInstance("NetMessage", IMessage.class);
        message.send();
        IService service = Factory.getInstance("HouseService", IService.class);
        service.work();
    }
}

interface IService {
    public void work();
}

class HouseService implements IService {

    @Override
    public void work() {
        System.out.println("HouseService work");
    }
}

interface IMessage {
    public void send();
}

class CloudMessage implements IMessage {
    @Override
    public void send() {
        System.out.println("CloudMessage send");
    }
}

class NetMessage implements IMessage {
    @Override
    public void send() {
        System.out.println("NetMessage send");
    }
}

class Factory {
    static public <T> T getInstance(String className, Class<T> clazz) {
        T instance = null;
        try {
            instance = (T) Class.forName(className).getDeclaredConstructor().newInstance();
        } catch (Exception exception) {
            exception.printStackTrace();
        }
        return instance;
    }
}
