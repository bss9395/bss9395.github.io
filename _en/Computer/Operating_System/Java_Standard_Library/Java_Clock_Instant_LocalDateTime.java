/* Java_Clock_Instant_LocalDateTime.java
Author: BSS9395
Update: 2023-01-12T22:36:00+08@China-Shanghai+08
Design: Java Standard Library: Clock, Instant, LocalDateTime
*/

import java.time.*;

public class Java_Clock_Instant_LocalDateTime {
    static public void main(String[] args) {
        //_Clock();
        //_Instant();
        _LocalDateTime();
    }
    static public void _Clock() {
        Clock clock_0 = Clock.systemUTC();
        System.out.println(clock_0.instant());
        System.out.println(clock_0.millis());
        System.out.println(System.currentTimeMillis());

        Clock clock_1 = Clock.offset(clock_0, Duration.ofSeconds(-6000));
        System.out.println(clock_1.instant());
    }
    static public void _Instant() {
        Instant instant_0 = Instant.now();
        System.out.println(instant_0);

        Instant instant_1 = Instant.parse("2023-01-14T15:41:00.123456789Z");
        System.out.println(instant_1);
        Instant instant_2 = instant_1.plus(Duration.ofHours(5).plusMinutes(4));
        System.out.println(instant_2);
    }
    static public void _LocalDateTime() {
        LocalDateTime time_0 = LocalDateTime.now();
        System.out.println(time_0);

        LocalDateTime time_1 = LocalDateTime.of(2023, 1, 14, 16, 12, 1);
        System.out.println(time_1);

        LocalDateTime time_2 = time_0.plusYears(1).plusMonths(1).plusDays(1).plusHours(1).plusMinutes(1).plusSeconds(1);
        System.out.println(time_2);
    }
}
