/* Factory.java
Author: BSS9395
Update: 2023-05-26T14:37:00+08@China-Guangdong-Zhanjiang+08
Design: Design Pattern: Factory
*/

abstract class AWork {
    abstract public void _Work();
}

class Work_Student extends AWork {
    @Override
    public void _Work() {
        System.out.println("学生做作业!");
    }
}

class Work_Teacher extends AWork {
    @Override
    public void _Work() {
        System.out.println("老师审批作业!");
    }
}

public class Factory {
    static public String _student = "student";
    static public String _teacher = "teacher";
    static public AWork _Instance(String instance) {
        if(instance.equals(_student)) {
            return new Work_Student();
        } else if(instance.equals(_teacher)) {
            return new Work_Teacher();
        }
        return null;
    }

    static public void main(String[] args) {
        AWork work_student = Factory._Instance(Factory._student);
        work_student._Work();

        AWork work_teacher = Factory._Instance(Factory._teacher);
        work_teacher._Work();
    }
}
