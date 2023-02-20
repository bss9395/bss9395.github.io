/* Java_BlockingQueue.java
Author: BSS9395
Update: 2023-02-19T14:06:00+08@China-Shanghai+08
Design: Java Standard Library: BlockingQueue
*/

import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;

public class Java_BlockingQueue {
    static public class Producer extends Thread {
        private BlockingQueue<String> _goods;
        public Producer(String name, BlockingQueue<String> goods) {
            super(name);
            _goods = goods;
        }

        static public String[] _langs = new String[] {
            "C", "C++", "C#", "Java", "Python"
        };
        static public int _index = 0;

        @Override
        public void run() {
            try {
                for(int i = 0; i < 100; i += 1) {
                    int index = 0;
                    synchronized (Producer._langs) {
                        index = Producer._index;
                        Producer._index += 1;
                    }
                    String lang = String.format("%03d", index) + _langs[index % _langs.length];
                    _goods.put(lang);
                    System.out.printf("%s: %s%n", Thread.currentThread().getName(), lang);
                    System.out.flush();
                }
            } catch (InterruptedException exception) {
                exception.printStackTrace();
            }
        }
    }

    static public class Consumer extends Thread {
        private BlockingQueue<String> _goods;
        public Consumer(String name, BlockingQueue<String> goods) {
            super(name);
            _goods = goods;
        }

        @Override
        public void run() {
            try {
                while (true) {
                    String lang = _goods.take();
                    System.out.printf("%s: %s%n", Thread.currentThread().getName(), lang);
                    System.out.flush();
                }
            } catch (InterruptedException exception) {
                exception.printStackTrace();
            }
        }
    }

    static public void main(String[] args) {
        _BlockingQueue();
    }
    static public void _BlockingQueue() {
        BlockingQueue<String> goods = new ArrayBlockingQueue<>(3);
        new Producer("Producer-0", goods).start();
        new Producer("Producer-1", goods).start();
        new Producer("Producer-2", goods).start();
        new Consumer("Consumer-0", goods).start();
        new Consumer("Consumer-1", goods).start();
    }
}
