import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.reflect.Method;

@Retention(RetentionPolicy.RUNTIME)
@interface DefaultAnnotation {
    public String title();
    public String url() default "bss9395@github.com";
}
class Message {
    @DefaultAnnotation(title = "bss9395")
    public void send(String msg) {
        System.out.println("【消息发送】" + msg);
    }
}

public class Java_Annotation {
    static public void main(String[] args) throws Exception {
        Method method = Message.class.getDeclaredMethod("send", String.class);
        DefaultAnnotation annotation = method.getAnnotation(DefaultAnnotation.class);
        System.out.println(annotation.title());
        System.out.println(annotation.url());

        String msg = annotation.title() + "(" + annotation.url() + ")";
        method.invoke(Message.class.getDeclaredConstructor().newInstance(), msg);
    }
}
