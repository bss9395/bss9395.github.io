/* Java_DateFormat.java
Author: BSS9395
Update: 2023-01-15T18:50:00+08@China-Shanghai+08
Design: Java Standard Library: DateFormat
*/

import java.text.DateFormat;
import java.text.ParseException;
import java.util.Date;
import java.util.Locale;

public class Java_DateFormat {
    static public void main(String[] args)
            throws ParseException {
        _DateFormat();
        _parse();
    }
    static public void _DateFormat() {
        Locale[] locales = new Locale[] {
            Locale.CHINA, Locale.US
        };
        String[] names = new String[] {
            "----中国格式----", "----美国格式----"
        };
        DateFormat[][] formats = new DateFormat[locales.length][8];
        for(int i = 0; i < locales.length; i += 1) {
            formats[i][0] = DateFormat.getDateInstance(DateFormat.SHORT, locales[i]);
            formats[i][1] = DateFormat.getDateInstance(DateFormat.MEDIUM, locales[i]);
            formats[i][2] = DateFormat.getDateInstance(DateFormat.LONG, locales[i]);
            formats[i][3] = DateFormat.getDateInstance(DateFormat.FULL, locales[i]);

            formats[i][4] = DateFormat.getTimeInstance(DateFormat.SHORT, locales[i]);
            formats[i][5] = DateFormat.getTimeInstance(DateFormat.MEDIUM, locales[i]);
            formats[i][6] = DateFormat.getTimeInstance(DateFormat.LONG, locales[i]);
            formats[i][7] = DateFormat.getTimeInstance(DateFormat.FULL, locales[i]);
        }

        Date date = new Date();
        for(int i = 0; i < locales.length; i += 1) {
            System.out.println(names[i]);
            System.out.printf("%10s: %s %n", "SHORT", formats[i][0].format(date));
            System.out.printf("%10s: %s %n", "MEDIUM", formats[i][1].format(date));
            System.out.printf("%10s: %s %n", "LONG", formats[i][2].format(date));
            System.out.printf("%10s: %s %n", "FULL", formats[i][3].format(date));

            System.out.printf("%10s: %s %n", "SHORT", formats[i][4].format(date));
            System.out.printf("%10s: %s %n", "MEDIUM", formats[i][5].format(date));
            System.out.printf("%10s: %s %n", "LONG", formats[i][6].format(date));
            System.out.printf("%10s: %s %n", "FULL", formats[i][7].format(date));
        }
    }
    static public void _parse()
            throws ParseException {
        String date_0 = "2023/01/15";
        String date_1 = "2023-01-15";
        System.out.println(DateFormat.getDateInstance(DateFormat.SHORT).parse(date_0));
        System.out.println(DateFormat.getDateInstance(DateFormat.SHORT).parse(date_1));
    }
}
