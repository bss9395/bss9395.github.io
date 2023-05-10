/* Java_default.java
Author: BSS9395
Update: 2023-05-02T17:17:00+08@China-Guangdong-Zhanjiang+08
Design: Java Keyword: default
*/

public class Java_default {
    interface IFace {
        default void _IDefault() {
            _IPrivate();
        }

        private void _IPrivate() {
            System.out.println("private void _IPrivate();");
        }
    }

    static class CFace implements IFace {
        public void _Print() {
            _IDefault();
        }
    }

    static public void main(String[] args) {
        CFace face = new CFace();
        face._Print();
    }
}
