/* Java_Pattern.java
Author: BSS9395
Update: 2023-04-28T17:29:00+08@China-Guangdong-Zhanjiang+08
Design: Java Standard Library: Pattern
*/

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Java_Pattern {
    static public void main(String[] args) {
        // _find();
        // _matches();
        // _lookingAt();
        // _String();
        // _replaceAll();
        // _replaceFirst();

    }
    static public void _find() {
        String text = "当前时间是2023-04-28T16:25:00.001002003+08@China-Guangdong-Zhanjiang+08，" +
                      "一年后时间是2024-04-28T16:25:00.001002003+08@China-Guangdong-Zhanjiang+08";
        Pattern pattern = Pattern.compile("[0-9]{4}-[0-9]{2}-[0-9]{2}T[0-9]{2}:[0-9]{2}:[0-9]{2}(\\.([0-9]{3}){1,3}){0,}(\\+|-)[0-9]{2}" +
                                          "@[A-Za-z]{1,}(-[A-Za-z]{1,}){0,}(\\+|-)[0-9]{2}");
        Matcher matcher = pattern.matcher(text);
        while(matcher.find() == true) {
            System.out.printf("[%s, %s]%s%n", matcher.start(), matcher.end(), matcher.group());
        }
    }
    static public void _matches() {
        String[] mails = new String[] {
            "bss9395@163.com",
            "maker@gmail.com",
            "brilliant@github.com",
            "emperor@apache.xx"
        };
        Pattern pattern = Pattern.compile("[A-Za-z0-9_]{1,}@[A-Za-z0-9_]{1,}\\.(com|org|cn|net|gov)");
        for(int i = 0; i < mails.length; i += 1) {
            Matcher matcher = pattern.matcher(mails[i]);
            System.out.printf("[%s]%s%n", matcher.matches() == true ? "true " : "false", mails[i]);
        }
    }
    static public void _lookingAt() {
        String[] mails = new String[] {
                "bss9395@163.com",
                "maker@gmail.com",
                "brilliant@github.com",
                "emperor@apache.com.xx"
        };
        Pattern pattern = Pattern.compile("[A-Za-z0-9_]{1,}@[A-Za-z0-9_]{1,}\\.(com|org|cn|net|gov)");
        for(int i = 0; i < mails.length; i += 1) {
            Matcher matcher = pattern.matcher(mails[i]);
            System.out.printf("[%s]%s%n", matcher.lookingAt() == true ? "true " : "false", mails[i]);
        }
    }
    static public void _String() {
        String[] mails = new String[] {
                "bss9395@163.com",
                "maker@gmail.com",
                "brilliant@github.com",
                "emperor@apache.xx"
        };
        for(int i = 0; i < mails.length; i += 1) {
            boolean result = mails[i].matches("[A-Za-z0-9_]{1,}@[A-Za-z0-9_]{1,}\\.(com|org|cn|net|gov)");
            System.out.printf("[%s]%s%n", result == true ? "true " : "false", mails[i]);
        }
    }
    static public void _replaceAll() {
        String[] contents = new String[] {
            "Java has regular expressions in 1.4.",
            "regular expressions now expressing in Java.",
            "Java represses oracular expressions."
        };
        Pattern pattern = Pattern.compile("re[A-Za-z_\\-]{0,}");
        for(int i = 0; i < contents.length; i += 1) {
            Matcher matcher = pattern.matcher(contents[i]);
            System.out.println(matcher.replaceAll("PHD"));
        }
    }
    static public void _replaceFirst() {
        String[] contents = new String[] {
                "Java has regular expressions in 1.4.",
                "regular expressions now expressing in Java.",
                "Java represses oracular expressions."
        };
        Pattern pattern = Pattern.compile("re[A-Za-z_\\-]{0,}");
        for(int i = 0; i < contents.length; i += 1) {
            Matcher matcher = pattern.matcher(contents[i]);
            System.out.println(matcher.replaceFirst("PHD"));
        }
    }

}
