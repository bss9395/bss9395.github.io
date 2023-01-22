/* Java_Locale.java
Author: BSS9395
Update: 2023-01-14T19:20:00+08@China-Shanghai+08
Design: Java Standard Library: Locale
*/

import java.util.Locale;
import java.util.ResourceBundle;

public class Java_Locale {
    static public void main(String[] args) {
        // _Locale();
        _ResourceBundle();
    }
    static public void _Locale() {
        Locale[] list = Locale.getAvailableLocales();
        for (Locale locale : list) {
            System.out.println(
                    locale.getDisplayCountry()  + ": " + locale.getCountry() + ", " +
                    locale.getDisplayLanguage() + ": " + locale.getLanguage()
            );

        }
    }
    static public void _ResourceBundle() {
        Locale locale = Locale.getDefault(Locale.Category.FORMAT);
        System.out.println(locale);
        ResourceBundle bundle = ResourceBundle.getBundle("lang", locale);
        System.out.println(bundle.getString("hello"));
    }
}
