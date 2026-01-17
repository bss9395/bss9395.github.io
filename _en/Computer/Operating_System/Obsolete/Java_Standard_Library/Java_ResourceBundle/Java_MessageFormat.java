/* Java_MessageFormat.java
Author: BSS9395
Update: 2023-01-14T23:00:00+08@China-Shanghai+08
Design: Java Standard Library: MessageFormat
*/

import java.text.MessageFormat;
import java.util.Date;
import java.util.ListResourceBundle;
import java.util.Locale;
import java.util.ResourceBundle;

public class Java_MessageFormat {

    static public void main(String[] args) {
        _getBundle(args);
        // _ListResourceBundle();
    }
    static public void _getBundle(String[] args) {
        Locale locale = (args.length == 2) ? new Locale(args[0], args[1]) : Locale.getDefault(Locale.Category.FORMAT);
        System.out.println(locale);
        ResourceBundle bundle = ResourceBundle.getBundle("format", locale);

        System.out.println(MessageFormat.format(bundle.getString("greeting"), "World", new Date()));
        System.out.println(MessageFormat.format("Hello {0}, today is {1}.", "World", new Date()));
    }
    static public void _ListResourceBundle() {
        ListResourceBundle bundle = new format_zh_CN();
        System.out.println(MessageFormat.format(bundle.getString("greeting"), "World", new Date()));
        System.out.println(MessageFormat.format("Hello {0}, today is {1}.", "World", new Date()));
    }
}
