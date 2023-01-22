/* format_zh_CN.java
Author: BSS9395
Update: 2023-01-15T18:25:00+08@China-Shanghai+08
Design: Java Resource Bundle
*/

import java.util.ListResourceBundle;

public class format_zh_CN extends ListResourceBundle {
    private final Object format[][] = {
            {
                    "greeting", "format_zh_CN, Hello {0}, today is {1}."
            }
    };
    @Override
    public Object[][] getContents() {
        return format;
    }
}