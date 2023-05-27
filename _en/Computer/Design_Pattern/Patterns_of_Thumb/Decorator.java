/* Decorator.java
Author: BSS9395
Update: 2023-05-27T15:17:00+08@China-Guangdong-Zhanjiang+08
Design: Design Pattern: Decorator
*/

abstract class APerson {
    abstract public void _Eat();
}

class Man extends APerson {
    @Override
    public void _Eat() {
        System.out.println("男人在吃东西！");
    }
}

abstract class ADecorator extends APerson {
    public APerson _person = null;
    abstract public void _Set_Person(APerson person);
    abstract public void _ReEat();
}

class Decorator_Man extends ADecorator {
    public void _Set_Person(APerson person) {
        this._person = person;
    }
    @Override
    public void _Eat() {
        System.out.println("Decorator_Man");
        this._person._Eat();
        _ReEat();

    }
    @Override
    public void _ReEat() {
        System.out.println("再吃一顿饭");
    }
}

class Decorator_Decorator extends ADecorator {
    public void _Set_Person(APerson person) {
        this._person = person;
    }
    @Override
    public void _Eat() {
        System.out.println("Decorator_Decorator");
        this._person._Eat();
    }
    @Override
    public void _ReEat() {

    }
}

public class Decorator {
    public static void main(String[] args) {
        Man                 man                 = new Man();
        Decorator_Man       decorator_man       = new Decorator_Man();
        Decorator_Decorator decorator_decorator = new Decorator_Decorator();

        decorator_man._Set_Person(man);
        decorator_decorator._Set_Person(decorator_man);
        decorator_decorator._Eat();
    }
}
