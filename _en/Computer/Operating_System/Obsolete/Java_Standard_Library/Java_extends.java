/* Java_extends.java
Author: bss9395
Update: 2025-07-24T11:04:00+08@China-GuangDong-ZhanJiang+08
*/

class Person {
    private String name;
    private int age;

    public void setName(String name) {
        this.name = name;
    }
    public String getName() {
        return this.name;
    }

    public void setAge(int age) {
        this.age = age;
    }
    public int getAge() {
        return this.age;
    }
}

class Student extends Person {
    private String school;

    public void setSchool(String school) {
        this.school = school;
    }
    public String getSchool() {
        return this.school;
    }
}

public class Java_extends {
    public static void main(String[] args) {
        Student student = new Student();
        student.setName("林大强");
        student.setAge(38);
        student.setSchool("社区大学");
        System.out.println("姓名：" + student.getName() + "，年龄：" + student.getAge() + ", 学校：" + student.getSchool());
    }
}
