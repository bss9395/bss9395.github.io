/* Java_FutureTask.java
Author: bss9395
Update: 2025-08-04T16:15:00+08@China-GuangDong-ZhanJiang+08
*/

import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.FutureTask;

public class Java_FutureTask {
    public static void main(String[] args) throws ExecutionException, InterruptedException {
        Call call = new Call();
        FutureTask<String> taskA = new FutureTask<String>(call);
        FutureTask<String> taskB = new FutureTask<String>(call);
        FutureTask<String> taskC = new FutureTask<String>(call);
        new Thread(taskA, "竞赛者A").start();
        new Thread(taskB, "竞赛者B").start();
        new Thread(taskC, "竞赛者C").start();
        System.out.println(taskA.get());
        System.out.println(taskB.get());
        System.out.println(taskC.get());
    }
}

class Call implements Callable<String> {
    private boolean _flag = false;
    @Override
    public String call() throws Exception {
        synchronized (this) {
            if(_flag == false) {
                _flag = true;
                String result = Thread.currentThread().getName() + "抢答成功";
                System.out.println(result);
                return result;
            }
            String result = Thread.currentThread().getName() + "抢答失败";
            System.out.println(result);
            return result;
        }
    }
}