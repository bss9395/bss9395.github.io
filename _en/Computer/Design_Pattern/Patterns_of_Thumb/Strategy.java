/* Strategy.java
Author: BSS9395
Update: 2023-05-27T15:17:00+08@China-Guangdong-Zhanjiang+08
Design: Design Pattern: Strategy
*/

abstract class AStrategy {
    abstract public void _Method();
}

class Strategy_A extends AStrategy {
    @Override
    public void _Method() {
        System.out.println("这是第一个实现");
    }
}

class Strategy_B extends AStrategy {
    @Override
    public void _Method() {
        System.out.println("这是第二个实现");
    }
}

class Strategy_C extends AStrategy {
    @Override
    public void _Method() {
        System.out.println("这是第三个实现");
    }
}

class Context {
    AStrategy _strategy = null;
    public void _Set_Strategy(AStrategy strategy) {
        _strategy = strategy;
    }

    public void _Do() {
        _strategy._Method();
    }
}

public class Strategy {
    public static void main(String[] args) {
        Strategy_A strategy_a = new Strategy_A();
        Strategy_B strategy_b = new Strategy_B();
        Strategy_C strategy_c = new Strategy_C();
        Context context = new Context();

        context._Set_Strategy(strategy_a);
        context._Do();

        context._Set_Strategy(strategy_b);
        context._Do();

        context._Set_Strategy(strategy_c);
        context._Do();
    }
}