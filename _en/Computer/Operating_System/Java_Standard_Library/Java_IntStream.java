/* Java_IntStream.java
Author: BSS9395
Update: 2023-01-18T22:38:00+08@China-Shanghai+08
Design: Java Standard Library: IntStream
*/

import java.util.stream.IntStream;

public class Java_IntStream {
    static public void main(String[] args) {
        _IntStream();
    }
    static public void _IntStream() {
        IntStream stream_0 = IntStream.builder()
            .add(20)
            .add(-2)
            .add(40)
            .add(30)
            .build();

        System.out.println(stream_0.max().getAsInt());
//        System.out.println(stream_0.min().getAsInt());
//        System.out.println(stream_0.sum());
//        System.out.println(stream_0.count());
//        System.out.println(stream_0.average());
//        System.out.println(stream_0.allMatch((elem) -> {
//            return (elem * elem > 20);
//        }));
//        System.out.println(stream_0.anyMatch((elem) -> {
//            return (elem * elem > 20);
//        }));
//
//        IntStream stream_1 = stream_0.map((elem) -> {
//            return (elem * 2 + 1);
//        });
//        stream_1.forEach(System.out::println);
    }
}
