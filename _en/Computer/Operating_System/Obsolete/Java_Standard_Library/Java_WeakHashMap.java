/* Java_WeakHashMap.java
Author: BSS9395
Update: 2023-01-28T22:05:00:+08@China-Shanghai+08
Design: Java Standard Library: WeakHashMap
*/

import java.util.WeakHashMap;

public class Java_WeakHashMap {
    static public void main(String[] args) {
        _WeakHashMap();
    }
    static public void _WeakHashMap() {
        WeakHashMap<String, String> map = new WeakHashMap<String, String>();
        map.put(new String("1156"), new String("BSS9395"));
        map.put(new String("1157"), new String("Maker"));
        map.put(new String("1158"), new String("Brilliant"));
        map.put("1159", new String("Emperor"));
        System.out.println(map);

        System.gc();
        System.runFinalization();
        System.out.println(map);
    }
}
