/* Java_ArrayDeque.java
Author: BSS9395
Update: 2023-01-22T19:16:00+08@China-Shanghai+08
Design: Java Standard Library: ArrayDeque
*/

import java.util.ArrayDeque;

public class Java_ArrayDeque {
    static public void main(String[] args) {
        // _ArrayDeque_stack();
        _ArrayDeque_queue();
    }
    static public void _ArrayDeque_stack() {
        ArrayDeque<String> stack = new ArrayDeque<String>();
        stack.push("C");
        stack.push("C++");
        stack.push("C#");
        stack.push("Java");
        stack.push("Python");
        System.out.println(stack);

        System.out.println(stack.peek());
        System.out.println(stack);
        System.out.println(stack.pop());
        System.out.println(stack);
    }
    static public void _ArrayDeque_queue() {
        ArrayDeque<String> queue = new ArrayDeque<String>();
        queue.add("C");
        queue.add("C++");
        queue.add("C#");
        queue.add("Java");
        queue.add("Python");
        System.out.println(queue);

        System.out.println(queue.peek());
        System.out.println(queue);
        System.out.println(queue.poll());
        System.out.println(queue);
    }
}
