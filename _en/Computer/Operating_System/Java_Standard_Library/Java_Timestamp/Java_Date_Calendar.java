/* Java_Date_Calendar.java
Author: BSS9395
Update: 2023-01-12T22:36:00+08@China-Shanghai+08
Design: Java Standard Library: Date, Calendar
*/

import java.util.Calendar;
import java.util.Date;

public class Java_Date_Calendar {
    static public void main(String[] args) {
        // _Date();
        // _Calendar();
        _add_roll();
        // _setLenient();
        // _set();
    }
    static public void _Date() {
        Date date_0 = new Date();
        Date date_1 = new Date(System.currentTimeMillis() + 100);
        System.out.println(date_0);
        System.out.println(date_1);
        System.out.println(date_0.compareTo(date_1));
        System.out.println(date_0.before(date_1));
    }
    static public void _Calendar() {
        Calendar calendar = Calendar.getInstance();
        System.out.printf("%04d-%02d-%02d %n", calendar.get(Calendar.YEAR), calendar.get(Calendar.MONTH) + 1, calendar.get(Calendar.DAY_OF_MONTH));

        calendar.set(2023, 01, 12, 23, 34, 45);
        calendar.add(Calendar.YEAR, -1);
        System.out.println(calendar.getTime());
        calendar.roll(Calendar.MONTH, -8);
        System.out.println(calendar.getTime());
    }
    static public void _add_roll() {
        Calendar calendar = Calendar.getInstance();
        calendar.set(2003, 7, 31, 12, 23, 34);
        calendar.add(Calendar.MONTH, 6);
        System.out.printf("%04d-%02d-%02dT%02d:%02d:%02d %n",
                calendar.get(Calendar.YEAR), calendar.get(Calendar.MONTH) + 1, calendar.get(Calendar.DAY_OF_MONTH),
                calendar.get(Calendar.HOUR_OF_DAY), calendar.get(Calendar.MINUTE), calendar.get(Calendar.SECOND));

        calendar.set(2003, 7, 31, 12, 23, 34);
        calendar.roll(Calendar.MONTH, 6);
        System.out.printf("%04d-%02d-%02dT%02d:%02d:%02d %n",
                calendar.get(Calendar.YEAR), calendar.get(Calendar.MONTH) + 1, calendar.get(Calendar.DAY_OF_MONTH),
                calendar.get(Calendar.HOUR_OF_DAY), calendar.get(Calendar.MINUTE), calendar.get(Calendar.SECOND));
    }
    static public void _setLenient() {
        Calendar calendar = Calendar.getInstance();
        calendar.set(Calendar.MONTH, 13);
        System.out.println(calendar);
        System.out.printf("%04d-%02d-%02dT%02d:%02d:%02d %n",
                calendar.get(Calendar.YEAR), calendar.get(Calendar.MONTH) + 1, calendar.get(Calendar.DAY_OF_MONTH),
                calendar.get(Calendar.HOUR_OF_DAY), calendar.get(Calendar.MINUTE), calendar.get(Calendar.SECOND));

        try {
            calendar = Calendar.getInstance();
            calendar.setLenient(false);
            calendar.set(Calendar.MONTH, 13);
            System.out.printf("%04d-%02d-%02dT%02d:%02d:%02d %n",
                    calendar.get(Calendar.YEAR), calendar.get(Calendar.MONTH) + 1, calendar.get(Calendar.DAY_OF_MONTH),
                    calendar.get(Calendar.HOUR_OF_DAY), calendar.get(Calendar.MINUTE), calendar.get(Calendar.SECOND));
        } catch (IllegalArgumentException exception) {
            exception.printStackTrace();
        }
    }
    static public void _set() {
        Calendar calendar = Calendar.getInstance();
        calendar.set(2003, 7, 31);
        calendar.set(Calendar.DATE, 5);
        System.out.printf("%04d-%02d-%02dT%02d:%02d:%02d %n",
                calendar.get(Calendar.YEAR), calendar.get(Calendar.MONTH) + 1, calendar.get(Calendar.DAY_OF_MONTH),
                calendar.get(Calendar.HOUR_OF_DAY), calendar.get(Calendar.MINUTE), calendar.get(Calendar.SECOND));
    }
}
