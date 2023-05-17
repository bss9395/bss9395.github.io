/* Java_super.java
Author: BSS9395
Update: 2023-05-16T16:37:00+08@China-Guangdong-Zhanjiang+08
Design: Java Keyword: super
*/

import java.util.Date;

public class Java_super extends Date {
    public void _Super() {
        System.out.println(super.getClass().getName());                  // note: super is like this.
        System.out.println(super.getClass().getSuperclass().getName());
    }

    static public void main(String[] args) {
        new Java_super()._Super();
    }
}
