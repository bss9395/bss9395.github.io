/* Taker.java
Author: BSS9395
Update: 2023-05-27T13:49:00+08@China-Guangdong-Zhanjiang+08
Design: Design Pattern: Taker
*/

class Memo {
    public String _state = null;
    public Memo(String state) {
        _state = state;
    }
}

class Maker {
    public Memo _memo = null;
    public void _Set_Memo(Memo memo) {
        _memo = memo;
    }
    public Memo _Get_Memo() {
        return _memo;
    }

    public void _Show_State(){
        System.out.println(_memo._state);
    }
}

class Taker {
    public Memo _memo = null;
    public void _Set_Memo(Memo memo) {
        _memo = memo;
    }
    public Memo _Get_Memo() {
        return _memo;
    }
    public void _Show_State(){
        System.out.println(_memo._state);
    }

    public static void main(String[] args) {
        Maker maker = new Maker();
        maker._Set_Memo(new Memo("开会中"));

        Taker taker = new Taker();
        taker._Set_Memo(maker._Get_Memo());

        maker._Set_Memo(new Memo("睡觉中"));
        maker._Show_State();

        maker._Set_Memo(taker._Get_Memo());
        maker._Show_State();
    }
}
