/* Java_DateTimeFormatter.java
Author: BSS9395
Update: 2023-01-15T20:45:00+08@China-Shanghai+08
Design: Java Standard Library: DateTimeFormatter
*/

import java.time.*;
import java.time.format.*;
import java.time.temporal.Temporal;
import java.time.temporal.TemporalAccessor;

public class Java_DateTimeFormatter {
    static public void main(String[] args) {
        // _DateTimeFormatter();
        _parse();
    }
    static public void _DateTimeFormatter() {
        DateTimeFormatter[] formatters = new DateTimeFormatter[] {
            DateTimeFormatter.ISO_LOCAL_DATE,
            DateTimeFormatter.ISO_LOCAL_TIME,
            DateTimeFormatter.ISO_LOCAL_DATE_TIME,
            DateTimeFormatter.ofLocalizedDateTime(FormatStyle.FULL, FormatStyle.MEDIUM),
            DateTimeFormatter.ofPattern("yyyy/MM/dd HH:mm:ss")
        };

        LocalDateTime time = LocalDateTime.now();
        for(int i = 0; i < formatters.length; i += 1) {
            System.out.println(formatters[i].format(time));
        }
    }
    static public void _parse() {
        String string = "2023/01/15 20:58:01";
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy/MM/dd HH:mm:ss");
        LocalDateTime time = LocalDateTime.parse(string, formatter);
        System.out.println(time);
    }
}
