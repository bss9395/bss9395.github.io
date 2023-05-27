/* Bridge.java
Author: BSS9395
Update: 2023-05-26T16:28:00+08@China-Guangdong-Zhanjiang+08
Design: Design Pattern: Bridge
*/

abstract class AClothing {
    public String _clothing = null;
}

class Jacket extends AClothing {
    public Jacket() {
        this._clothing = "马甲";
    }
}

class Trouser extends AClothing {
    public Trouser() {
        this._clothing = "裤子";
    }
}

abstract class APerson {
    public String _type = null;
    abstract public void _Dress_Up(AClothing clothing);
}

class Man extends APerson {
    public Man() {
        this._type = "男人";
    }

    public void _Dress_Up(AClothing clothing) {
        System.out.printf("%s穿%s%n", this._type, clothing._clothing);
    }
}

class Lady extends APerson {
    public Lady() {
        this._type = "女人";
    }

    public void _Dress_Up(AClothing clothing) {
        System.out.printf("%s穿%s%n", this._type, clothing._clothing);
    }
}

public class Bridge {
    public static void main(String[] args) {
        APerson   man     = new Man();
        APerson   lady    = new Lady();
        AClothing jacket  = new Jacket();
        AClothing trouser = new Trouser();
        man._Dress_Up(jacket);
        lady._Dress_Up(trouser);
    }
}
