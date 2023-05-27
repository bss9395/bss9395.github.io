/* Mediator.java
Author: BSS9395
Update: 2023-05-26T23:52:00+08@China-Guangdong-Zhanjiang+08
Design: Design Pattern: Mediator
*/

abstract class AColleague {
    abstract public void _Action();
}

class Receptionist extends AColleague {
    @Override
    public void _Action() {
        System.out.println("前台注意了！");
    }
}

class Colleague extends AColleague {
    @Override
    public void _Action() {
        System.out.println("普通员工努力工作。");
    }
}

abstract class AMediator {
    abstract public void _Notice(String content);
}

public class Mediator extends AMediator {
    public Receptionist _receptionist = new Receptionist();
    public Colleague    _colleague    = new Colleague();

    public void _Notice(String colleague) {
        if (colleague.equals("receptionist")) {
            _receptionist._Action();
        }
        else if (colleague.equals("colleague")) {
            _colleague._Action();
        }
    }

    public static void main(String[] args) {
        AMediator mediator = new Mediator();
        mediator._Notice("receptionist");
        mediator._Notice("colleague");
    }
}
