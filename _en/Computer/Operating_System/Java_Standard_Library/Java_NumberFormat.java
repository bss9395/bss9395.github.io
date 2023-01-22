/* Java_NumberFormat.java
Author: BSS9395
Update: 2023-01-15T18:27:00+08@China-Shanghai+08
Design: Java Standard Library: NumberFormat
*/

import java.text.NumberFormat;
import java.util.*;

public class Java_NumberFormat {
    static public void main(String[] args) {
        _NumberFormat();
    }
    static public void _NumberFormat() {
        Locale[] locales = {
            Locale.CHINA, Locale.JAPAN, Locale.GERMAN, Locale.US
        };
        String[] names = {
            "----中国格式----", "----日本格式----", "----德国格式----", "----美国格式----"
        };

        NumberFormat[][] formats = new NumberFormat[locales.length][3];
        for(int i = 0; i < formats.length; i += 1) {
            formats[i][0] = NumberFormat.getNumberInstance(locales[i]);
            formats[i][1] = NumberFormat.getCurrencyInstance(locales[i]);
            formats[i][2] = NumberFormat.getPercentInstance(locales[i]);
        }

        double number = 654.321;
        for(int i = 0; i < formats.length; i += 1) {
            System.out.println(names[i]);
            System.out.println(formats[i][0].format(number));
            System.out.println(formats[i][1].format(number));
            System.out.println(formats[i][2].format(number));
        }
    }
}
