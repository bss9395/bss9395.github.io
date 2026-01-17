import java.util.Timer;

class MyTask extends java.util.TimerTask {
    @Override
    public void run() {
        System.out.println("[" + Thread.currentThread().getName() + "] 当前时间：" + System.currentTimeMillis());
        System.out.println("end: run");
    }
}

public class Java_TimerTask {
    public static void main(String[] args) {
        // _Test_schedule();
        _Test_scheduleAtFixedRate();
    }
    public static void _Test_schedule() {
        Timer timer = new Timer();
        timer.schedule(new MyTask(), 1000);  // 任务执行完以后程序不退出
        System.out.println("end schedule");
    }
    public static void _Test_scheduleAtFixedRate() {
        Timer timer = new Timer();
        timer.scheduleAtFixedRate(new MyTask(), 100, 1000);
        System.out.println("end scheduleAtFixedRate");
    }
}
