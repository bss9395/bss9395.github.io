/* Maker.java
Author: BSS9395
Update: 2023-05-26T15:30:00+08@China-Guangdong-Zhanjiang+08
Design: Design Pattern: Maker
*/

class Person {
    public String _head = "";
    public String _body = "";
    public String _foot = "";
}

class Man extends Person {

}

abstract class AMake_Person {
    public Person _person = null;
    abstract public AMake_Person _Make_Head();
    abstract public AMake_Person _Make_Body();
    abstract public AMake_Person _Make_Foot();
 }

class Make_Man extends AMake_Person {
    public Make_Man() {
        this._person = new Man();
    }
    @Override
    public Make_Man _Make_Head() {
        this._person._head = "男人的头";
        return this;
    }
    @Override
    public Make_Man _Make_Body() {
        this._person._body = "男人的身体";
        return this;
    }
    @Override
    public Make_Man _Make_Foot() {
        this._person._foot = "男人的脚";
        return this;
    }
}

public class Maker {
    static public Person _Maker(AMake_Person make) {
        return make._Make_Head()._Make_Body()._Make_Foot()._person;
    }

    public static void main(String[] args) {
        Person person = Maker._Maker(new Make_Man());
        System.out.println(person._head);
        System.out.println(person._body);
        System.out.println(person._foot);
    }
}
