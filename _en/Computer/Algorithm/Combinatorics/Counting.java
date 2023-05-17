/* Counting.java
Author: BSS9395
Update: 2023-05-16T16:07:00+08@China-Guangdong-Zhanjiang+08
Design: Counting
*/

public class Counting {
    static public void _Permutation_Once_Brute() {
        char[]   indexes = "012".toCharArray();
        String[] prev    = new String[] {
            ""
        };
        for (int length = indexes.length; 1 <= length; length -= 1) {
            String[] curr = new String[prev.length * length];
            int counter = 0;
            for (int idx = 0; idx < prev.length; idx += 1) {
                for (int i = 0; i < indexes.length; i += 1) {
                    if(false == prev[idx].contains("" + indexes[i])) {
                        curr[counter] = prev[idx] + indexes[i];
                        counter += 1;
                    }
                }
            }
            prev = curr;
        }
        System.out.println(java.util.Arrays.toString(prev));
    }

    public static void main(String[] args) {
        _Permutation_Once_Brute();
    }
}