/* Java_format.java
Author: bss9395
Update: 2025-07-24T11:04:00+08@China-GuangDong-ZhanJiang+08
*/

public class Java_format {
    public static void main(String[] args) {
        String name = "张三";
        int age = 18;
        double score = 98.7654321;
        String str = String.format("姓名：%s，年龄：%d，成绩：%5.2f。", name, age, score);
        System.out.println(str);
    }
}
