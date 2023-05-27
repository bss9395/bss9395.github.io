/* Factory_Abstract.java
Author: BSS9395
Update: 2023-05-26T15:07:00+08@China-Guangdong-Zhanjiang+08
Design: Design Pattern: Abstract Factory
*/

abstract class ACat {
    abstract public void _Eat();
}

class Cat_Black extends ACat {
    @Override
    public void _Eat() {
        System.out.println("The black cat is eating!");
    }
}

class Cat_White extends ACat {
    @Override
    public void _Eat() {
        System.out.println("The white cat is eating!");
    }
}

abstract class ADog {
    abstract public void _Eat();
}

class Dog_Black extends ADog {
    @Override
    public void _Eat() {
        System.out.println("The black dog is eating!");
    }
}

class Dog_White extends ADog {
    @Override
    public void _Eat() {
        System.out.println("The white dog is eating!");
    }
}

abstract class AFactory {
    static public String _cat_black = "cat_black";
    static public String _cat_white = "cat_white";
    static public String _dog_black = "dog_black";
    static public String _dog_white = "dog_white";
    abstract public ACat _Make_Cat(String instance);
    abstract public ADog _Make_Dog(String instance);
}

public class Factory_Abstract extends AFactory {
    @Override
    public ACat _Make_Cat(String instance) {
        return new Cat_Black();
    }
    @Override
    public ADog _Make_Dog(String instance) {
        return new Dog_Black();
    }

    public static void main(String[] args) {
        AFactory factory = new Factory_Abstract();
        ACat cat_black = factory._Make_Cat(factory._cat_black);
        cat_black._Eat();

        ADog dog_white = factory._Make_Dog(factory._dog_white);
        dog_white._Eat();
    }
}
