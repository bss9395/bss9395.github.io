/* Java_super.java
Author: bss9395
Update: 2025-07-24T11:41:00+08@China-GuangDong-ZhanJiang+08
*/

class Animal {
    public String genre = "哺乳动物";

    public Animal() {
        super();
    }
}

class Person extends Animal {
    public String name = "林大强";
    public int age = 34;

    public Person(String name, int age) {
        super();
        this.name = name;
        this.age = age;
    }

    @Override
    public String toString() {
        return "genre: " + genre + ", name: " + name + ", age: " + age;
    }
}

class Student extends Person {
    public double score = 0.0;
    public Student(String name, int age) {
        super(name, age);

    }

    @Override
    public String toString() {
        // return super.super.toString();  // super.super访问错误
        return super.toString() + ", score: " + score;
    }
}

public class Java_super {
    static public void main(String[] args) {
        System.out.println(new Student("林小强", 38));
    }
}
