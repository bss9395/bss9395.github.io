/* Java_Timer.java
Author: BSS9395
Update: 2023-03-03T21:36:00+08@China-Zhanjiang+08
Design: Java Standard Library: Timer
*/

import java.util.Calendar;
import java.util.Timer;
import java.util.TimerTask;

public class Java_Timer {
    public static void main(String[] args) {
        // _schedule_delay();
        // _schedual_delay_period();
        // _schedualAtFixedRate_delay_period();
        _schedualAtFixedRate_Date_period();
    }
    static public void _schedule_delay() {
        Timer timer = new Timer(false);
        timer.schedule(new TimerTask() {
            @Override
            public void run() {
                System.out.println("schedule_delay");
                timer.cancel();
            }
        }, 2000);
    }

    static public void _schedual_delay_period() {
        Timer timer = new Timer(false);
        timer.schedule(new TimerTask() {
            @Override
            public void run() {
                System.out.println("schedule_delay_period");
            }
        }, 2000, 3000);
    }

    static public void _schedualAtFixedRate_delay_period() {
        Timer timer = new Timer(false);
        timer.scheduleAtFixedRate(new TimerTask() {
            @Override
            public void run() {
                System.out.println("schedualAtFixedRate_delay");
            }
        }, 2000, 3000);
    }

    static public void _schedualAtFixedRate_Date_period() {
        Calendar calendar = Calendar.getInstance();
        calendar.add(Calendar.SECOND, 2);

        Timer timer = new Timer(false);
        timer.scheduleAtFixedRate(new TimerTask() {
            @Override
            public void run() {
                System.out.println("_schedualAtFixedRate_Date_period");
            }
        }, calendar.getTime(), 1000 * 60 * 60 * 24);
    }
}
