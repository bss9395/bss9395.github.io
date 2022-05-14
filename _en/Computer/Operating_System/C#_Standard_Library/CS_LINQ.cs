/* CS_LINQ.cs
Author: BSS9395
Update: 2022-05-13T14:44:00+08@China-Shanghai+08
Design: C# Language Feature: LINQ
*/
class CS_LINQ {
    public static void Main(String[] args) {
        _LINQ_Method();
        // _LINQ();
        // _LINQ_from();
        // _LINQ_join();
        // _LINQ_let();
        // _LINQ_where();
        // _LINQ_orderby();
        // _LINQ_select();
        // _LINQ_group();
        // _LINQ_into();
    }
    ////////////////////////////////////////////////////////////////////////////
    public static void _LINQ_Method() {
        int[] numbers = {
            2, 5, 28, 31, 17, 16, 42
        };

        var method = numbers.Where(num => num < 10);

        foreach (int num in method) {
            Console.WriteLine($"{num} ");
        }
    }
    ////////////////////////////////////////////////////////////////////////////
    public static void _LINQ() {
        int[] numbers = {
            2, 5, 28, 31, 17, 16, 42
        };

        int count = (
            from num in numbers
            where num < 10
            select num
        ).Count();

        Console.WriteLine($"count = {count}");
    }
    ////////////////////////////////////////////////////////////////////////////
    public static void _LINQ_from() {
        int[] numbers0 = {
            3, 4, 5, 6
        };
        int[] numbers1 = {
            6, 7, 8, 9
        };

        var query =
            from number0 in numbers0
            from number1 in numbers1
            where 4 <= number0 && number1 < 8
            select new { number0, number1, sum = number0 + number1 };

        foreach (var number in query) {
            Console.WriteLine($"{number} ");
        }
    }
    ////////////////////////////////////////////////////////////////////////////
    class Student {
        public int _student_id = 0;
        public string _student_name = "";
    }
    class Course_Student {
        public int _student_id = 0;
        public string _course_name = "";
    }
    public static void _LINQ_join() {
        Student[] students = new Student[] {
            new Student{_student_id = 1, _student_name = "Carson"},
            new Student{_student_id = 2, _student_name = "Klassen"},
            new Student{_student_id = 3, _student_name = "Fleming"},
        };
        Course_Student[] course_students = new Course_Student[] {
            new Course_Student{_student_id = 1, _course_name = "Art"},
            new Course_Student{_student_id = 2, _course_name = "Art"},
            new Course_Student{_student_id = 1, _course_name = "History"},
            new Course_Student{_student_id = 3, _course_name = "History"},
            new Course_Student{_student_id = 3, _course_name = "Physics"},
        };

        var query =
            from student in students
            join course in course_students
            on student._student_id equals course._student_id
            where course._course_name == "History"
            select student._student_name;

        foreach (var student in query) {
            Console.WriteLine($"Student taking History: {student}");
        }
    }
    ////////////////////////////////////////////////////////////////////////////
    public static void _LINQ_let() {
        var numbers0 = new[] { 3, 4, 5, 6 };
        var numbers1 = new[] { 6, 7, 8, 9 };

        var query =
            from number0 in numbers0
            from number1 in numbers1
            let sum = number0 + number1
            where sum == 12
            select new { number0, number1, sum };

        foreach (var number in query) {
            Console.WriteLine($"{number}");
        }
    }
    ////////////////////////////////////////////////////////////////////////////
    public static void _LINQ_where() {
        var numbers0 = new[] { 3, 4, 5, 6 };
        var numbers1 = new[] { 6, 7, 8, 9 };

        var query =
            from number0 in numbers0
            from number1 in numbers1
            let sum = number0 + number1
            where 11 <= sum
            where number0 == 4
            select new { number0, number1, sum };

        foreach (var number in query) {
            Console.WriteLine($"{number}");
        }
    }
    ////////////////////////////////////////////////////////////////////////////
    public static void _LINQ_orderby() {
        var students = new[] {
            new { _name = "Mary Jones", _age = 19, _major = "History" },
            new { _name = "Carol Fleming", _age = 21, _major = "History" },
            new { _name = "Bob Smith", _age = 20, _major = "CompSci" },
        };

        var query =
            from student in students
            orderby student._age
            select student;

        foreach (var student in query) {
            Console.WriteLine($"{student}");
        }
    }
    ////////////////////////////////////////////////////////////////////////////
    public static void _LINQ_select() {
        var students = new[] {
            new { _name = "Mary Jones", _age = 19, _major = "History" },
            new { _name = "Carol Fleming", _age = 21, _major = "History" },
            new { _name = "Bob Smith", _age = 20, _major = "CompSci" },
        };

        var query =
            from student in students
            select student._name;

        foreach (var student in query) {
            Console.WriteLine($"{student}");
        }
    }
    ////////////////////////////////////////////////////////////////////////////
    public static void _LINQ_group() {
        var students = new[] {
            new { _name = "Mary Jones", _age = 19, _major = "History" },
            new { _name = "Bob Smith", _age = 20, _major = "CompSci" },
            new { _name = "Carol Fleming", _age = 21, _major = "History" }
        };

        var query =
            from student in students
            group student by student._major;

        foreach (var group in query) {
            Console.WriteLine($"{group.Key}");

            foreach (var student in group) {
                Console.WriteLine($"{student}");
            }
        }
    }
    ////////////////////////////////////////////////////////////////////////////
    public static void _LINQ_into() {
        var numbers0 = new[] { 3, 4, 5, 6 };
        var numbers1 = new[] { 4, 5, 6, 7 };

        var query =
            from number0 in numbers0
            join number1 in numbers1
            on number0 equals number1
            into numbers
            from number in numbers
            select number;

        foreach (var number in query) {
            Console.WriteLine($"{number}");
        }
    }
}
