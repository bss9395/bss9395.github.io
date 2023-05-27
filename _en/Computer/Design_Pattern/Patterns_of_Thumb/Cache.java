/* Cache.java
Author: BSS9395
Update: 2023-05-26T21:56:00+08@China-Guangdong-Zhanjiang+08
Design: Design Pattern: Cache
*/

import java.util.HashMap;
import java.util.Map;

abstract class AShared {
    abstract public void _Action(String arg);
}

class Shared extends AShared {
    @Override
    public void _Action(String arg) {
        System.out.printf("arg=%s%n", arg);
    }
}

public class Cache {
    static public Map<String, AShared> _shared = new HashMap<String, AShared>();

    static public AShared _Get_Shared(String key) {
        if (_shared.get(key) == null) {
            AShared share = new Shared();
            _shared.put(key, share);
            return share;
        }
        return _shared.get(key);
    }

    static public int _Get_Size() {
        return _shared.size();
    }

    static public void main(String[] args) {
        AShared share_0 = Cache._Get_Shared("abc");
        share_0._Action("ABC");

        AShared share_1 = Cache._Get_Shared("abc");
        System.out.println(share_0 == share_1 ? "share_0 == share_1" : "share_0 != share_1");

        AShared share_2 = Cache._Get_Shared("def");
        share_2._Action("DEF");

        AShared share_3 = Cache._Get_Shared("ghi");
        share_3._Action("GHI");

        AShared share_4 = Cache._Get_Shared("jkl");
        share_4._Action("JKL");

        System.out.printf("Factory._Get_Size()=%s%n", Cache._Get_Size());
    }
}
