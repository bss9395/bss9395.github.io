import java.util.Arrays;
import java.util.Comparator;

class Person implements Comparable<Person> {
    private String _name;
    private int _age;
    public Person(String name, int age) {
        super();
        _name = name;
        _age = age;
    }
    public int getAge() {
        return _age;
    }

    @Override
    public String toString() {
        return "[Person] 姓名：" + _name + "，年龄：" + _age;
    }

    @Override
    public int compareTo(Person person) {
        return _age - person._age;
    }
}

class PersonComparator implements Comparator<Person> {
    @Override
    public int compare(Person lhs, Person rhs) {
        return lhs.getAge() - rhs.getAge();
    }
}

public class Java_sort {
    public static void main(String[] args) {
        // _Test_sort_Integer();
        // _Test_sort_String();
        // _Test_sort_Comparable();
        // _Test_Sort_Comparator();
        _Test_Sort_Lambda();
    }

    static public void _Test_sort_Integer() {
        Integer data[] = new Integer[] {
                10, 9, 5, 2, 20
        };
        Arrays.sort(data);
        System.out.println(Arrays.toString(data));
    }
    static public void _Test_sort_String() {
        String data[] = new String[] {
            "X", "B", "A", "E", "G"
        };
        Arrays.sort(data);
        System.out.println(Arrays.toString(data));
    }
    static public void _Test_sort_Comparable() {
        Person[] person = new Person[] {
            new Person("小强-A", 80),
            new Person("小强-B", 50),
            new Person("小强-C", 100)
        };
        Arrays.sort(person);
        System.out.println(Arrays.toString(person));
    }
    static public void _Test_Sort_Comparator() {
        Person[] person = new Person[] {
                new Person("小强-A", 80),
                new Person("小强-B", 50),
                new Person("小强-C", 100)
        };
        Arrays.sort(person, new PersonComparator());
        System.out.println(Arrays.toString(person));
    }
    static public void _Test_Sort_Lambda() {
        Person[] person = new Person[] {
                new Person("小强-A", 80),
                new Person("小强-B", 50),
                new Person("小强-C", 100)
        };
        Arrays.sort(person, new Comparator<Person>() {
            @Override
            public int compare(Person lhs, Person rhs) {
                return lhs.getAge() - rhs.getAge();
            }
        });
        System.out.println(Arrays.toString(person));
    }
}
