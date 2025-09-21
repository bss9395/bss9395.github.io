/* Java_UUID.java
Author: bss9395
Update: 2025-08-06T20:26:00+08@China-GuangDong-ZhanJiang+08
*/

import java.util.UUID;

public class Java_UUID {
    public static void main(String[] args) {
        _Test_UUID();
    }
    public static void _Test_UUID() {
        UUID uuid = UUID.randomUUID();
        System.out.println(uuid);
    }
}
