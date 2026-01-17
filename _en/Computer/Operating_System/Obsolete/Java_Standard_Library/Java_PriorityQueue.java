/* Java_PriorityQueue.java
Author: BSS9395
Update: 2023-01-22T19:09:00+08@China-Shanghai+08
Design: Java Standard Library: PriorityQueue
*/

import java.util.PriorityQueue;

public class Java_PriorityQueue {
    static public void main(String[] args) {
        _PriorityQueue();
    }
    static public void _PriorityQueue() {
        PriorityQueue<String> langs = new PriorityQueue<String>();
        langs.add("Java");
        langs.add("Python");
        langs.add("C");
        langs.add("C++");
        langs.add("C#");
        System.out.println(langs);

        System.out.println(langs.poll());
        System.out.println(langs.poll());
        System.out.println(langs.poll());
    }
}
