/* Java_IdentityHashMap.java
Author: BSS9395
Update: 2023-01-28T22:19:00+08@China-Shanghai+08
Design: Java Standard Library: IdentityHashMap
*/

import java.util.IdentityHashMap;

public class Java_IdentityHashMap {
    static public void main(String[] args) {
        _IdentityHashMap();
    }
    static public void _IdentityHashMap() {
        IdentityHashMap<String, String> map = new IdentityHashMap<String, String>();
        map.put(new String("1156"), new String("BSS9395"));
        map.put(new String("1157"), new String("Maker"));
        map.put(new String("1158"), new String("Brilliant"));
        map.put("1159", new String("Emperor"));
        map.put("1159", new String("Dummy"));
        map.put(new String("1159"), new String("Another"));
        System.out.println(map);
    }
}
