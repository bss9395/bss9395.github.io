/* Java_Loop_Label.java
Author: BSS9395
Update: 2021-10-07T20:57:00+08@China-Guangdong-Shenzhen+08
Design: Java Language Feature: Loop Label
*/

public class Java_Loop_Label {
    public static void main(String[] args) {
        Break:
        for (int i = 0; i < 3; i += 1) {
            for (int j = 0; j < 2; j += 1) {
                if (i == 1) {
                    break Break;
                }
                System.out.printf("[i, j] = [%d, %d] %n", i, j);
            }
        }

        ////////////////////////////////
        System.out.println("========================================");
        Continue:
        for (int i = 0; i < 3; i += 1) {
            for (int j = 0; j < 2; j += 1) {
                if (i == 1) {
                    continue Continue;
                }
                System.out.printf("[i, j] = [%d, %d] %n", i, j);
            }
        }
    }
}
