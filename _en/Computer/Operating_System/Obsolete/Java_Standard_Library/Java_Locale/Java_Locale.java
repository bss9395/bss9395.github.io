/* Java_Locale.java
Author: BSS9395
Update: 2023-01-14T19:20:00+08@China-Shanghai+08
Design: Java Standard Library: Locale
*/

import java.text.MessageFormat;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Locale;
import java.util.ResourceBundle;

public class Java_Locale {
    static public void main(String[] args) {
        // _Locale();
        // _ResourceBundle();
        _MessageFormat();
    }
    static public void _Locale() {
        Locale[] list = Locale.getAvailableLocales();
        for (Locale locale : list) {
            System.out.println(
                    locale.getDisplayCountry()  + ": " + locale.getCountry() + ", " +
                    locale.getDisplayLanguage() + ": " + locale.getLanguage()
            );
        }

        System.out.println("--------------------------------------------------------------------------------");
        Locale locale_CHINA   = Locale.CHINA;
        Locale locale_CHINESE = Locale.CHINESE;
        Locale locale_SIMPLIFIED_CHINESE = Locale.SIMPLIFIED_CHINESE;
        System.out.println(locale_CHINA);
        System.out.println(locale_CHINESE);
        System.out.println(locale_SIMPLIFIED_CHINESE);
    }
    static public void _ResourceBundle() {
        Locale locale = locale = Locale.getDefault();
        // locale = Locale.getDefault(Locale.Category.DISPLAY);
        // locale = Locale.getDefault(Locale.Category.FORMAT);
        System.out.println(locale);
        ResourceBundle bundle = ResourceBundle.getBundle("lang", locale);
        System.out.println(bundle.getString("hello"));
    }
    static public void _MessageFormat() {
        Locale locale = new Locale("en", "US");
        ResourceBundle resource = ResourceBundle.getBundle("lang", locale);
        String info = resource.getString("info");
        System.out.println(info);
        System.out.println(MessageFormat.format(info, "mldn", new SimpleDateFormat("yyyy-MM-dd").format(new Date())));
    }
}
