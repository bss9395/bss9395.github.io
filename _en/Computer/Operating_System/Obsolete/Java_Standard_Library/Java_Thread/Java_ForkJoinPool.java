/* Java_ForkJoinPool.java
Author: BSS9395
Update: 2023-02-19T20:52:00+08@China-Shanghai+08
Design: Java Standard Library: ForkJoinPool
*/

import java.util.Random;
import java.util.concurrent.*;

public class Java_ForkJoinPool {
    static public class ForkAction extends RecursiveAction {
        static private int _threshold = 50;
        private int _head = 0;
        private int _tail = 0;
        public ForkAction(int head, int tail) {
            _head = head;
            _tail = tail;
        }

        @Override
        public void compute() {
            if(_tail - _head < _threshold) {
                for(int i = _head; i < _tail; i += 1) {
                    System.out.printf("%s: %02d%n", Thread.currentThread().getName(), i);
                }
            } else {
                int waist = (_head + _tail) / 2;
                new ForkAction(_head, waist).fork();
                new ForkAction(waist, _tail).fork();
            }
        }
    }

    static public class ForkTask extends RecursiveTask<Integer> {
        static private int _threshold = 20;
        private int _array[] = null;
        private int _head = 0;
        private int _tail = 0;
        public ForkTask(int array[], int head, int tail) {
            _array = array;
            _head = head;
            _tail = tail;
        }

        @Override
        public Integer compute() {
            if(_tail - _head < _threshold) {
                int sum = 0;
                for(int i = _head; i < _tail; i += 1) {
                    sum += _array[i];
                }
                return sum;
            } else {
                int waist = (_head + _tail) / 2;
                ForkTask task_head = new ForkTask(_array, _head, waist);
                ForkTask task_tail = new ForkTask(_array, waist, _tail);
                task_head.fork();
                task_tail.fork();
                return (task_head.join() + task_tail.join());
            }
        }
    }

    static public void main(String[] args)
        throws InterruptedException, ExecutionException {
        // _RecursiveAction();
        _RecursiveTask();
    }
    static public void _RecursiveAction()
        throws InterruptedException{
        ForkJoinPool pool = new ForkJoinPool();
        pool.submit(new ForkAction(0, 300));
        pool.awaitTermination(2, TimeUnit.SECONDS);
        pool.shutdown();
    }
    static public void _RecursiveTask()
        throws InterruptedException, ExecutionException {
        int[] array = new int[100];
        Random random = new Random();

        int sum = 0;
        for(int i = 0; i < array.length; i += 1) {
            // sum += (array[i] = random.nextInt(20));
            sum += (array[i] = i + 1);
        }
        System.out.printf("sum          == %3d%n", sum);

        ForkJoinPool pool = ForkJoinPool.commonPool();
        Future<Integer> future = pool.submit(new ForkTask(array, 0, array.length));
        System.out.printf("future.get() == %03d%n", future.get());

        pool.shutdown();
    }
}
