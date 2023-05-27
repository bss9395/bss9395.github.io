/* Proxy.java
Author: BSS9395
Update: 2023-05-26T22:12:00+08@China-Guangdong-Zhanjiang+08
Design: Proxy
*/

abstract class AInter {
    abstract public void _Action();
}

class Inter extends AInter {
    @Override
    public void _Action() {
        System.out.println("========");
        System.out.println("这是被代理的类");
        System.out.println("========");
    }
}

class Proxy extends AInter {
    AInter _inter = null;
    public Proxy(AInter inter) {
        _inter = inter;
    }
    @Override
    public void _Action() {
        System.out.println("代理开始");
        _inter._Action();
        System.out.println("代理结束");
    }

    static public void main(String[] args) {
        AInter obj = new Proxy(new Inter());
        obj._Action();
    }
}
