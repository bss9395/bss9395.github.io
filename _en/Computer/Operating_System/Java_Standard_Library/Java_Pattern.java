/* Java_Pattern.java
Author: bss9395
Update: 2025-08-05T08:05:00+08@China-GuangDong-ZhanJiang+08
*/

import java.util.Arrays;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Java_Pattern {
    public static void main(String[] args) {
        // _Pattern_matches();
        // _Pattern_find();
        // _Pattern_replaceAll();
        _Pattern_replaceFirst();
        // _Pattern_split();
        // _String_matches();
        // _String_split();
    }
    public static void _Pattern_matches() {
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
    public static void _Pattern_find() {
        String regex = "[0-9]{1,}";
        String input = "abc123def456";
        Pattern pattern = Pattern.compile(regex);
        Matcher matcher = pattern.matcher(input);
        while (matcher.find()) {
            System.out.printf("找到匹配的子串: [%2d,%2d]%s%n", matcher.start(), matcher.end(), matcher.group(0));
        }
    }
    public static void _Pattern_replaceAll() {
        String regex = "[0-9]{1,}";
        String input = "abc123def456";
        String replacement = "X";
        Pattern pattern = Pattern.compile(regex);
        Matcher matcher = pattern.matcher(input);
        String result = matcher.replaceAll(replacement);
        System.out.println("替换后的字符串: " + result);
    }
    public static void _Pattern_replaceFirst() {
        String[] contents = new String[] {
                "Java has regular expressions in 1.4.",
                "regular expressions now expressing in Java.",
                "Java represses oracular expressions."
        };
        Pattern pattern = Pattern.compile("ex[A-Za-z_\\-]{0,}");
        for(int i = 0; i < contents.length; i += 1) {
            Matcher matcher = pattern.matcher(contents[i]);
            System.out.println(matcher.replaceFirst("PHD"));
        }
    }
    public static void _Pattern_split() {
        String str = "JKL()UI$()QR@#JKLSD()QW#EIO$RJKL";
        String regex = "[^a-zA-Z]{1,}";
        Pattern pattern = Pattern.compile(regex);
        String[] result = pattern.split(str);
        System.out.println(Arrays.toString(result));
    }
    public static void _String_matches() {
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
    public static void _String_split() {
        String regex = ",";
        String input = "abc,def,ghi";
        String[] parts = input.split(regex);
        System.out.println("分割后的结果: " + Arrays.toString(parts));
    }
}
